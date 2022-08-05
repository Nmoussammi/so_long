/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:18:43 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/30 11:38:49 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx(char **map, int nb_lines, t_map *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit (1);
	data->mlx_win = mlx_new_window(data->mlx, \
	(ft_strlen(map[0]) - 1) * IMG_SIZE, nb_lines * IMG_SIZE, "so_long");
	if (!data->mlx_win)
		exit(1);
}

void	ft_xpm_file_to_image(t_map *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, \
		"./images_mandatory/wall.XPM", &data->width, &data->height);
	data->background = mlx_xpm_file_to_image(data->mlx, \
		"./images_mandatory/ground.xpm", &data->width, &data->height);
	data->open_door = mlx_xpm_file_to_image(data->mlx, \
		"./images_mandatory/open_door.XPM", &data->width, &data->height);
	data->player = mlx_xpm_file_to_image(data->mlx, \
		"./images_mandatory/down.XPM", &data->width, &data->height);
	data->dollar_image = mlx_xpm_file_to_image(data->mlx, \
		"./images_mandatory/dollar1.XPM", &data->width, &data->height);
	data->player_left = mlx_xpm_file_to_image(data->mlx, \
		"./images_mandatory/left.xpm", &data->width, &data->height);
	data->player_right = mlx_xpm_file_to_image(data->mlx, \
		"./images_mandatory/right.xpm", &data->width, &data->height);
	data->player_up = mlx_xpm_file_to_image(data->mlx, \
		"./images_mandatory/up.xpm", &data->width, &data->height);
}

void	ft_put_image_to_window_p(t_map *data)
{
	if (data->map[data->i][data->j] == 'P')
	{
		if (data->player_pos == 0)
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
				data->player, data->w, IMG_SIZE * data->i);
		else if (data->player_pos == 1)
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
				data->player_up, data->w, IMG_SIZE * data->i);
		else if (data->player_pos == 2)
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
				data->player_left, data->w, IMG_SIZE * data->i);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
				data->player_right, data->w, IMG_SIZE * data->i);
	}
}

void	ft_put_image_to_window(t_map *data)
{
	if (data->map[data->i][data->j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->wall, data->w, IMG_SIZE * data->i);
	if (data->map[data->i][data->j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->background, data->w, IMG_SIZE * data->i);
	ft_put_image_to_window_p(data);
	if (data->map[data->i][data->j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->dollar_image, data->w, IMG_SIZE * data->i);
	if (data->map[data->i][data->j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->open_door, data->w, IMG_SIZE * data->i);
}

int	ft_add_image_to_window(t_map *data)
{
	data->width = IMG_SIZE;
	data->height = IMG_SIZE;
	data->i = 0;
	while (data->i < data->nb_lines)
	{
		data->j = 0;
		data->w = 0;
		while (data->j < ft_strlen(data->map[0]) - 1)
		{
			ft_put_image_to_window(data);
			data->j++;
			data->w += IMG_SIZE;
		}
		data->i++;
	}
	return (0);
}
