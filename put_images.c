#include "so_long.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

void    put_wall(t_data *data, int x, int y)
{
    int x_pixel;
    int y_pixel;

    y_pixel = y * data->tile_size;
    x_pixel = x * data->tile_size;
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img_wall, x_pixel, y_pixel);
}

void     put_ground(t_data *data, int x, int y)
{
    int x_pixel;
    int y_pixel;

    y_pixel = y * data->tile_size;
    x_pixel = x * data->tile_size;
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img_ground, x_pixel, y_pixel);
}

void    put_collectible(t_data *data, int x, int y)
{
    int x_pixel;
    int y_pixel;

    y_pixel = y * data->tile_size;
    x_pixel = x * data->tile_size;
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img_collectible, x_pixel, y_pixel);
}

void    put_exit(t_data *data, int x, int y)
{
    int x_pixel;
    int y_pixel;

    y_pixel = y * data->tile_size;
    x_pixel = x * data->tile_size;
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img_exit, x_pixel, y_pixel);
}

void    put_player(t_data *data, int x, int y)
{
    int x_pixel;
    int y_pixel;

    y_pixel = y * data->tile_size;
    x_pixel = x * data->tile_size;
    if (!data->img_player[data->current_player_frames])
    {
        ft_printf("Error: player image current_player_frames %d not loaded\n", data->current_player_frames);
        return;
    }
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img_player[data->current_player_frames], x_pixel, y_pixel);
}

void    put_enemy(t_data *data, int x, int y)
{
    int x_pixel;
    int y_pixel;

    y_pixel = y * data->tile_size;
    x_pixel = x * data->tile_size;
    if (!data->img_enemy[data->current_enemy_frames])
    {
        ft_printf("Error: enemy image current_enemy_frames %d not loaded\n", data->current_enemy_frames);
        return;
    }
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img_enemy[data->current_enemy_frames], x_pixel, y_pixel);
}
