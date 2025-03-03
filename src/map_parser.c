#include "so_long.h"

// Harita dosyasını ayrıştırır ve harita yapısını oluşturur.
// Dosyayı açar, boyutları belirler, döşeme dizisi için bellek ayırır,
// satırları okur ve harita geçerliliğini kontrol eder.
t_map *parse_map(char *filename)
{
    t_map *map;
    int fd;
    int width;
    int height;

    // Harita yapısı için bellek ayır.
    map = malloc(sizeof(t_map));
    if (!map)
        return NULL; // Bellek ayırma hatası

    // Harita dosyasını salt okunur modda aç.
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Harita dosyası açma hatası\n");
        free(map);
        return (NULL);
    }

    // Harita boyutlarını belirle (satır sayısı ve satır uzunluğu).
    if (!get_map_dimensions(fd, &width, &height))
    {
        close(fd);
        free(map);
        return NULL; // Boyut belirleme hatası
    }

    // Döşeme dizisi için bellek ayır.
    map->tiles = malloc(sizeof(char *) * (height + 1));
    if (!map->tiles)
    {
        close(fd);
        free(map);
        return NULL; // Bellek ayırma hatası
    }

    // Dosyayı başa sar.
    lseek(fd, 0, SEEK_SET);

    // Harita satırlarını oku ve diziye yerleştir.
    if (!read_map_lines(fd, map, width, height))
    {
        close(fd);
        free_map(map);
        return NULL; // Satır okuma hatası
    }

    close(fd);
    // Harita genişliğini ve yüksekliğini ayarla
    map->width = width;
    map->height = height;
    return check_map_validity(map);
}

// Harita boyutlarını belirler (satır sayısı ve satır uzunluğu).
int get_map_dimensions(int fd, int *width, int *height)
{
    char *line;
    int w;
    int h;

    h = 0;
    w = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (w == 0)
            w = ft_strlen(line) - 1; // İlk satırın genişliğini al
        else if (w != (int)ft_strlen(line) - 1)
        {
            ft_printf("Hata: Harita dikdörtgen değil.\n");
            free(line);
            return 0; // Dikdörtgen kontrol hatası
        }
        free(line);
        h++;
    }
    *width = w;
    *height = h;
    return (1);
}

// Harita satırlarını okur ve döşeme dizisini doldurur.
int read_map_lines(int fd, t_map *map, int width, int height)
{
    char *line;
    int y;

    y = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        // Satırı döşeme dizisine kopyala ve son '\n' karakterini sil.
        map->tiles[y] = ft_strdup(line);
        if (!map->tiles[y])
        {
            free(line);
            return (0); // Bellek ayırma hatası
        }
        map->tiles[y][width] = '\0';
        // Satırı işle ve hata kontrolü yap.
        if (!process_map_line(map, map->tiles[y], y))
        {
            free(line);
            return (0); // Satır işleme hatası
        }
        free(line);
        y++;
    }
    map->tiles[height] = NULL; // Son satırı NULL ile işaretle
    return (1);
}

// Harita satırını işler ve harita yapısını günceller.
// Oyuncu, toplanabilir ve çıkış karakterlerini sayar ve konumlarını kaydeder.
int process_map_line(t_map *map, char *line, int y)
{
    int x;

    x = 0;
    // Satırdaki karakterleri işle.
    while (line[x])
    {
        // Oyuncu karakterini kontrol et.
        if (line[x] == PLAYER)
        {
            map->player_x = x;
            map->player_y = y;
            map->player_count++;
        }
        // Toplanabilir karakterini kontrol et.
        else if (line[x] == COLLECTIBLE)
            map->collectible_count++;
        // Çıkış karakterini kontrol et.
        else if (line[x] == EXIT)
            map->exit_count++;
        // Geçersiz karakter kontrolü.
        else if (line[x] != EMPTY && line[x] != WALL)
        {
            ft_printf("Hata: Geçersiz harita karakteri: %c\n", line[x]);
            return (0);
        }
        x++;
    }
    return (1);
}

// Harita geçerliliğini kontrol eder.
// Oyuncu, çıkış ve toplanabilir karakterlerinin sayılarını kontrol eder,
// harita genişliğini ve yüksekliğini ayarlar ve duvar kontrolü yapar.
t_map *check_map_validity(t_map *map)
{
    // Geçersiz P, E veya C sayısı kontrolü.
    if (map->player_count != 1 || map->exit_count != 1 || map->collectible_count == 0)
    {
        ft_printf("Hata: Geçersiz P, E veya C sayısı.\n");
        return (NULL);
    }
    // Duvar kontrolü yap.
    return (check_map_walls(map));
}

// Harita duvarlarını kontrol eder.
// Haritanın kenarlarının duvarlarla çevrili olup olmadığını kontrol eder.
t_map *check_map_walls(t_map *map)
{
    int i;

    i = 0;
    // Yatay duvar kontrolü.
    while (i < map->width)
    {
        if (map->tiles[0][i] != WALL || map->tiles[map->height - 1][i] != WALL)
        {
            ft_printf("Hata: Yatay duvar hatası.\n");
            return (NULL);
        }
        i++;
    }
    i = 0;
    // Dikey duvar kontrolü.
    while (i < map->height)
    {
        if (map->tiles[i][0] != WALL || map->tiles[i][map->width - 1] != WALL)
        {
            ft_printf("Hata: Dikey duvar hatası.\n");
            return (NULL);
        }
        i++;
    }
    return (map);
}