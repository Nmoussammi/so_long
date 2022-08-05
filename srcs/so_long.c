/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:17:04 by nmoussam          #+#    #+#             */
/*   Updated: 2022/08/05 17:03:21 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*data;

	data = malloc(sizeof(t_map));
	data->nb_move = 0;
	data->player_pos = 0;
	if (argc != 2)
		ft_print_message_error("Error\nInvalide number of arguments");
	if (ft_check_file(argv[1]) == 0)
		ft_print_message_error("Error\nThe map filename is invalid.");
	data->nb_lines = ft_nb_lines_of_map(argv[1]);
	data->map = ft_get_map(argv[1], data->nb_lines);
	ft_map_is_surrounded_by_walls(data->map, data->nb_lines);
	ft_map_is_rectangular(data, data->nb_lines);
	ft_check_element_map(data->map, data->nb_lines);
	ft_check_player(data->map, data->nb_lines, data);
	ft_check_collectible(data->map, data->nb_lines, data);
	ft_check_exit(data->map, data->nb_lines, data);
	ft_mlx(data->map, data->nb_lines, data);
	ft_xpm_file_to_image(data);
	ft_add_image_to_window(data);
	loop_images(data);
	ft_free(data);

	return (0);
}
