#include "../include/so_long.h"

static int open_and_check_map(t_map *map, char *map_path, int *fd);

// YARDIMCI FONKSİYON: Haritadaki P, E, C sayılarını kontrol eder.
static int check_map_elements(t_map *map)
{
    if (map->player_count != 1)
    {
        error_handler("Error\nMap must contain exactly one player (P).");
        return (0);
    }
    if (map->exit_count != 1)
    {
        error_handler("Error\nMap must contain exactly one exit (E).");
        return (0);
    }
    if (map->collectibles < 1)
    {
        error_handler("Error\nMap must contain at least one collectible (C).");
        return (0);
    }
    return (1);
}

// Yardımcı fonksiyon: Dosyayı açar ve ilk kontrolleri yapar
static int open_and_check_map(t_map *map, char *map_path, int *fd)
{
    map->map = NULL; // ÖNEMLİ: NULL'a eşitle, free_map güvenli çalışsın.
    map->collectibles = 0;
    map->exit_count = 0;
    map->player_count = 0;
    map->width = 0;
    map->height = 0;
    map->path = map_path; // Haritanın yolunu kaydet

    *fd = open(map_path, O_RDONLY);
    if (*fd == -1)
    {
        error_handler("Error\nFile cannot be opened");
        return (0);
    }
    return (1);
}

static int perform_map_checks(t_map *map, int fd) {
    close(fd);

    if (!check_map_walls(map))
    {
        error_handler("Error\nMap is not surrounded by walls!");
        free_map(map);
        return (0);
    }

    if (!check_map_elements(map))
    {
        free_map(map);
        return (0);
    }

    // Yol kontrol  (check_valid_path)

    return (1);
}

int map_check(t_map *map, char *map_path)
{
    int fd; // Dosya tanımlayıcısı

    // Dosyayı aç ve temel kontrolleri yap
    if (!open_and_check_map(map, map_path, &fd))
        return (0);

    // Haritayı oku
    if (!read_map(fd, map))
    {
        close(fd); // Okuma başarısız olursa dosyayı kapat
        free_map(map); // Belleği temizle
        return (0); // Hata döndür
    }

     //Duvar,P,E,C kontrolleri.
    if(!perform_map_checks(map, fd))
        return(0);

    return (1); // Tüm kontroller başarılı
}

int check_valid_path(t_map *map)
{
    (void)map;
    return (1);
}