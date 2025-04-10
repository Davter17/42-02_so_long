/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:31:01 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/04/09 16:07:21 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static bool	player_moves(t_game *game, int new_y, int new_x)
{	
	ft_printf("Collectables: %i\n", game->collectables);
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectables == 0)
			exit (0);
	}
	if (game->map[new_y][new_x] == 'C')
		game->collectables--;
	if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[new_y][new_x] = 'P';
		game->player_y = new_y;
		game->player_x = new_x;
	}
	else
		return (0);	
	return (1);
}

int	handle_key(int keycode, t_game *game)
{
	static int	moves;
	bool		move;

	move = 0;
	if (!moves)
		moves = 0;
	if (keycode == 65307)
		exit (0);
	else if (keycode == 119)
		move = player_moves(game, game->player_y - 1, game->player_x);
	else if (keycode == 97)
		move = player_moves(game, game->player_y, game->player_x - 1);
	else if (keycode == 115)
		move = player_moves(game, game->player_y + 1, game->player_x);
	else if (keycode == 100)
		move = player_moves(game, game->player_y, game->player_x + 1);
	if (move)
	{
		ft_printf("%i\n", ++moves);
		game_render(game);
	}
	return (0);
}
