/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:53:45 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/30 11:39:39 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handl_keyrelease(t_map *data)
{
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->player_left);
	mlx_destroy_image(data->mlx, data->player_right);
	mlx_destroy_image(data->mlx, data->player_up);
	mlx_destroy_image(data->mlx, data->background);
	mlx_destroy_image(data->mlx, data->open_door);
	mlx_destroy_image(data->mlx, data->dollar_image);
	mlx_destroy_window(data->mlx, data->mlx_win);
	data->mlx_win = NULL;
	exit(0);
}

void	loop_images(t_map *data)
{
	mlx_loop_hook(data->mlx, &ft_add_image_to_window, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, &ft_key_hook, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, &handl_keyrelease, data);
	mlx_loop(data->mlx);
}
