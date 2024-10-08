/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:04:30 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/20 18:10:58 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(t_data *data, t_map *map, char *map_path)
{
	map_folder(map_path, map);
	file_checker(map_path, map);
	map_extension(map_path, map);
	map_count_lines(map, map_path);
	map_to_struct(map, map_path);
	map_shape(map);
	map_resources(map);
	player_coord(map, map->player);
	exit_coord(map);
	final_map_verification(map);
	mlx_window(data, map);
}

void	map_shape(t_map *map)
{
	int		i;
	int		line_size;
	int		read_line;

	line_size = ft_strlen(map->full_map[0]);
	i = 0;
	while (i <= map->map_lines)
	{
		read_line = ft_strlen(map->full_map[i]);
		if (map->full_map[i][line_size - 1] != '\n')
			line_size -= 1;
		if (read_line != line_size)
			print_error("Error!\nMap_shape.", map);
		i++;
	}
}

void	map_count_lines(t_map *map, char *map_path)
{
	int		fd;
	char	*line;

	map->map_lines = -1;
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map->map_lines += 1;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}

void	map_to_struct(t_map *map, char *map_path)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		print_error("Error!\nInvalid map.", map);
	}
	map->map_columns = (ft_strlen(line) - 2);
	map->full_map = ft_calloc(sizeof(char *), map->map_lines + 1);
	map->flooded_map = ft_calloc(sizeof(char *), map->map_lines + 1);
	i = 0;
	while (line)
	{
		map->full_map[i] = ft_strdup(line);
		map->flooded_map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
}
