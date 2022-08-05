/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:09:19 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/25 17:57:34 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_destroy_image(t_map *data)
{
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->player_left);
	mlx_destroy_image(data->mlx, data->player_right);
	mlx_destroy_image(data->mlx, data->player_up);
	mlx_destroy_image(data->mlx, data->background);
	mlx_destroy_image(data->mlx, data->open_door);
	mlx_destroy_image(data->mlx, data->dollar1);
	mlx_destroy_image(data->mlx, data->dollar2);
	mlx_destroy_image(data->mlx, data->dollar3);
	mlx_destroy_image(data->mlx, data->dollar4);
	mlx_destroy_image(data->mlx, data->enemy1);
	mlx_destroy_image(data->mlx, data->enemy2);
	mlx_destroy_image(data->mlx, data->enemy3);
	mlx_destroy_image(data->mlx, data->enemy4);
	mlx_destroy_window(data->mlx, data->mlx_win);
	data->mlx_win = NULL;
	exit(0);
}
