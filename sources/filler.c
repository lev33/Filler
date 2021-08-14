/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:49:46 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/05/13 23:11:18 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**  get token memory
**  read token sizes
**  get map memory and read token map
*/

static int		get_token(t_game *game)
{
	char	*line;
	int		y;

	if (!(game->token = (t_token *)ft_memalloc(sizeof(t_token))))
		return (0);
	line = NULL;
	if (get_next_line(0, &line) != 1 || !ft_strnequ(line, "Piece", 5))
	{
		ft_strdel(&line);
		return (0);
	}
	game->token->height = ft_atoi(line + 6);
	game->token->width = (game->token->height > 9) ? ft_atoi(line + 9)
															: ft_atoi(line + 8);
	ft_strdel(&line);
	if (!(game->token->map = (char**)ft_memalloc(sizeof(char*)
														* game->token->height)))
		return (0);
	y = -1;
	while (++y < game->token->height)
		if (get_next_line(0, &(game->token->map[y])) != 1)
			return (0);
	return (1);
}

static int		read_map_line(char *line, t_game *game, int y)
{
	int		x;

	x = -1;
	while (++x < game->map_width)
		if (line[x] == '.')
			game->map[y][x] = 0;
		else if (ft_toupper(line[x]) == game->player)
			game->map[y][x] = -1;
		else if (ft_toupper(line[x]) == game->challenger)
			game->map[y][x] = -2;
		else
			return (0);
	return (1);
}

static int		read_map(t_game *game)
{
	int		y;
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) != 1)
	{
		ft_strdel(&line);
		return (0);
	}
	ft_strdel(&line);
	y = -1;
	while (++y < game->map_height)
	{
		if (get_next_line(0, &line) != 1 || !read_map_line(&line[4], game, y))
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	return (1);
}

static int		read_map_size(t_game *game)
{
	char	*line;
	int		**map;
	int		y;

	if (get_next_line(0, &line) != 1 || !ft_strnequ(line, "Plateau", 7))
	{
		ft_strdel(&line);
		return (0);
	}
	game->map_height = ft_atoi(line + 8);
	game->map_width = (game->map_height > 99) ? ft_atoi(line + 12)
														: ft_atoi(line + 11);
	ft_strdel(&line);
	y = -1;
	if ((map = (int **)ft_memalloc(sizeof(int *) * game->map_height)))
		while (++y < game->map_height)
			if (!(map[y] = (int *)ft_memalloc(sizeof(int) * game->map_width)))
			{
				while (--y >= 0)
					free(map[y]);
				free(map);
				return (0);
			}
	game->map = map;
	return (1);
}

int				main(void)
{
	t_game		*game;
	char		*line;

	line = NULL;
	if (!(game = (t_game *)ft_memalloc(sizeof(t_game))))
		return (1);
	if (get_next_line(0, &line) != 1 || (!ft_strnequ(line, "$$$ exec p1", 11)
				&& !ft_strnequ(line, "$$$ exec p2", 11)))
	{
		free(game);
		ft_strdel(&line);
		return (1);
	}
	game->player = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
	game->challenger = (ft_atoi(line + 10) == 1) ? 'X' : 'O';
	ft_strdel(&line);
	if (!read_map_size(game) || !read_map(game) || !get_token(game))
		return (1);
	place_token(game);
	while (get_next_line(0, &line) == 1 && read_map(game) && get_token(game))
	{
		ft_strdel(&line);
		place_token(game);
	}
	return (0);
}
