#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

int    create_window(t_data *data)
{
    int width;
    int height;
    int window_width;
    int window_height;
    
    width = 0;
    height = 0;
    while (data->map[height])
        height++;
    width = ft_strlen(data->map[0]);
    data->tile_size = 192;
    data->current_player_frames = 0;
    window_width = data->tile_size * width;
    window_height = data->tile_size * height;
    data->mlx_window = mlx_new_window(data->mlx_connection, window_width, window_height, "so_long");
    if (!data->mlx_window)
        return (-1);
    return (0);
}

int close_window(t_data *data)
{
    int i;

    i = 0 ;
    if (data->img_ground)
        mlx_destroy_image(data->mlx_connection, data->img_ground);
    if (data->img_wall)
        mlx_destroy_image(data->mlx_connection, data->img_wall);
    if (data->img_collectible)
        mlx_destroy_image(data->mlx_connection, data->img_collectible);
    if (data->img_exit)
        mlx_destroy_image(data->mlx_connection, data->img_exit);
    if (data->img_enemy)
    {
        while (i < TOTAL_PLAYER_FRAMES)
        {
            mlx_destroy_image(data->mlx_connection, data->img_player[i]);
            i++;
        }
        free(data->img_player);
    }
    i = 0;
    if (data->img_enemy)
    {
        while (i < TOTAL_ENEMY_FRAMES)
        {
            mlx_destroy_image(data->mlx_connection, data->img_enemy[i]);
            i++;
        }
        free(data->img_enemy);
    }
    if (data->enemy)
        free(data->enemy);
    mlx_destroy_window(data->mlx_connection, data->mlx_window);
    mlx_destroy_display(data->mlx_connection);
    free(data->mlx_connection);
    free_map(data->map);
    exit(0);
    return (0);
}



void write_on_screen(t_data *data)
{
    char *str_steps;
    int x;
    int y;

    str_steps = ft_itoa(data->footsteps);
    x = data->tile_size / 2;
    y = data->tile_size / 2;
    mlx_string_put(data->mlx_connection, data->mlx_window, x, y, 0x000000 , str_steps);
    free(str_steps);
}
