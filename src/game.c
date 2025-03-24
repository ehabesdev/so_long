#include "../include/so_long.h"

static void find_player_start(t_game *game)
{
    int x = 0;
    int y = 0;

    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width) {
            if (game->map.map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                return ;
            }
            x++;
        }
        y++;
    }
}

static int handle_movement(t_game *game, int new_x, int new_y)
{
    if (!is_valid_move(&game->map, new_x, new_y))
        return (0);
    game->map.map[game->player_y][game->player_x] = '0';
    game->player_x = new_x;
    game->player_y = new_y;
    game->moves += 1;
    ft_printf("Hamle: %u\n", game->moves);
    if (game->map.map[new_y][new_x] == 'C')
        game->map.collectibles--;
    if (game->map.collectibles == 0 && game->map.map[new_y][new_x] == 'E')
    {
        end_game_text(game);
        exit_game(game);
    }
    game->map.map[game->player_y][game->player_x] = 'P';
    draw_map(game);
    return (1);
}

int key_hook(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_game(game);
    else if (keycode == KEY_W)
        handle_movement(game, game->player_x, game->player_y - 1);
    else if (keycode == KEY_A)
        handle_movement(game, game->player_x - 1, game->player_y);
    else if (keycode == KEY_S)
        handle_movement(game, game->player_x, game->player_y + 1);
    else if (keycode == KEY_D)
        handle_movement(game, game->player_x + 1, game->player_y);
    return (0);
}

int main(int argc, char **argv)
{
    t_game game;

    game.moves = 0;
    if (argc != 2)
    {
        error_handler("Usage: ./so_long <map_file.ber>");
        return (1);
    }
    if (!map_check(&game.map, argv[1]))
        return (1);
    find_player_start(&game);
    if (!init_graphics(&game))
    {
        free_map(&game.map);
        return (1);
    }
    if (!load_images(&game))
        exit_game(&game);
    draw_map(&game);
    mlx_key_hook(game.win, key_hook, &game);
    mlx_hook(game.win, 17, 0, exit_game, &game);
    mlx_loop(game.mlx);
    return (0);
}

int exit_game(t_game *game)
{
  if (game->win)
    mlx_destroy_window(game->mlx, game->win);
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
