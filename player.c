#include <stdlib.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "so_long.h"


void		get_next_position(t_data *data, char *str, int *new_x, int *new_y)
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
		if (data->player_x == data->exit_x && data->player_y == data->exit_y)
			data->map[data->player_y][data->player_x] = 'E';
		else
			data->map[data->player_y][data->player_x] = '0';
		data->player_x = new_x;
		data->player_y = new_y;
		enemy_mouvement(data);
		if (data->map[data->player_y][data->player_x] == 'I' || data->map[new_y][new_x + data->enemy->direction] == 'I' ) //  a modifier
			you_died(data);
		if (data->map[data->player_y][data->player_x] == 'C')
		{
			data->n_collectible--;
			ft_printf("you found a bag full of coins !\n----------- %d LEFT ------------\n", data->n_collectible);
		}
		if (data->map[new_y][new_x] == 'E' && data->n_collectible == 0)
			you_won(data);
		data->map[data->player_y][data->player_x] = 'P';
		ft_printf("%d\n", data->footsteps += 1);
		put_map(data);
	}
}

void	update_player_state(t_data *data, int new_x, int new_y)
{
	if (data->player_x == data->exit_x && data->player_y == data->exit_y)
		data->map[data->player_y][data->player_x] = 'E';
	else
		data->map[data->player_y][data->player_x] = '0';

	data->player_x = new_x;
	data->player_y = new_y;

	if (data->map[new_y][new_x] == 'C')
	{
		data->n_collectible--;
		ft_printf("you found a bag full of coins !\n----------- %d LEFT ------------\n", data->n_collectible);
	}

	enemy_mouvement(data);

	if (data->map[new_y][new_x] == 'I')
		you_died(data);

	if (data->map[new_y][new_x] == 'E' && data->n_collectible == 0)
		you_won(data);

	data->map[new_y][new_x] = 'P';
	ft_printf("%d\n", data->footsteps += 1);
	put_map(data);
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
