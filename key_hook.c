#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "so_long.h"

void 	you_won(t_data *data)
{

	ft_printf("-----------\n--YOU WON--\n-----------\n");
	close_window(data);
}
void 	you_died(t_data *data)
{

		ft_printf("\n--------------\n---YOU DIED---\n--------------\n\n");
		close_window(data);
}

void	n_collectible(t_data *data)
{
	int x;
	int y;

	data->n_collectible = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while(data->map[y][x])
		{
			if (data->map[y][x] == 'C')
			{
				data->n_collectible++;
			}
			x++;
		}
		y++;
	}
}


void	enemy_mouvement(t_data *data)
{
	int		new_x;
	int		new_y;
	int		i;
	char	next_tile;

	i = 0;
	while (i < data->n_enemies)
	{
		next_tile = data->map[data->enemy[i].y][data->enemy[i].x + data->enemy[i].direction];
		new_x = data->enemy[i].x + data->enemy[i].direction;
		new_y = data->enemy[i].y;
		if (new_x >= 0 && new_x < (int)ft_strlen(data->map[new_y]))
		{
			if (next_tile != 'E' && next_tile != '1' && next_tile != 'I')
			{
				data->map[data->enemy[i].y][data->enemy[i].x] = '0';
				data->map[new_y][new_x] = 'I';
				data->enemy[i].x = new_x;
    		}
			else
				data->enemy[i].direction *= -1;
		}
		else
		data->enemy[i].direction *= -1;
		i++;
	}
}


void		player_mouvement(t_data *data, char *str)
{
	int new_x;
	int new_y;
	
	new_x = data->player_x;
	new_y = data->player_y;
	if (ft_strncmp(str, "UP", 2) == 0)
		new_y--;
	else if (ft_strncmp(str, "DOWN", 4) == 0)
		new_y++;
	else if (ft_strncmp(str, "LEFT", 4) == 0)
		new_x--;
	else if (ft_strncmp(str, "RIGHT", 5) == 0)
		new_x++;
	if (data->map[new_y][new_x] != '1')
	{	
		if (data->map[new_y][new_x] == 'I')
			you_died(data);
		if (data->map[new_y][new_x] == 'C')
		{
			data->n_collectible--;
			ft_printf("you found a bag full of coins !\n----------- %d LEFT ------------\n", data->n_collectible);
		}
		if (data->map[new_y][new_x] == 'E' && data->n_collectible == 0)
			you_won(data);
		if (data->player_x == data->exit_x && data->player_y == data->exit_y)
			data->map[data->player_y][data->player_x] = 'E';	
		else 
		{
			data->map[data->player_y][data->player_x] = '0';
			enemy_mouvement(data);
		}
		data->map[new_y][new_x] = 'P';
		data->player_x = new_x;
		data->player_y = new_y;
		ft_printf("%d\n", data->footsteps += 1);
		put_map(data);
	}
}

int	count_enemies(t_data *data)
{
	data->n_enemies = 0;
	int x;
	int y;
	int n_enemies;

	n_enemies = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while(data->map[y][x])
		{
			if (data->map[y][x] == 'I')
				n_enemies++;
			x++;
		}
		y++;
	}
	return (n_enemies);
}

void	enemy_position(t_data *data)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while(data->map[y][x])
		{
			if (data->map[y][x] == 'I' && data->n_enemies)
			{
				data->enemy[i].x = x;
				data->enemy[i].y = y;
				data->enemy[i].direction = (i % 2 == 1) ? 1 : -1;
				i++;
			}
			x++;
		}
		y++;
	}
}
 

void	player_position(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while(data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			if (data->map[y][x] == 'E')
			{
				data->exit_x = x;
				data->exit_y = y;
			}
			x++;
		}
		y++;
	}
}

int key_handler(int keycode, t_data *data)
{
	if (keycode == 65307) // ÉCHAP
        close_window(data);
	else if (keycode == 119) // W
		player_mouvement(data, "UP");
	else if (keycode == 115) // S
		player_mouvement(data, "DOWN");  
    else if (keycode == 97) // A
    	player_mouvement(data, "LEFT");
	else if (keycode == 100) // D
		player_mouvement(data, "RIGHT");
	return (0);
}
