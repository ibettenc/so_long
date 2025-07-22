/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:44:18 by ibettenc          #+#    #+#             */
/*   Updated: 2025/07/12 15:57:29 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define TOTAL_PLAYER_FRAMES 7
#define TOTAL_ENEMY_FRAMES 6

typedef struct s_enemy
{
	int		x;
	int		y;
	int		direction;
}	t_enemy;

typedef struct s_data
{
	void	*mlx_connection;
	void	*mlx_window;
	char	**map;
	int		tile_size;
	int		n_collectible;
	int		exit;
	int		exit_y;
	int		exit_x;
	int		footsteps;

	void	*img_wall;
	void	*img_ground;
	void	*img_collectible;
	void	*img_exit;
	void	**img_player;
	void	**img_enemy;

	int		current_player_frames;
	int		current_enemy_frames;
	int		player_x;
	int		player_y;
	int		n_enemies;
	t_enemy	*enemy;
}	t_data;

int		parsing_lines(char *line);
void	free_map_and_lines(char **map, char *line, int height, int fd);
int		allocate_map(char **map, char *line, int height);
char	**load_map(t_data *data);
void	free_map(char **map);
int		close_window(t_data *data);
int		load_images(t_data *data);
void	put_wall(t_data *data, int x, int y);
void	put_ground(t_data *data, int x, int y);
void	put_enemy(t_data *data, int x, int y);
void	put_collectible(t_data *data, int x, int y);
void	put_exit(t_data *data, int x, int y);
void	put_player(t_data *data, int x, int y);
int		put_map(t_data *data);
int		key_handler(int keycode, t_data *data);
void	player_position(t_data *data);
void	player_mouvement(t_data *data, char *str);
int		create_window(t_data *data);
void	n_collectible(t_data *data);
int     animate_player(t_data *data);
int     animate_enemy(t_data *data);
int     load_player_frames(t_data *data);
int     load_enemy_frames(t_data *data);
int		animate_all(t_data *data);
void	write_on_screen(t_data *data);
void	enemy_position(t_data *data);
int		count_enemies(t_data *data);
void 	you_died(t_data *data);