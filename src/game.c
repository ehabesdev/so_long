#include "so_long.h"

// Harita yapısını başlatır.
// MLX yapısını, pencereyi, XPM resimlerini yükler ve hata kontrolü yapar.
int init_map(t_map *map)
{
    map->mlx_ptr = mlx_init();
    if (!map->mlx_ptr) {
        ft_printf("MLX init başarısız!\n");
        return (0);
    }

    map->win_ptr = mlx_new_window(map->mlx_ptr, map->width * 64, map->height * 64, "so_long");
    if (!map->win_ptr) {
        ft_printf("Pencere oluşturulamadı.\n");
        return (0);
    }

    if (!load_xpm_images(map)) {
        ft_printf("Hata: XPM dosyaları yüklenemedi.\n");
        free_map(map);
        return (0);
    }

    return (1);
}

// XPM resimlerini yükler.
// Belirtilen dosya yollarından XPM resimlerini yükler ve harita yapısına atar.
int load_xpm_images(t_map *map)
{
    int w, h;

    map->wall_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/walls_1.xpm", &w, &h);
    map->player_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/player.xpm", &w, &h);
    map->collectible_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/collectable.xpm", &w, &h);
    map->exit_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/gate.xpm", &w, &h);
    map->empty_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/floor01_1.xpm", &w, &h);

    if (!map->wall_img || !map->player_img || !map->collectible_img || !map->exit_img || !map->empty_img)
        return (0); // Bir tanesi bile yüklenemezse hata döndür.

    return (1); // Hepsi başarıyla yüklendi.
}