/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:34:38 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/25 16:50:59 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	int		p_i;
	int		p_j;
	int		dol;
	void	*enemy1;
	void	*enemy2;
	void	*enemy3;
	void	*enemy4;
	void	*exit;
	int		dollar;
	void	*dollar1;
	void	*dollar2;
	void	*dollar3;
	void	*dollar4;
	void	*enemy;
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
	int		nb_dol;
	int		nb_move;
	char	*move;
	char	*string;
}				t_map;

int			ft_check_file(char *filename);
int			ft_nb_lines_of_map(char *filename);
char		**ft_get_map(char *map_name, int nb_line);
void		ft_check_element_map(char **map, int nb_line);
void		ft_map_is_surrounded_by_walls(char **map, int nb_lines);
void		ft_map_is_rectangular(t_map *data, int nb_lines);
void		ft_check_player(char **map, int nb_lines, t_map *data);
void		ft_check_collectible(char **map, int nb_lines, t_map *data);
void		ft_check_exit(char **map, int nb_lines, t_map *data);
void		ft_mlx(char **map, int nb_lines, t_map *data);
void		ft_xpm_file_to_image(t_map *data);
void		ft_print_message_error(char *str);
void		ft_put_image_to_window(t_map *data);
int			ft_add_image_to_window(t_map *data);
int			ft_key_hook(int keycode, t_map *data);
int			ft_move_left(t_map *data);
int			ft_move_right(t_map *data);
void		ft_put_image_to_window_p(t_map *data);
int			ft_move_down(t_map *data);
int			ft_move_up(t_map *data);
int			handl_keyrelease(t_map *data);
void		loop_images(t_map *data);
void		ft_free(t_map *data);
void		ft_check_enemy(char **map, int nb_lines, t_map *data);
void		ft_dollar_img(t_map *data);
void		ft_put_img_dollar_bonus(t_map *data);
void		ft_enemy_img(t_map *data);
void		ft_put_img_enemy_bonus(t_map *data);
int			ft_enemy_right(t_map *data, int i, int j);
int			ft_enemy_up(t_map *data, int i, int j);
int			ft_enemy_down(t_map *data, int i, int j);
int			ft_enemy_left(t_map *data, int i, int j);
void		print_mouvement(t_map *data);
char		*ft_itoa(int n);
static int	nbr_chr(long int n);
int			ft_destroy_image(t_map *data);
void		loop_images(t_map *data);
void		ft_move_enemy(int i, int j, t_map *data);
void		ft_enemy(t_map *data);
char		*ft_join(char *s1, char *s2);
void		*ft_memmove(void *dst, const void *src, int len);
void		*ft_memcpy(void *dst, const void *src, int n);
#endif