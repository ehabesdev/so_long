#include "../include/so_long.h"

static char **allocate_memory(t_map *map);
static int  read_lines(int fd, t_map *map);
static int  reopen_and_copy(t_map *map, int fd);
static int  process_single_line(t_map *map, char **line, int *row);

int read_map(int fd, t_map *map)
{
    if (!read_lines(fd, map))
        return (0);
    if (!allocate_memory(map))
        return (0);
    if (!reopen_and_copy(map, fd))
        return (0);
    return (1);
}

static int read_lines(int fd, t_map *map)
{
    char *line;
    int  row;

    row = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        if (row == 0)
            map->width = ft_strlen(line);
        if (!process_single_line(map, &line, &row))
            return (0);
        line = get_next_line(fd);
    }
    if (line != NULL)
        free(line);
    if (row == 0)
    {
        error_handler("Empty file!");
        return (0);
    }
    map->height = row;
    return (1);
}

static int process_single_line(t_map *map, char **line, int *row)
{
    if (*row == 0)
        map->width = ft_strlen(*line);
    if (!process_line(map, *line))
    { 
        free(*line);
        return (0);
    }
    free(*line);
    *line = NULL;
    (*row)++;
    return (1);
}

static char **allocate_memory(t_map *map)
{
    int i;

    map->map = (char **)malloc(sizeof(char *) * map->height);
    if (!map->map)
    {
        error_handler("Error\nMemory allocation for map failed!");
        return (NULL);
    }
    i = 0;
    while (i < map->height)
    {
        map->map[i] = (char *)malloc(sizeof(char) * (map->width + 1));
        if (!map->map[i])
        {
            while (i > 0)
                free(map->map[--i]);
            free(map->map);
            error_handler("Error\nMalloc error!");
            return (NULL);
        }
        map->map[i][map->width] = '\0';
        i++;
    }
    return (map->map);
}

static int reopen_and_copy(t_map *map, int fd)
{
    char *line;
    int  row;

    close(fd);
    fd = open(map->path, O_RDONLY);
    if (fd == -1)
    {
        error_handler("Error\nReopening map file failed");
        return (0);
    }
    row = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        ft_memcpy(map->map[row], line, map->width);
        free(line);
        line = NULL;
        row++;
        line = get_next_line(fd);
    }
    close(fd);
    return (1);
}
