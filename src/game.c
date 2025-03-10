#include "../include/so_long.h"
#include <stdio.h> // NULL için geçici olarak.

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        error_handler("Usage: ./so_long <map_file.ber>");
        return (1);
    }
    if (!map_check(&game.map, argv[1]))
        return (1);
    if (!init_graphics(&game)) //Grafik arayüzünü başlat
    {
        free_map(&game.map);
        return (1);
    }
    if (!load_images(&game))
    {
        exit_game(&game);
        return (1);
    }
    draw_map(&game);
    mlx_key_hook(game.win, key_hook, &game);
    mlx_hook(game.win, 17, 0, exit_game, &game); // Çıkış eventi (X butonu)
    mlx_loop(game.mlx);
    return (0);
}

void error_handler(char *message)
{
    ft_printf("%s\n", message);
    exit(1);
}

int key_hook(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_game(game);
    // İleride diğer tuş kontrollerini ekle (WASD veya ok tuşları)
    return (0);
}

int exit_game(t_game *game)
{
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);

    // Yüklenen resimleri kontrol et ve free'le
    if (game->wall.img)
        mlx_destroy_image(game->mlx, game->wall.img);
    if(game->floor.img)
        mlx_destroy_image(game->mlx, game->floor.img);
    if(game->player.img)
        mlx_destroy_image(game->mlx, game->player.img);
    if(game->collectible.img)
        mlx_destroy_image(game->mlx, game->collectible.img);
    if(game->exit.img)
        mlx_destroy_image(game->mlx, game->exit.img);
    free_map(&game->map);
    if(game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    exit(0);
}