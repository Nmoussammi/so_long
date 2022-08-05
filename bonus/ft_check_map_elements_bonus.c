/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_elements_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:38:26 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/25 15:53:50 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_element_map(char **map, int nb_line)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C' \
			&& map[i][j] != 'E' && map[i][j] != 'P' && \
			map[i][j] != 'R' && map[i][j] != '\n')
				ft_print_message_error("Error\n Invalid Element of map\n");
			j++;
		}
		i++;
	}
}

void	ft_check_player(char **map, int nb_lines, t_map *data)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (i < nb_lines)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'P')
			{
				player++;
				data->p_i = i;
				data->p_j = j;
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		ft_print_message_error("Error\n The Map must have one Player\n");
}

void	ft_check_collectible(char **map, int nb_lines, t_map *data)
{
	int	i;
	int	j;

	i = 0;
	data->dol = 0;
	while (i < nb_lines)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'C')
				data->dol++;
			j++;
		}
		i++;
	}
	if (data->dol == 0)
		ft_print_message_error("Error\n Collectable doesn't exist\n");
}

void	ft_check_exit(char **map, int nb_lines, t_map *data)
{
	int	i;
	int	j;

	i = 0;
	data->exit = 0;
	while (i < nb_lines)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'E')
				data->exit++;
			j++;
		}
		i++;
	}
	if (data->exit == 0)
		ft_print_message_error("Error\n Exit doesn't exist");
}

void	ft_check_enemy(char **map, int nb_lines, t_map *data)
{
	int	i;
	int	j;

	i = 0;
	data->enemy = 0;
	while (i < nb_lines)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'R')
				data->enemy++;
			j++;
		}
		i++;
	}
	if (data->enemy == 0)
		ft_print_message_error("Error\n Enemy doesn't exist");
}
