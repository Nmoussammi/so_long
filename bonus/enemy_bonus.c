/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:37:31 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/25 18:41:22 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_enemy_img(t_map *data)
{
	data->enemy1 = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/enemy1.xpm", &data->width, &data->height);
	data->enemy2 = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/enemy2.xpm", &data->width, &data->height);
	data->enemy3 = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/enemy3.xpm", &data->width, &data->height);
	data->enemy4 = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/enemy4.xpm", &data->width, &data->height);
}

void	ft_put_img_enemy_bonus(t_map *data)
{
	static int	x;

	usleep(100);
	if (data->map[data->i][data->j] == 'R' && x % 4 == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->enemy1, \
			data->w, data->i * IMG_SIZE);
	if (data->map[data->i][data->j] == 'R' && x % 4 == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->enemy2, \
			data->w, data->i * IMG_SIZE);
	if (data->map[data->i][data->j] == 'R' && x % 4 == 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->enemy3, \
			data->w, data->i * IMG_SIZE);
	if (data->map[data->i][data->j] == 'R' && x % 4 == 3)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->enemy4, \
			data->w, data->i * IMG_SIZE);
	usleep(100);
	x++;
}

void	ft_move_enemy(int i, int j, t_map *data)
{
	int	x;	

	x = rand() % 2;
	if (x == 0)
		ft_enemy_left(data, i, j);
	if (x == 1)
		ft_enemy_right(data, i, j);
}

void	ft_enemy(t_map *data)
{
	int			i;
	int			j;
	static int	v;

	i = 0;
	v++;
	if (v == 10)
	{
		while (i < data->nb_lines)
		{
			j = 0;
			while (j < ft_strlen(data->map[i]) - 1)
			{
				if (data->map[i][j] == 'R')
					ft_move_enemy(i, j, data);
				j++;
			}
			i++;
		}
		v = 0;
	}
}
