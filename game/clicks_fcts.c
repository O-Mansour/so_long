/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clicks_fcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:47:46 by omansour          #+#    #+#             */
/*   Updated: 2023/01/21 03:25:29 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_swap(char *a, char *b)
{
	int	i;

	i = *a;
	*a = *b;
	*b = i;
}

void	do_top(t_game_elts *elts)
{
	ft_swap(&elts->map[elts->p->y - 1][elts->p->x],
		&elts->map[elts->p->y][elts->p->x]);
	elts->p->y -= 1;
	elts->moves += 1;
	ft_putnbr_fd(elts->moves, 1);
	write(1, "\n", 1);
}

void	do_bottom(t_game_elts *elts)
{
	ft_swap(&elts->map[elts->p->y + 1][elts->p->x],
		&elts->map[elts->p->y][elts->p->x]);
	elts->p->y += 1;
	elts->moves += 1;
	ft_putnbr_fd(elts->moves, 1);
	write(1, "\n", 1);
}

void	do_right(t_game_elts *elts)
{
	ft_swap(&elts->map[elts->p->y][elts->p->x + 1],
		&elts->map[elts->p->y][elts->p->x]);
	elts->p->x += 1;
	elts->moves += 1;
	ft_putnbr_fd(elts->moves, 1);
	write(1, "\n", 1);
}

void	do_left(t_game_elts *elts)
{
	ft_swap(&elts->map[elts->p->y][elts->p->x - 1],
		&elts->map[elts->p->y][elts->p->x]);
	elts->p->x -= 1;
	elts->moves += 1;
	ft_putnbr_fd(elts->moves, 1);
	write(1, "\n", 1);
}
