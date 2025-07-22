#include "so_long.h"
#include "mlx/mlx.h"

int     load_player_frames(t_data *data)
{
    int i;
    int w;
    int h;

    i = 0;
    data->img_player = malloc(sizeof(void *) * TOTAL_PLAYER_FRAMES);
    if (!data->img_player)
        return (-1);
    data->img_player[0] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/player0.xpm", &w, &h);
    data->img_player[1] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/player1.xpm", &w, &h);
    data->img_player[2] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/player2.xpm", &w, &h);
    data->img_player[3] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/player3.xpm", &w, &h);
    data->img_player[4] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/player4.xpm", &w, &h);
    data->img_player[5] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/player5.xpm", &w, &h);
    data->img_player[6] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/player6.xpm", &w, &h);
    while(i < TOTAL_PLAYER_FRAMES)
    {
        if (!data->img_player[i])
            return (-1);
        i++;
    }
    return (0);
}

int     load_enemy_frames(t_data *data)
{
    int i;
    int w;
    int h;

    i = 0;
    data->img_enemy = malloc(sizeof(void *) * TOTAL_ENEMY_FRAMES);
    if (!data->img_enemy)
        return (-1);
    data->img_enemy[0] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/enemy0.xpm", &w, &h);
    data->img_enemy[1] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/enemy1.xpm", &w, &h);
    data->img_enemy[2] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/enemy2.xpm", &w, &h);
    data->img_enemy[3] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/enemy3.xpm", &w, &h);
    data->img_enemy[4] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/enemy4.xpm", &w, &h);
    data->img_enemy[5] = mlx_xpm_file_to_image(data->mlx_connection, "sprites/enemy5.xpm", &w, &h);
    while(i < TOTAL_ENEMY_FRAMES)
    {
        if (!data->img_enemy[i])
            return (-1);
        i++;
    }
    return (0);
}

int animate_player(t_data *data)
{
    static int frame_player_counter;
    if (frame_player_counter == 0)
        frame_player_counter = 1;
    else
        frame_player_counter++;
    if (frame_player_counter >= 7500) // changer toutes les x boucles
    {
        data->current_player_frames++;
        if (data->current_player_frames >= TOTAL_PLAYER_FRAMES)
            data->current_player_frames = 0;
        put_map(data);
        frame_player_counter = 0;
    }
    return (0);
}

int animate_enemy(t_data *data)
{
    static int frame_enemy_counter;
    if (frame_enemy_counter == 0)
        frame_enemy_counter = 1;
    else
        frame_enemy_counter++;
    if (frame_enemy_counter >= 7000) // changer toutes les x boucles
    {
        data->current_enemy_frames++;
        if (data->current_enemy_frames >= TOTAL_ENEMY_FRAMES)
            data->current_enemy_frames = 0;
        put_map(data);
        frame_enemy_counter = 0;
    }
    return (0);
}

int animate_all(t_data *data)
{
    animate_enemy(data);
    animate_player(data);
    return (0);
}

