#include "so_long.h"

t_map *parse_map(char *filename)
{
    t_map *map = malloc(sizeof(t_map));
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        ft_printf("Harita dosyası açma hatası\n");
        free(map);
        return NULL;
    }
    map->tiles = NULL;
    return read_map_lines(fd, map);
}

t_map *read_map_lines(int fd, t_map *map)
{
    char *line;
    int y = 0, width = 0;
    while ((line = get_next_line(fd)) != NULL) {
        int len = strlen(line) - 1;
        if (width == 0) width = len;
        else if (width != len) {
            ft_printf("Hata: Harita dikdörtgen değil.\n");
            free_map(map); close(fd); free(line);
            return NULL;
        }
        map->tiles = realloc(map->tiles, sizeof(char *) * (y + 2));
        map->tiles[y] = strdup(line); map->tiles[y][len] = '\0';
        if (!process_map_line(map, map->tiles[y], y)) {
            close(fd); free(line); return NULL;
        }
        free(line); y++;
    }
    map->tiles[y] = NULL; close(fd);
    return check_map_validity(map);
}

int process_map_line(t_map *map, char *line, int y)
{
    for (int x = 0; line[x]; x++) {
        if (line[x] == PLAYER) {
            map->player_x = x; map->player_y = y; map->player_count++;
        } else if (line[x] == COLLECTIBLE) map->collectible_count++;
        else if (line[x] == EXIT) map->exit_count++;
        else if (line[x] != EMPTY && line[x] != WALL) {
            ft_printf("Hata: Geçersiz harita karakteri: %c\n", line[x]);
            free_map(map); return 0;
        }
    }
    return (1);
}

t_map *check_map_validity(t_map *map) {
    if (map->player_count != 1 || map->exit_count != 1 || map->collectible_count == 0) {
        ft_printf("Hata: Geçersiz P, E veya C sayısı.\n");
        free_map(map); return NULL;
    }
    map->width = strlen(map->tiles[0]);
    map->height = 0; while (map->tiles[map->height]) map->height++;
    return check_map_walls(map);
}

t_map *check_map_walls(t_map *map)
{
    for (int i = 0; i < map->width; i++)
        if (map->tiles[0][i] != WALL || map->tiles[map->height - 1][i] != WALL) {
            ft_printf("Hata: Yatay duvar hatası.\n");
            free_map(map); return NULL;
        }
    for (int i = 0; i < map->height; i++)
        if (map->tiles[i][0] != WALL || map->tiles[i][map->width - 1] != WALL) {
            ft_printf("Hata: Dikey duvar hatası.\n");
            free_map(map); return NULL;
        }
    return (map);
}