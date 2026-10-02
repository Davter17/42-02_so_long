/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:54:23 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/04/09 18:23:33 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_images(t_game *game)
{
	int	x;
	int	y;

	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &x, &y);
	if (!game->img_floor)
		handle_exit(game);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &x, &y);
	if (!game->img_wall)
		handle_exit(game);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx,
			"textures/collectable.xpm", &x, &y);
	if (!game->img_collectable)
		handle_exit(game);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &x, &y);
	if (!game->img_player)
		handle_exit(game);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &x, &y);
	if (!game->img_exit)
		handle_exit(game);
}
