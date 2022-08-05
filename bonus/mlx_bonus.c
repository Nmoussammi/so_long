/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:37:57 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/25 18:22:52 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_mlx(char **map, int nb_lines, t_map *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit (1);
	data->mlx_win = mlx_new_window(data->mlx, \
	(ft_strlen(map[0]) - 1) * IMG_SIZE, nb_lines * IMG_SIZE, "so_long_bonus");
	if (!data->mlx_win)
		exit(1);
}

void	ft_xpm_file_to_image(t_map *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, \
		"./images_bonus/wall.XPM", &data->width, &data->height);
	data->background = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/ground.xpm", &data->width, &data->height);
	data->open_door = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/open_door.XPM", &data->width, &data->height);
	data->player = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/down.XPM", &data->width, &data->height);
	data->player_left = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/left.xpm", &data->width, &data->height);
	data->player_right = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/right.xpm", &data->width, &data->height);
	data->player_up = mlx_xpm_file_to_image(data->mlx, \
				"./images_bonus/up.xpm", &data->width, &data->height);
	ft_enemy_img(data);
	ft_dollar_img(data);
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
	if (data->map[data->i][data->j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->open_door, data->w, IMG_SIZE * data->i);
	ft_put_image_to_window_p(data);
	ft_put_img_dollar_bonus(data);
	ft_put_img_enemy_bonus(data);
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
		print_mouvement(data);
		ft_enemy(data);
	}
	return (0);
}
