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

static int	player_moves(t_game *game, int new_y, int new_x)
{
	if (game->map[new_y][new_x] == 'E' && game->collectables == 0)
		return (2);
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
	int			result;

	result = 0;
	if (!moves)
		moves = 0;
	if (keycode == 65307)
		handle_exit(game);
	else if (keycode == 119)
		result = player_moves(game, game->player_y - 1, game->player_x);
	else if (keycode == 97)
		result = player_moves(game, game->player_y, game->player_x - 1);
	else if (keycode == 115)
		result = player_moves(game, game->player_y + 1, game->player_x);
	else if (keycode == 100)
		result = player_moves(game, game->player_y, game->player_x + 1);
	if (result == 1 || result == 2)
	{
		ft_printf("%i\n", ++moves);
		game_render(game);
		if (result == 2)
			handle_exit(game);
	}
	return (0);
}
