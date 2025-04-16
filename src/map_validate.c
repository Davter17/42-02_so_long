/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 00:58:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/04/09 16:07:21 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static bool	validate_square(char **map, t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (i == 0)
			len = j;
		else if (j != len)
			return (0);
		i++;
	}
	game->width = len - 1;
	if (game->width > 60)
		return (0);
	game->height = i;
	if (game->height > 31)
		return (0);
	return (1);
}

static bool	validate_limits(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (j < game->width)
		{
			if ((i == 0 || j == 0 || j == game->width - 1)
				&& game->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	i--;
	j = 0;
	while (j < game->width)
	{
		if (game->map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	validate_chars(char **map, bool ini, bool exi, int collectables)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j + 1])
		{
			if (map[i][j] == 'C')
				collectables++;
			else if (map[i][j] == 'P' && !ini)
				ini = true;
			else if (map[i][j] == 'E' && !exi)
				exi = true;
			else if ((map[i][j] == 'E' && exi) || (map[i][j] == 'P' && ini)
					|| (map[i][j] != '0' && map[i][j] != '1'))
				return (0);
			j++;
		}
		i++;
	}
	if (exi && ini && collectables > 0)
		return (collectables);
	return (0);
}

bool	map_validate(t_game *game)
{
	if (!validate_square(game->map, game))
		return (ft_printf("Error\n"), 0);
	if (!validate_limits(game))
		return (ft_printf("Error\n"), 0);
	game->collectables = validate_chars(game->map, false, false, 0);
	if (game->collectables == 0)
		return (ft_printf("Error\n"), 0);
	return (1);
}
