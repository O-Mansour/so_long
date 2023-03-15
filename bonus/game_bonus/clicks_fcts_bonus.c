/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clicks_fcts_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:47:46 by omansour          #+#    #+#             */
/*   Updated: 2023/01/24 14:01:53 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_swap(char *a, char *b)
{
	int	i;

	i = *a;
	*a = *b;
	*b = i;
}

void	do_top(t_game_elts *elts)
{
	char	*str;

	ft_swap(&elts->map[elts->p->y - 1][elts->p->x],
		&elts->map[elts->p->y][elts->p->x]);
	elts->p->y -= 1;
	elts->moves += 1;
}

void	do_bottom(t_game_elts *elts)
{
	char	*str;

	ft_swap(&elts->map[elts->p->y + 1][elts->p->x],
		&elts->map[elts->p->y][elts->p->x]);
	elts->p->y += 1;
	elts->moves += 1;
}

void	do_right(t_game_elts *elts)
{
	char	*str;

	ft_swap(&elts->map[elts->p->y][elts->p->x + 1],
		&elts->map[elts->p->y][elts->p->x]);
	elts->p->x += 1;
	elts->moves += 1;
}

void	do_left(t_game_elts *elts)
{
	char	*str;

	ft_swap(&elts->map[elts->p->y][elts->p->x - 1],
		&elts->map[elts->p->y][elts->p->x]);
	elts->p->x -= 1;
	elts->moves += 1;
}
