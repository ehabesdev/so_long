#include "../include/so_long.h"

int is_valid_move(t_map *map, int new_x, int new_y)
{
    if (new_x < 0 || new_x >= map->width || new_y < 0 || new_y >= map->height)
        return (0);
    if (map->map[new_y][new_x] == '1')
        return (0);
    return (1);
}

void error_handler(char *message)
{
    ft_printf("Error\n%s\n", message);
    exit(1);
}

void end_game_text(t_game *game)
{
    ft_printf("  _____                     _    _                     \n");
    ft_printf(" |  __ \\                   | |  | |                    \n");
    ft_printf(" | |__) |  _ __    ___   __| |  | |  ___    ___    _ __ \n");
    ft_printf(" |  _  /  | '__|  / _ \\ / _` |  | | / __|  / _ \\  | '__|\n");
    ft_printf(" | | \\ \\  | |    |  __/| (_| |  | | \\__ \\ | (_) | | |\n");
    ft_printf(" |_|  \\_\\ |_|     \\___| \\__,_|  |_| |___/  \\___/  |_|\n");
    ft_printf("                                                       \n");
    ft_printf("    **********************************************     \n");
    ft_printf("    * Congrats! You beat the game in %u moves!   *     \n", game->moves);
    ft_printf("    *  So long, and thanks for all the fish!     *     \n");
    ft_printf("    *                 by ehabes                  *     \n");
    ft_printf("    **********************************************     \n");
    ft_printf("                                                       \n");
}
