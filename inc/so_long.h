/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:49:01 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/04/09 16:36:13 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <stdbool.h>

typedef struct s_position
{
	int	y;
	int	x;
}	t_position;

char	**map_reader(char *map_name);
int		map_validate(char **map);
bool	map_checker(char **map, int collectables);

#endif