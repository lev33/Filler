/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:50:40 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/05/13 22:57:42 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_weight(t_game *game, t_token *token, int y, int x)
{
	int	j;
	int	i;
	int	weight;
	int	counter;

	weight = 0;
	counter = 0;
	j = -1;
	while (++j < game->token->height)
	{
		i = -1;
		while (++i < token->width)
			if (game->token->map[j][i] == '*')
			{
				if ((y + j) < 0 || (y + j) >= game->map_height
						|| (x + i) < 0 || (x + i) >= game->map_width
						|| game->map[y + j][x + i] == -2)
					return (-1);
				if (game->map[y + j][x + i] == -1)
					counter++;
				weight += game->map[y + j][x + i];
			}
	}
	return ((counter == 1) ? weight : -1);
}

static void		get_token_place(t_game *game)
{
	int	j;
	int	i;
	int	weight;
	int	min;

	min = game->map_height * game->map_width * game->map_width;
	j = -1 - game->token->height;
	while (++j < game->map_height)
	{
		i = -1 - game->token->width;
		while (++i < game->map_width)
		{
			weight = get_weight(game, game->token, j, i);
			if (weight != -1 && weight < min)
			{
				game->y = j;
				game->x = i;
				min = weight;
			}
		}
	}
}

static int		get_value(t_game *game, int x, int y)
{
	int	j;
	int	i;
	int	val;
	int	min;

	min = game->map_height + game->map_width;
	j = -1;
	while (++j < game->map_height)
	{
		i = -1;
		while (++i < game->map_width)
		{
			if (game->map[j][i] == -2)
			{
				val = (i > x) ? i - x : x - i;
				val += (j > y) ? j - y : y - j;
				if (val < min)
					min = val;
			}
		}
	}
	return (min);
}

/*
**  fill map (get values for empty cells)
**  get_token_place()
**  free token map memory and token memory
**  print token place
*/

void			place_token(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
			if (game->map[y][x] == 0)
				game->map[y][x] = get_value(game, x, y);
	}
	get_token_place(game);
	y = -1;
	while (++y < game->token->height)
		free(game->token->map[y]);
	free(game->token->map);
	free(game->token);
	ft_putnbr(game->y);
	ft_putchar(' ');
	ft_putnbr(game->x);
	ft_putchar('\n');
	game->y = 0;
	game->x = 0;
}
