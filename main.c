#include <stdlib.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "so_long.h"

int     load_images(t_data *data)
{
    int    w;
    int    h;

    data->img_wall = mlx_xpm_file_to_image(data->mlx_connection, "sprites/wall.xpm", &w, &h);
    data->img_ground = mlx_xpm_file_to_image(data->mlx_connection, "sprites/ground.xpm", &w, &h);
    if (load_player_frames(data) == -1 || load_enemy_frames(data) == -1)
        {
            ft_printf("Error\nFailed to load Player Frames\n");
            return (-1);
        }
    data->img_collectible = mlx_xpm_file_to_image(data->mlx_connection, "sprites/collectible.xpm", &w, &h);
    data->img_exit = mlx_xpm_file_to_image(data->mlx_connection, "sprites/exit.xpm", &w, &h);
    if (!data->img_wall || !data->img_ground
        || !data->img_collectible || !data->img_exit)
    {
        ft_printf("Error\nFailed to load one or more images\n");
        return (-1);
    }
    return (0);
}

int main()
{
    t_data data;

    ft_memset(&data, 0, sizeof(t_data)); // initialse toute la memoire a zero
    data.mlx_connection = mlx_init();
    if (data.mlx_connection == NULL)
        return (-1);
    data.map = load_map(&data);
    if (!data.map || !data.map[0])
    {
        ft_printf("Error : map\nFailed to load map\n");
        free(data.mlx_connection);
        return (-1);
    }
    if (create_window(&data) == -1)
    {
        ft_printf("Error : window\nFailed to create window\n");
        return (-1);
    }
    data.n_enemies = count_enemies(&data);
    data.enemy = malloc(sizeof(t_enemy) * data.n_enemies);
    if (!data.enemy)
        return (-1);
    player_position(&data);
    data.floodfill = floodfill(&data, data.map, data.map_width, data.map_height);
    if (data.floodfill == 0)
    {
        ft_printf("Error : floodfill\nCollectible or Exit are not reachable\n");
        close_window(&data);
        return (-1);
    }
    enemy_position(&data);
    n_collectible(&data);
    data.footsteps = 0;
    data.current_enemy_frames = 0;
    data.current_player_frames = 0;
    if (load_images(&data) == -1) // charger ttes les images une fois
        return (-1);
    put_map(&data); // je free dans load_map
    mlx_key_hook(data.mlx_window, key_handler, &data);
    mlx_loop_hook(data.mlx_connection, animate_all, &data);
    mlx_hook(data.mlx_window, 17, 0, close_window, &data);
    mlx_loop(data.mlx_connection);
    return (0);
}


// gcc main.c load_map.c put_images.c manage_window.c key_hook.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c -Lmlx -lmlx -lXext -lX11 -Imlx libft/libft.a ft_printf/libftprintf.a

// valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
