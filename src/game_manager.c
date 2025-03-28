#include "../include/so_long.h"

static void handle_destination_tile(t_game *game, char destination_char)
{
    if (destination_char == 'C')
    {
        game->map.collectibles--;
        game->map.map[game->player_y][game->player_x] = 'P';
    }
    else if (destination_char == 'E')
    {
        if (game->map.collectibles == 0)
        {
            end_game_text(game);
            exit_game(game);
        }
    }
    else
        game->map.map[game->player_y][game->player_x] = 'P';
}

static int handle_movement(t_game *game, int new_x, int new_y)
{
    char destination_char;
    int  old_x;
    int  old_y;

    old_x = game->player_x;
    old_y = game->player_y;
    if (!is_valid_move(&game->map, new_x, new_y))
        return (0);
    destination_char = game->map.map[new_y][new_x];
    if (!(game->map.map[old_y][old_x] == 'E' && game->map.collectibles > 0))
        game->map.map[old_y][old_x] = '0';
    game->player_x = new_x;
    game->player_y = new_y;
    game->moves += 1;
    ft_printf("Moves: %u\n", game->moves);
    handle_destination_tile(game, destination_char);
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

