/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:50:18 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/04/09 19:03:41 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static t_position	*find_player(char **map)
{
	int	i;
	int	j;
	t_position	*player;
	
	i = 0;
	j = 0;
	player = malloc(sizeof(t_position));
	if (!player)
		return (NULL);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player->y = i;
				player->x = j;
				return (player);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

int	flood_fill(char **map, int y, int x)
{
	int			collectable;

	collectable = 0;
	if (map[y][x] == 'E' || map[y][x] == 'C')
		collectable++;
	map[y][x] = '1';
	if (map[y - 1][x] != '1')
		collectable += flood_fill(map, y - 1, x);
	if (map[y + 1][x] != '1')
		collectable += flood_fill(map, y + 1, x);
	if (map[y][x - 1] != '1')
		collectable += flood_fill(map, y, x - 1);
	if (map[y][x + 1] != '1')
		collectable += flood_fill(map, y, x + 1);
	return (collectable);
}

bool map_checker(char **map, int collectables)
{
	t_position	*player;
	char		**map2;
	int			reachables;

	map2 = ft_matrix_duplicate(map);
	player = find_player(map2);
	if (!player)
	{
		ft_matrix_free(map2);
		exit(1);
	}
	reachables = flood_fill(map2, player->y, player->x);
	free(player);
	ft_matrix_free(map2);
	if (reachables == collectables + 1);
		return (1);
	ft_printf("Error\n");
	exit (0);
}
