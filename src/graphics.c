#include "so_long.h"

// Haritayı ekrana çizer.
// Döşeme dizisindeki her bir karaktere karşılık gelen resmi pencereye çizer.
void render_map(t_map *map) {
    int x;
    int y;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            // Döşeme türüne göre resmi çiz.
            if (map->tiles[y][x] == WALL)
                mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall_img, x * 64, y * 64);
            else if (map->tiles[y][x] == PLAYER)
                mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player_img, x * 64, y * 64);
            else if (map->tiles[y][x] == COLLECTIBLE)
                mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->collectible_img, x * 64, y * 64);
            else if (map->tiles[y][x] == EXIT)
                mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->exit_img, x * 64, y * 64);
            else
                mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->empty_img, x * 64, y * 64);
            x++;
        }
        y++;
    }
}

// Kullanıcı girişini işler.
// WASD tuşlarına göre oyuncuyu hareket ettirir ve pencereyi kapatır.
int handle_input(int keycode, t_map *map)
{
    int new_x;
    int new_y;

    new_x = map->player_x;
    new_y = map->player_y;
    if (keycode == 65307) // ESC tuşu
    {
        free_map(map);
        exit(0);
    }
    else if (keycode == 119) // W tuşu
        new_y--;
    else if (keycode == 115) // S tuşu
        new_y++;
    else if (keycode == 97) // A tuşu
        new_x--;
    else if (keycode == 100) // D tuşu
        new_x++;
    // Yeni konum duvarda değilse ve geçerli bir konumsa oyuncuyu hareket ettir.
    if (map->tiles[new_y][new_x] != WALL && new_x >= 0 && new_x < map->width && new_y >= 0 && new_y < map->height)
    {
        update_player_position(map, new_x, new_y);
        render_map(map); // Haritayı yeniden çiz.
    }
    return (0);
}

// Oyuncunun konumunu günceller.
// Eski konumu boş alan olarak işaretler ve yeni konumu oyuncu olarak işaretler.
void update_player_position(t_map *map, int new_x, int new_y)
{
    // Eski konumu boş alan olarak işaretle.
    map->tiles[map->player_y][map->player_x] = EMPTY;
    // Yeni konumu oyuncu olarak işaretle.
    map->tiles[new_y][new_x] = PLAYER;
    // Oyuncunun konumunu güncelle.
    map->player_x = new_x;
    map->player_y = new_y;
    // Hareket sayısını artır.
    map->move_count++;
    // Hareket sayısını ekrana yazdır.
    ft_printf("Hareket Sayısı: %d\n", map->move_count);
}