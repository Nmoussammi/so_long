/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 02:06:00 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/24 12:26:06 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"
# include <string.h>
# include <stdio.h>
# include "../ft_printf/ft_printf.h"

# define IMG_SIZE 50

typedef struct s_map{
	int		nb_lines;
	char	**map;
	int		i;
	int		j;
	int		w;
	int		position_i;
	int		position_j;
	int		dollar;
	void	*dollar_image;
	void	*exit;
	void	*mlx;
	void	*mlx_win;
	void	*background;
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*close_door;
	void	*open_door;
	int		player_pos;
	int		close;
	void	*wall;
	int		width;
	int		height;
	int		nb_dollars;
	int		nb_move;
}				t_map;

int		ft_check_file(char *filename);
int		ft_nb_lines_of_map(char *filename);
char	**ft_get_map(char *map_name, int nb_line);
void	ft_check_element_map(char **map, int nb_line);
void	ft_map_is_surrounded_by_walls(char **map, int nb_lines);
void	ft_map_is_rectangular(t_map *data, int nb_lines);
void	ft_check_player(char **map, int nb_lines, t_map *data);
void	ft_check_collectible(char **map, int nb_lines, t_map *data);
void	ft_check_exit(char **map, int nb_lines, t_map *data);
void	ft_mlx(char **map, int nb_lines, t_map *data);
void	ft_xpm_file_to_image(t_map *data);
void	ft_print_message_error(char *str);
void	ft_put_image_to_window(t_map *data);
int		ft_add_image_to_window(t_map *data);
int		ft_key_hook(int keycode, t_map *data);
int		ft_move_left(t_map *data);
int		ft_move_right(t_map *data);
void	ft_put_image_to_window_p(t_map *data);
int		ft_move_down(t_map *data);
int		ft_move_up(t_map *data);
int		handl_keyrelease(t_map *data);
void	loop_images(t_map *data);
void	ft_free(t_map *data);
#endif