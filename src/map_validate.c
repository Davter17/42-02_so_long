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

static int	validate_square(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
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
	return (--len);
}

static bool	validate_limits(char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j <= len)
		{
			if ((i == 0 || j == 0 || j == len) && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	i--;
	j = 0;
	while (j < len)
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	i++;
	return (1);
}

int	map_validate(char **map)
{
	int			len;
	int			collectables;

	len = validate_square(map);
	
	if (!len)
		return (ft_printf("Error\n"), 0);
	if (!validate_limits(map, len - 1))
		return (ft_printf("Error\n"), 0);
	collectables = validate_chars(map, false, false, 0);
	if (collectables == 0)
		return (ft_printf("Error\n"), 0);
	return (collectables);
}
