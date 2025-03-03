#include "so_long.h"

// Harita yapısını başlatır.
// MLX yapısını, pencereyi, XPM resimlerini yükler ve hata kontrolü yapar.
void init_map(t_map *map) {
    // MLX yapısını başlat.
    map->mlx_ptr = mlx_init();
    // Yeni bir pencere oluştur.
    map->win_ptr = mlx_new_window(map->mlx_ptr, map->width * 64, map->height * 64, "so_long");
    // XPM resimlerini yükle.
    load_xpm_images(map);
    // XPM yükleme hatası kontrolü yap.
    if (!map->wall_img || !map->player_img || !map->collectible_img || !map->exit_img || !map->empty_img)
    {
        ft_printf("Hata: XPM yükleme hatası.\n");
        free_map(map);
        exit(1);
    }
}

// XPM resimlerini yükler.
// Belirtilen dosya yollarından XPM resimlerini yükler ve harita yapısına atar.
void load_xpm_images(t_map *map) 
{
    int w;
    int h;

    // Duvar resmini yükle.
    map->wall_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/walls_1.xpm", &w, &h);
    // Oyuncu resmini yükle.
    map->player_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/player.xpm", &w, &h);
    // Toplanabilir resmini yükle.
    map->collectible_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/collectable.xpm", &w, &h);
    // Çıkış resmini yükle.
    map->exit_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/gate.xpm", &w, &h);
    // Boş alan resmini yükle.
    map->empty_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/floor01_1.xpm", &w, &h);
}