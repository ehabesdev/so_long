#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// 42 Kütüphaneleri
#include "../libs/libft/libft.h"                // libft
#include "../libs/ft_printf/libftprintf.h"        // ft_printf
#include "../libs/get_next_line/get_next_line.h" // GNL
#include "../libs/minilibx/mlx.h"    // MiniLibX

//Sabitler
# define TILE_SIZE 64

// -keycodelar-
# define KEY_W 17
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

// Yapılar (Structures)
typedef struct s_map
{
    char **map;        // Haritayı tutacak 2D dizi (char**)
    int width;         // Haritanın genişliği (kare sayısı)
    int height;        // Haritanın yüksekliği (kare sayısı)
    int collectibles;  // Haritadaki toplanabilir öğe sayısı
    int exit_count;    // Haritadaki çıkış sayısı (genellikle 1 olmalı)
    int player_count;  // Haritadaki oyuncu sayısı (genellikle 1 olmalı)
    char *path;        // Harita yolunu da struct'ın içinde sakla.
} t_map;

typedef struct s_img
{
    void    *img;           // Resmin MiniLibX içindeki tanımlayıcısı (işaretçi)
    char    *addr;          // Resmin piksel verilerinin bellekteki başlangıç adresi
    int     bits_per_pixel; // Piksel başına bit sayısı (renk derinliği)
    int     line_length;     // Bir satırın bayt cinsinden uzunluğu (satır genişliği)
    int     endian;          // Byte sıralaması (endianness)
    int     width;          // Resmin genişliği (piksel cinsinden)
    int     height;         // Resmin yüksekliği (piksel cinsinden)
} t_img;

typedef struct s_game {
    void        *mlx;          // MiniLibX bağlantı işaretçisi (instance pointer)
    void        *win;          // Pencere işaretçisi (window pointer)
    t_map       map;           // Harita verileri
    t_img       player;        // Oyuncu görseli
    t_img       wall;          // Duvar görseli
    t_img       floor;         // Zemin görseli
    t_img       collectible;   // Toplanabilir öğe görseli
    t_img       exit;          // Çıkış görseli
    int         player_x;      // Oyuncunun x koordinatı (kare cinsinden)
    int         player_y;      // Oyuncunun y koordinatı (kare cinsinden)
}   t_game;

// Fonksiyon prototipleri

// map_handling.c
int  map_check(t_map *map, char *map_path);
int check_valid_path(t_map *map);

// map_reading.c
int  read_map(int fd, t_map *map);

// map_validation.c
int  check_map_walls(t_map *map);
void free_map(t_map *map);
int  check_valid_path(t_map *map);

// map_utils.c
int is_valid_char(char c);
int process_line(t_map *map, char *line);

// game.c
void error_handler(char *message);
int key_hook(int keycode, t_game *game);
int exit_game(t_game *game);

// graphics.c
int  init_graphics(t_game *game);
int  load_images(t_game *game);
int  draw_map(t_game *game);
int  render_frame(t_game *game);

#endif
