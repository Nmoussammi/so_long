/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:10:49 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/24 16:27:07 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_up(t_map *data)
{
	if (data->map[data->position_i - 1][data->position_j] == '1' || \
	(data->map[data->position_i - 1][data->position_j] == 'E' && \
	data->dollar != data->nb_dollars))
		return (0);
	data->nb_move++;
	ft_printf("The Total Count of Movement = %d\n", data->nb_move);
	if (data->map[data->position_i - 1][data->position_j] == '0')
	{
		data->map[data->position_i][data->position_j] = '0';
		data->position_i--;
		data->map[data->position_i][data->position_j] = 'P';
	}
	else if (data->map[data->position_i - 1][data->position_j] == 'C')
	{
		data->map[data->position_i][data->position_j] = '0';
		data->position_i--;
		data->map[data->position_i][data->position_j] = 'P';
		data->nb_dollars++;
	}
	else if (data->map[data->position_i - 1][data->position_j] == 'E')
	{
		if (data->dollar == data->nb_dollars)
			ft_print_message_error("Bravo! You Win!");
	}
	return (0);
}

int	ft_move_down(t_map *data)
{
	if (data->map[data->position_i + 1][data->position_j] == '1' \
	|| (data->map[data->position_i + 1][data->position_j] == 'E' \
	&& data->dollar != data->nb_dollars))
		return (0);
	data->nb_move++;
	ft_printf("The Total Count of Movement = %d\n", data->nb_move);
	if (data->map[data->position_i + 1][data->position_j] == '0')
	{
		data->map[data->position_i][data->position_j] = '0';
		data->position_i++;
		data->map[data->position_i][data->position_j] = 'P';
	}
	else if (data->map[data->position_i + 1][data->position_j] == 'C')
	{
		data->map[data->position_i][data->position_j] = '0';
		data->position_i++;
		data->map[data->position_i][data->position_j] = 'P';
		data->nb_dollars++;
	}
	else if (data->map[data->position_i + 1][data->position_j] == 'E')
	{
		if (data->dollar == data->nb_dollars)
			ft_print_message_error("Bravo! You Win!");
	}
	return (0);
}

int	ft_move_right(t_map *data)
{
	if (data->map[data->position_i][data->position_j + 1] == '1' \
	|| (data->map[data->position_i][data->position_j + 1] == 'E' \
	&& data->dollar != data->nb_dollars))
		return (0);
	data->nb_move++;
	ft_printf("The Total Count of Movement = %d\n", data->nb_move);
	if (data->map[data->position_i][data->position_j + 1] == '0')
	{
		data->map[data->position_i][data->position_j] = '0';
		data->position_j++;
		data->map[data->position_i][data->position_j] = 'P';
	}
	else if (data->map[data->position_i][data->position_j + 1] == 'C')
	{
		data->map[data->position_i][data->position_j] = '0';
		data->position_j++;
		data->map[data->position_i][data->position_j] = 'P';
		data->nb_dollars++;
	}
	else if (data->map[data->position_i][data->position_j + 1] == 'E')
	{
		if (data->dollar == data->nb_dollars)
			ft_print_message_error("Bravo! You Win!");
	}
	return (0);
}

int	ft_move_left(t_map *data)
{
	if (data->map[data->position_i][data->position_j - 1] == '1' \
	|| (data->map[data->position_i][data->position_j - 1] == 'E' \
	&& data->dollar != data->nb_dollars))
		return (0);
	data->nb_move++;
	ft_printf("The Total Count of Movement = %d\n", data->nb_move);
	if (data->map[data->position_i][data->position_j - 1] == '0')
	{
		data->map[data->position_i][data->position_j] = '0';
		data->position_j--;
		data->map[data->position_i][data->position_j] = 'P';
	}
	else if (data->map[data->position_i][data->position_j - 1] == 'C')
	{
		data->map[data->position_i][data->position_j] = '0';
		data->position_j--;
		data->map[data->position_i][data->position_j] = 'P';
		data->nb_dollars++;
	}
	else if (data->map[data->position_i][data->position_j - 1] == 'E')
	{
		if (data->dollar == data->nb_dollars)
			ft_print_message_error("Bravo! You Win!");
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
