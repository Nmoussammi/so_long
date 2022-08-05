/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:37:33 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/24 18:15:25 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_move_up(t_map *data)
{
	if (data->map[data->p_i - 1][data->p_j] == '1' || \
	(data->map[data->p_i - 1][data->p_j] == 'E' && data->dol != data->nb_dol))
		return (0);
	data->nb_move++;
	if (data->map[data->p_i - 1][data->p_j] == 'R')
		ft_print_message_error("Game Over :( You are die!\n");
	else if (data->map[data->p_i - 1][data->p_j] == '0')
	{
		data->map[data->p_i][data->p_j] = '0';
		data->p_i--;
		data->map[data->p_i][data->p_j] = 'P';
	}
	else if (data->map[data->p_i - 1][data->p_j] == 'C')
	{
		data->map[data->p_i][data->p_j] = '0';
		data->p_i--;
		data->map[data->p_i][data->p_j] = 'P';
		data->nb_dol++;
	}
	else if (data->map[data->p_i - 1][data->p_j] == 'E')
	{
		if (data->dol == data->nb_dol)
			ft_print_message_error("Good! You win :)");
	}
	return (0);
}

int	ft_move_down(t_map *data)
{
	if (data->map[data->p_i + 1][data->p_j] == '1' || (data->map[data->p_i + 1] \
		[data->p_j] == 'E' && data->dol != data->nb_dol))
		return (0);
	data->nb_move++;
	if (data->map[data->p_i + 1][data->p_j] == 'R')
		ft_print_message_error("Game Over :( You are die!\n");
	else if (data->map[data->p_i + 1][data->p_j] == '0')
	{
		data->map[data->p_i][data->p_j] = '0';
		data->p_i++;
		data->map[data->p_i][data->p_j] = 'P';
	}
	else if (data->map[data->p_i + 1][data->p_j] == 'C')
	{
		data->map[data->p_i][data->p_j] = '0';
		data->p_i++;
		data->map[data->p_i][data->p_j] = 'P';
		data->nb_dol++;
	}
	else if (data->map[data->p_i + 1][data->p_j] == 'E')
	{
		if (data->dol == data->nb_dol)
			ft_print_message_error("Good! You win :)");
	}
	return (0);
}

int	ft_move_right(t_map *data)
{
	if (data->map[data->p_i][data->p_j + 1] == '1' || (data->map[data->p_i] \
		[data->p_j + 1] == 'E' && data->dol != data->nb_dol))
		return (0);
	data->nb_move++;
	if (data->map[data->p_i][data->p_j + 1] == 'R')
		ft_print_message_error("Game Over :( You are die!\n");
	else if (data->map[data->p_i][data->p_j + 1] == '0')
	{
		data->map[data->p_i][data->p_j] = '0';
		data->p_j++;
		data->map[data->p_i][data->p_j] = 'P';
	}
	else if (data->map[data->p_i][data->p_j + 1] == 'C')
	{
		data->map[data->p_i][data->p_j] = '0';
		data->p_j++;
		data->map[data->p_i][data->p_j] = 'P';
		data->nb_dol++;
	}
	else if (data->map[data->p_i][data->p_j + 1] == 'E')
	{
		if (data->dol == data->nb_dol)
			ft_print_message_error("Good! You win :)");
	}
	return (0);
}

int	ft_move_left(t_map *data)
{
	if (data->map[data->p_i][data->p_j - 1] == '1' || (data->map[data->p_i] \
		[data->p_j - 1] == 'E' && data->dol != data->nb_dol))
		return (0);
	data->nb_move++;
	if (data->map[data->p_i][data->p_j - 1] == 'R')
		ft_print_message_error("Game Over :( You are die!\n");
	else if (data->map[data->p_i][data->p_j - 1] == '0')
	{
		data->map[data->p_i][data->p_j] = '0';
		data->p_j--;
		data->map[data->p_i][data->p_j] = 'P';
	}
	else if (data->map[data->p_i][data->p_j - 1] == 'C')
	{
		data->map[data->p_i][data->p_j] = '0';
		data->p_j--;
		data->map[data->p_i][data->p_j] = 'P';
		data->nb_dol++;
	}
	else if (data->map[data->p_i][data->p_j - 1] == 'E')
	{
		if (data->dol == data->nb_dol)
			ft_print_message_error("Good! You win :)");
	}
	return (0);
}

int	ft_key_hook(int keycode, t_map *data)
{
	if (keycode == 13 || keycode == 126)
	{
		data->player_pos = 1;
		ft_move_up(data);
	}
	if (keycode == 0 || keycode == 123)
	{
		data->player_pos = 2;
		ft_move_left(data);
	}
	if (keycode == 1 || keycode == 125)
	{
		data->player_pos = 0;
		ft_move_down(data);
	}
	if (keycode == 2 || keycode == 124)
	{
		data->player_pos = 3;
		ft_move_right(data);
	}
	if (keycode == 53)
		ft_free(data);
	return (0);
}
