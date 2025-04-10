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

void	map_main(char *map_name, t_game *game)
{
	if (map_reader(map_name, game) == 0)
		exit (1);
	if (!map_validate(game))
	{
		free(game);
		exit (1);
	}
	if (!map_checker(game))
	{
		free(game);
		exit (1);
	}
}

static void	mlx_main(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return ;
	game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32, "so_long");
	if (!game->win)
		return ;
	load_images(game);
	game_render(game);
	mlx_key_hook(game->win, handle_key, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (argc != 2)
		return (1);
	map_main(argv[1], game);
	mlx_main(game);
	return (0);
}
