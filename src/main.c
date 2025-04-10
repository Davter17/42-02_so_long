/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:42:25 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/04/09 19:03:25 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		collectables;
	//void	*mlx

	if (argc != 2)
		return (1);
	map = map_reader(argv[1]);
	if (!map)
		return (1);
	collectables = map_validate(map);;
	if (collectables == 0)
		return (ft_matrix_free(map), 1);
	if (!map_checker(map, collectables))
		return (ft_matrix_free(map), 1);
	ft_matrix_free(map);
	return (0);
	
	//mlx = mlx_init();
	//mlx_loop_hook(mlx, mi_funcion_loop, );
	
}
