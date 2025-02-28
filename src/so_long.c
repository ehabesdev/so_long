#include "so_long.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        ft_printf("Hata: Yanlış argüman sayısı.\n");
        return 1;
    }

    t_map *map = parse_map(argv[1]);
    if (!map) {
        ft_printf("Hata: Harita ayrıştırma başarısız.\n");
        return 1;
    }

    init_map(map);
    render_map(map);

    mlx_hook(map->win_ptr, 2, 1L<<0, handle_input, map);
    mlx_loop(map->mlx_ptr);

    free_map(map);
    return 0;
}

void free_map(t_map *map) {
    if (map) {
        if (map->tiles) {
            for (int i = 0; map->tiles[i]; i++) {
                free(map->tiles[i]);
            }
            free(map->tiles);
        }
        if (map->mlx_ptr && map->win_ptr) {
            mlx_destroy_window(map->mlx_ptr, map->win_ptr);
            mlx_destroy_image(map->mlx_ptr, map->wall_img);
            mlx_destroy_image(map->mlx_ptr, map->player_img);
            mlx_destroy_image(map->mlx_ptr, map->collectible_img);
            mlx_destroy_image(map->mlx_ptr, map->exit_img);
                        mlx_destroy_image(map->mlx_ptr, map->empty_img);
        }
        free(map);
    }
}