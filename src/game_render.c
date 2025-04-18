/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:59:12 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/04/09 18:23:33 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	put_image(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_wall, j * 64, i * 64);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_player, j * 64, i * 64);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_collectable, j * 64, i * 64);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_exit, j * 64, i * 64);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_floor, j * 64, i * 64);
}

void	game_render(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_image(game, i, j);
			j++;
		}
		i++;
	}
}
