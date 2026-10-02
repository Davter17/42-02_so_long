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

int	handle_exit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game)
	{
		if (game->map)
			ft_matrix_free(&game->map);
		if (game->mlx)
		{
			if (game->win)
				mlx_destroy_window(game->mlx, game->win);
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
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
	}
	exit(0);
}

void	map_main(char *map_name, t_game *game)
{
	if (map_reader(map_name, game) == 0)
	{
		ft_printf("Error\n");
		free(game);
		exit(1);
	}
	if (!map_validate(game))
	{
		ft_matrix_free(&game->map);
		free(game);
		exit(1);
	}
	if (!map_checker(game))
	{
		ft_matrix_free(&game->map);
		free(game);
		exit(1);
	}
}

static int	handle_close(void)
{
	exit(0);
	return (0);
}

static void	mlx_main(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_matrix_free(&game->map);
		free(game);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx,
			game->width * 64, game->height * 64, "so_long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_matrix_free(&game->map);
		free(game);
		exit(1);
	}
	game->img_floor = NULL;
	game->img_wall = NULL;
	game->img_collectable = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	load_images(game);
	game_render(game);
	mlx_key_hook(game->win, handle_key, game);
	mlx_hook(game->win, 17, 0, handle_close, NULL);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (1);
	game = malloc(sizeof(t_game));
	map_main(argv[1], game);
	mlx_main(game);
	return (0);
}
