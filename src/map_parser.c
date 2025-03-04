#include "so_long.h"

// Satır sonundaki '\n' karakterini temizler.
void trim_newline(char *line)
{
    int len = ft_strlen(line);
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';
}

// Harita dosyasını ayrıştırır ve harita yapısını oluşturur.
t_map *parse_map(char *filename)
{
    t_map *map;
    int fd;
    int width, height;

    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    ft_bzero(map, sizeof(t_map));
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Harita dosyası açma hatası\n");
        free(map);
        return (NULL);
    }

    if (!get_map_dimensions(fd, &width, &height))
    {
        close(fd);
        free(map);
        return (NULL);
    }

    map->tiles = malloc(sizeof(char *) * (height + 1));
    if (!map->tiles)
    {
        close(fd);
        free(map);
        return (NULL);
    }

    lseek(fd, 0, SEEK_SET);

    if (!read_map_lines(fd, map, width, height))
    {
        close(fd);
        free_map(map);
        return (NULL);
    }

    close(fd);
    map->width = width;
    map->height = height;

    return check_map_validity(map);
}

// Harita boyutlarını belirler.
int get_map_dimensions(int fd, int *width, int *height)
{
    char *line;
    int w = 0;
    int h = 0;

    while ((line = get_next_line(fd)) != NULL)
    {
        trim_newline(line);  // Satır sonundaki '\n' temizleniyor.

        if (w == 0)
        {
            w = ft_strlen(line);
        }
        else if (w != (int)ft_strlen(line))
        {
            ft_printf("Hata: Harita dikdörtgen değil (satır: %d).\n", h + 1);
            free(line);
            return (0);
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
    int y = 0;

    while ((line = get_next_line(fd)) != NULL)
{
    trim_newline(line);

    if ((int)ft_strlen(line) != width)
    {
        ft_printf("Hata: Harita satır uzunluğu uyumsuz (satır: %d).\n", y + 1);
        free(line);  // Hafızayı serbest bırak
        return (0);
    }

    map->tiles[y] = ft_strdup(line);
    free(line);
    if (!map->tiles[y])
        return (0);

    if (!process_map_line(map, map->tiles[y], y))
    {
        free_map(map);  // Hata durumunda hafızayı temizle
        return (0);
    }

    y++;
}

    map->tiles[height] = NULL;
    return (1);
}

// Bir harita satırını analiz eder.
int process_map_line(t_map *map, char *line, int y)
{
    int x = 0;

    while (line[x])
    {
        if (line[x] == PLAYER)
        {
            map->player_x = x;
            map->player_y = y;
            map->player_count++;
        }
        else if (line[x] == COLLECTIBLE)
        {
            map->collectible_count++;
        }
        else if (line[x] == EXIT)
        {
            map->exit_count++;
        }
        else if (line[x] != EMPTY && line[x] != WALL)
        {
            ft_printf("Hata: Geçersiz karakter '%c' (x: %d, y: %d)\n", line[x], x, y);
            return (0);
        }
        x++;
    }
    return (1);
}

// Haritanın genel geçerliliğini kontrol eder.
t_map *check_map_validity(t_map *map)
{
    if (map->player_count != 1 || map->exit_count != 1 || map->collectible_count == 0)
    {
        ft_printf("Hata: P, E veya C sayısı geçersiz.\n");
        return (NULL);
    }
    return check_map_walls(map);
}

// Haritanın kenarlarının duvarlarla kaplı olup olmadığını kontrol eder.
t_map *check_map_walls(t_map *map)
{
    for (int i = 0; i < map->width; i++)
    {
        if (map->tiles[0][i] != WALL || map->tiles[map->height - 1][i] != WALL)
        {
            ft_printf("Hata: Üst veya alt duvar eksik.\n");
            return (NULL);
        }
    }

    for (int i = 0; i < map->height; i++)
    {
        if (map->tiles[i][0] != WALL || map->tiles[i][map->width - 1] != WALL)
        {
            ft_printf("Hata: Sol veya sağ duvar eksik.\n");
            return (NULL);
        }
    }

    return (map);
}
