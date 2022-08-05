/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:40:07 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/25 17:51:58 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	loop_images(t_map *data)
{
	mlx_loop_hook(data->mlx, &ft_add_image_to_window, data);
	mlx_hook(data->mlx_win, 2, 1L, &ft_key_hook, data);
	mlx_hook(data->mlx_win, 17, 1L, &ft_destroy_image, data);
	mlx_loop(data->mlx);
}
