#include "../include/so_long.h"

static int check_map_elements(t_map *map)
{
    if (map->player_count != 1)
    {
        error_handler("Error\nMap must contain exactly one player (P).");
        return (0);
    }
    if (map->exit_count != 1)
    {
        error_handler("Error\nMap must contain exactly one exit (E).");
        return (0);
    }
    if (map->collectibles < 1)
    {
        error_handler("Error\nMap must contain at least one collectible (C).");
        return (0);
    }
    return (1);
}

static int open_and_check_map(t_map *map, char *map_path, int *fd)
{
    map->map = NULL;
    map->collectibles = 0;
    map->exit_count = 0;
    map->player_count = 0;
    map->width = 0;
    map->height = 0;
    map->path = map_path;
    *fd = open(map_path, O_RDONLY);
    if (*fd == -1)
    {
        error_handler("Error\nFile cannot be opened");
        return (0);
    }
    return (1);
}

static int perform_map_checks(t_map *map, int fd)
{
    close(fd);

    if (!check_map_walls(map))
    {
        error_handler("Error\nMap is not surrounded by walls!");
        free_map(map);
        return (0);
    }
    if (!check_map_elements(map))
    {
        free_map(map);
        return (0);
    }
    return (1);
}

int map_check(t_map *map, char *map_path)
{
    int fd;
    
    if (!open_and_check_map(map, map_path, &fd))
        return (0);
    if (!read_map(fd, map))
    {
        close(fd);
        free_map(map);
        return (0);
    }
    if(!perform_map_checks(map, fd))
        return(0);
    return (1);
}
