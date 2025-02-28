#include "so_long.h"

void init_map(t_map *map) {
    map->mlx_ptr = mlx_init();
    map->win_ptr = mlx_new_window(map->mlx_ptr, map->width * 64, map->height * 64, "so_long");
    load_xpm_images(map);
    if (!map->wall_img || !map->player_img || !map->collectible_img || !map->exit_img || !map->empty_img) {
        ft_printf("Hata: XPM yükleme hatası.\n");
        free_map(map); exit(1);
    }
}

void load_xpm_images(t_map *map) 
{
    int w, h;
    map->wall_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/walls_1.xpm", &w, &h);
    map->player_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/player.xpm", &w, &h);
    map->collectible_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/collectable.xpm", &w, &h);
    map->exit_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/gate.xpm", &w, &h);
    map->empty_img = mlx_xpm_file_to_image(map->mlx_ptr, "assets/floor01_1.xpm", &w, &h);
}