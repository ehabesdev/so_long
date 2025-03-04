#include "so_long.h"

// Ana fonksiyon. Programın başlangıç noktasıdır.
// Argümanları kontrol eder, haritayı ayrıştırır, başlatır, render eder,
// olay döngüsünü başlatır ve sonunda haritayı serbest bırakır.

int main(int argc, char **argv) {
    t_map *map;

    if (argc != 2) {
        ft_printf("Hata: Yanlış argüman sayısı.\n");
        return (1);
    }

    map = parse_map(argv[1]);
    if (!map) {
        ft_printf("Hata: Harita ayrıştırma başarısız.\n");
        return (1);
    }

    if (!init_map(map)) {
        ft_printf("Harita başlatılamadı.\n");
        free_map(map);
        return (1);
    }

    render_map(map);

    mlx_hook(map->win_ptr, 2, 1L<<0, handle_input, map);
    mlx_loop(map->mlx_ptr);

    free_map(map);
    return (0);
}

// Haritayı serbest bırakır.
// Harita yapısını, harita döşemelerini, MLX kaynaklarını ve resimleri serbest bırakır.
void free_map(t_map *map)
{
    int i;

    // Harita yapısı boş değilse devam et.
    if (map)
    {
        // Döşeme dizisi boş değilse devam et.
        if (map->tiles)
        {
            i = 0;
            // Her döşeme satırını serbest bırak.
            while (map->tiles[i])
            {
                free(map->tiles[i]);
                i++;
            }
            // Döşeme dizisini serbest bırak.
            free(map->tiles);
        }
        // MLX yapısı ve pencere boş değilse devam et.
        if (map->mlx_ptr && map->win_ptr)
        {
            // Pencereyi yok et.
            mlx_destroy_window(map->mlx_ptr, map->win_ptr);
            // Resimleri yok et.
            mlx_destroy_image(map->mlx_ptr, map->wall_img);
            mlx_destroy_image(map->mlx_ptr, map->player_img);
            mlx_destroy_image(map->mlx_ptr, map->collectible_img);
            mlx_destroy_image(map->mlx_ptr, map->exit_img);
            mlx_destroy_image(map->mlx_ptr, map->empty_img);
        }
        // Harita yapısını serbest bırak.
        free(map);
    }
}