#include "../include/so_long.h"

int is_valid_char(char c)
{
    if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'))
    {
        error_handler("Error\nInvalid char in map.");
        return (0);
    }
    return (1);
}


int process_line(t_map *map, char *line)
{
    int col;

    col = 0;
    if ((int)ft_strlen(line) != map->width)
    {
        error_handler("Error\nInvalid map: Line lengths are not consistent.");
        return (0);
    }
    while (line[col] != '\0')
    {
        if (!is_valid_char(line[col]))
            return (0);
        if (line[col] == 'C')
            map->collectibles++;
        else if (line[col] == 'E')
            map->exit_count++;
        else if (line[col] == 'P')
            map->player_count++;
        col++;
    }
    return (1);
}