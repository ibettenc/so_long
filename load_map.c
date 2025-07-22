/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:08:25 by ibettenc          #+#    #+#             */
/*   Updated: 2025/07/16 14:13:54 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "so_long.h"
#include "mlx/mlx.h"
#include <fcntl.h>  // open()
#include <stdlib.h> // free()
#include <unistd.h> // close()

int	parsing_lines(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	if (len <= 0)
	{
		ft_printf("Error\nMap lines are not the same size\n");
		return (-1);
	}
	return (len);
}

void free_map(char **map)
{
    int i;
	
	i = 0;
    if (!map)
        return;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int    put_map(t_data *data)
{
    int     y;
    int     x;

    mlx_clear_window(data->mlx_connection, data->mlx_window);
    y = 0;
    while(data->map[y])
    {
        x = 0;
        while(data->map[y][x])
        {
				if (data->map[y][x] != '1' && data->map[y][x] != '0' && data->map[y][x] != 'C'
					&& data->map[y][x] != 'E' && data->map[y][x] != 'I' && data->map[y][x] != 'P')
				{
					ft_printf("\nError\nWrong character in map.ber\n\n");
					close_window(data);
					return (-1);
				}
					if (data->map[y][x] == '1')
                    put_wall(data, x, y);
                else if (data->map[y][x] == '0')
                    put_ground(data, x, y);
                else if (data->map[y][x] == 'C')
                    put_collectible(data, x, y);
                else if (data->map[y][x] == 'E')
                    put_exit(data, x, y);
                else if (data->map[y][x] == 'I')
                    put_enemy(data, x, y);
                else if (data->map[y][x] == 'P')
                    put_player(data, x, y);
                else
                    return (-1);
                x++;
        }
        y++;
    }
    write_on_screen(data);
    return (0);
}

char	**load_map(t_data *data)
{
	int		fd;
	int		len;
	int		height;
	int		verification;
	char	*line;
	char	**map;

	fd = open("maps/map.ber", O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = calloc(30, sizeof(char *)); // initialise tous les pointeurs à NULL

	if (!map)
		return (NULL);

	line = get_next_line(fd);
	if (!line)
		return (free_map(map), close(fd), NULL);
	height = 0;
	
	verification = parsing_lines(line);
	
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	
	while (line)
	{
		if (verification != parsing_lines(line))
			return (free(line), free_map(map), free(data->mlx_connection), close(fd), NULL);

		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		
		map[height] = ft_strdup(line);
		if (!map[height])
			return (free_map(map), free(line), free(data->mlx_connection), close(fd), NULL);
		
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	map[height] = NULL;
	return (map);
}
// FUNCTION TOO LONG NUT THE REST IS NORM OK
