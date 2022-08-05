/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:04:24 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/24 20:44:21 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_enemy_right(t_map *data, int i, int j)
{
	if (data->map[i][j + 1] == 'P')
		ft_print_message_error("Game Over :( You are die!\n");
	if (data->map[i][j + 1] == '0')
	{
		data->map[i][j++] = '0';
		data->map[i][j] = 'R';
	}
	return (0);
}

int	ft_enemy_up(t_map *data, int i, int j)
{
	if (data->map[i - 1][j] == 'P')
		ft_print_message_error("Game Over :( You are die!\n");
	if (data->map[i - 1][j] == '0')
	{
		data->map[i--][j] = '0';
		data->map[i][j] = 'R';
	}
	return (0);
}

int	ft_enemy_down(t_map *data, int i, int j)
{
	if (data->map[i + 1][j] == 'P')
		ft_print_message_error("Game Over :( You are die!\n");
	if (data->map[i + 1][j] == '0')
	{
		data->map[i++][j] = '0';
		data->map[i][j] = 'R';
	}
	return (0);
}

int	ft_enemy_left(t_map *data, int i, int j)
{
	if (data->map[i][j - 1] == 'P')
		ft_print_message_error("Game Over :( You are die!\n");
	if (data->map[i][j - 1] == '0')
	{
		data->map[i][j--] = '0';
		data->map[i][j] = 'R';
	}
	return (0);
}
