/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:51:09 by ligeorgi          #+#    #+#             */
/*   Updated: 2020/05/13 22:52:33 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_token
{
	int			height;
	int			width;
	char		**map;
}				t_token;

typedef struct	s_game
{
	char		player;
	char		challenger;
	int			map_height;
	int			map_width;
	int			**map;
	t_token		*token;
	int			y;
	int			x;
}				t_game;

void			place_token(t_game *game);

#endif
