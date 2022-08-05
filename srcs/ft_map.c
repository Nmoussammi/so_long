/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:00:42 by nmoussam          #+#    #+#             */
/*   Updated: 2022/05/30 11:19:01 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_nb_lines_of_map(char *filename)
{
	int		fd;
	char	*line;
	int		nb_line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_print_message_error("Error\n can't open File descriptor\n");
	line = get_next_line(fd);
	if (!line)
		ft_print_message_error("Error\n Empty Map\n");
	free(line);
	nb_line = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		nb_line++;
	}
	close(fd);
	return (nb_line);
}

char	**ft_get_map(char *file_name, int nb_line)
{
	char	**map;
	int		fd;
	int		i;

	map = (char **)malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = -1;
	while (++i < nb_line)
		map[i] = get_next_line(fd);
	close(fd);
	return (map);
}

void	ft_map_is_surrounded_by_walls(char **map, int nb_lines)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	while (map[0][j] != '\n' && map[nb_lines - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[nb_lines - 1][j] != '1')
			ft_print_message_error("Error\n \
The map is not surrounded by walls\n");
		j++;
	}
	len = ft_strlen(map[0]);
	i = 0;
	while (i < nb_lines)
	{
		if (map[i][0] != '1' || map[i][len - 2] != '1')
			ft_print_message_error("Error\n \
The map is not surrounded by walls\n");
			i++;
	}
}

void	ft_map_is_rectangular(t_map *data, int nb_lines)
{
	int	i;

	i = 0;
	while (i < nb_lines - 2)
	{
		if (ft_strlen(data->map[i]) != ft_strlen(data->map[i + 1]) || \
ft_strlen(data->map[nb_lines - 1]) != ft_strlen(data->map[nb_lines - 2]) - 1)
			ft_print_message_error("Error\n The map isn't Rectangular\n");
		i++;
	}
}
