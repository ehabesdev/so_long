#include "../include/so_long.h"

int init_graphics(t_game *game)
{
    game->mlx = mlx_init();
    if (game->mlx == NULL)
    {
        error_handler("Error\nFailed to initialize MiniLibX.");
        return (0);
    }
    int window_width;
    int window_height;
    window_width = game->map.width * TILE_SIZE;
    window_height = game->map.height * TILE_SIZE;
    game->win = mlx_new_window(game->mlx, window_width, window_height, "So Long");
    if (game->win == NULL)
    {
        free(game->mlx);
        error_handler("Error\nFailed to create window.");
        return (0);
    }
    return (1);
}

static int load_single_image(t_game *game, t_img *img, char *path)
{
    img->img = mlx_xpm_file_to_image(game->mlx, path, &img->width, &img->height);
    if (!img->img)
    {
        error_handler("Error\nFailed to load image");
        return (0);
    }
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    return (1);
}

int load_images(t_game *game)
{
    if (!load_single_image(game, &game->wall, "assets/wall.xpm"))
        return (0);
    if (!load_single_image(game, &game->floor, "assets/floor.xpm"))
        return (0);
    if (!load_single_image(game, &game->player, "assets/player.xpm"))
        return (0);
    if (!load_single_image(game, &game->collectible, "assets/collectible.xpm"))
        return (0);
    if (!load_single_image(game, &game->exit, "assets/exit.xpm"))
        return (0);
    return (1);
}

// graphics.c

int draw_map(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            mlx_put_image_to_window(game->mlx, game->win, game->floor.img, x * TILE_SIZE, y * TILE_SIZE);
            if (game->map.map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall.img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map.map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collectible.img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map.map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit.img,  x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
    return (1);
}
