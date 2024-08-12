/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42poto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:37:31 by rde-fari          #+#    #+#             */
/*   Updated: 2024/08/12 19:52:32 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str, t_map *map)
{
	ft_printf("\n░░░░▒▒▒▒▓▓▓▓███████╣ ❌ ╠███████▓▓▓▓▒▒▒▒░░░░\n");
	ft_putendl_fd(str, 1);
	ft_printf("░░░░▒▒▒▒▓▓▓▓████████████████████▓▓▓▓▒▒▒▒░░░░\n");
	mem_clear(map);
	exit (1);
}

int	main(int argc, char *argv[])
{
	t_map		*map;

	map = ft_calloc(sizeof(t_map), 1);
	map->player = ft_calloc(sizeof(t_player), 1);
	if (argv[1] == NULL)
		print_error("Erro!\nInvalid path.", map);
	if (argc != 2)
		print_error("Erro!\nInvalid arguments quantity!", map);
	map_checker(map, argv[1]);
	mem_clear(map);
	return (0);
}
