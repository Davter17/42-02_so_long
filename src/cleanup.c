/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:03:25 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/04/09 19:03:25 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	cleanup_images(t_game *game)
{
	if (game->img_collectable)
		mlx_destroy_image(game->mlx, game->img_collectable);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
}

void	init_images_null(t_game *game)
{
	game->img_floor = NULL;
	game->img_wall = NULL;
	game->img_collectable = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
}
