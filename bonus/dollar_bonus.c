/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:47:39 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/30 11:32:21 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_dollar_img(t_map *data)
{
	data->dollar1 = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/dollar1.xpm", &data->width, &data->height);
	data->dollar2 = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/dollar2.xpm", &data->width, &data->height);
	data->dollar3 = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/dollar3.xpm", &data->width, &data->height);
	data->dollar4 = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/dollar4.xpm", &data->width, &data->height);
}

void	ft_put_img_dollar_bonus(t_map *data)
{
	static int	x;

	usleep(100);
	if (data->map[data->i][data->j] == 'C' && x % 4 == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dollar1, \
			data->w, data->i * IMG_SIZE);
	if (data->map[data->i][data->j] == 'C' && x % 4 == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dollar2, \
			data->w, data->i * IMG_SIZE);
	if (data->map[data->i][data->j] == 'C' && x % 4 == 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dollar3, \
			data->w, data->i * IMG_SIZE);
	if (data->map[data->i][data->j] == 'C' && x % 4 == 3)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dollar4, \
			data->w, data->i * IMG_SIZE);
	usleep(100);
	x++;
}
