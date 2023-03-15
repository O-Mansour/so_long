/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clicks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:39:44 by omansour          #+#    #+#             */
/*   Updated: 2023/01/24 17:23:24 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	to_top(t_game_elts *elts)
{
	int	i;
	int	j;

	j = elts->p->x;
	i = elts->p->y;
	if (elts->map[i - 1][j] == '1')
		return ;
	else if (elts->map[i - 1][j] == 'E')
	{
		if (elts->rc == 0)
			exit (0);
	}
	else if (elts->map[i - 1][j] == 'C')
	{
		do_top(elts);
		elts->map[i][j] = '0';
		elts->rc -= 1;
	}
	else if (elts->map[i - 1][j] == '0')
		do_top(elts);
}

void	to_bottom(t_game_elts *elts)
{
	int		i;
	int		j;

	j = elts->p->x;
	i = elts->p->y;
	if (elts->map[i + 1][j] == '1')
		return ;
	else if (elts->map[i + 1][j] == 'E')
	{
		if (elts->rc == 0)
			exit (0);
	}
	else if (elts->map[i + 1][j] == 'C')
	{
		do_bottom(elts);
		elts->map[i][j] = '0';
		elts->rc -= 1;
	}
	else if (elts->map[i + 1][j] == '0')
		do_bottom(elts);
}

void	to_right(t_game_elts *elts)
{
	int		i;
	int		j;

	j = elts->p->x;
	i = elts->p->y;
	if (elts->map[i][j + 1] == '1')
		return ;
	else if (elts->map[i][j + 1] == 'E')
	{
		if (elts->rc == 0)
			exit (0);
	}
	else if (elts->map[i][j + 1] == 'C')
	{
		do_right(elts);
		elts->map[i][j] = '0';
		elts->rc -= 1;
	}
	else if (elts->map[i][j + 1] == '0')
		do_right(elts);
}

void	to_left(t_game_elts *elts)
{
	int		i;
	int		j;

	j = elts->p->x;
	i = elts->p->y;
	if (elts->map[i][j - 1] == '1')
		return ;
	else if (elts->map[i][j - 1] == 'E')
	{
		if (elts->rc == 0)
			exit (0);
	}
	else if (elts->map[i][j - 1] == 'C')
	{
		do_left(elts);
		elts->map[i][j] = '0';
		elts->rc -= 1;
	}
	else if (elts->map[i][j - 1] == '0')
		do_left(elts);
}

int	clicks(int key, void *p)
{
	char		*str;
	t_game_elts	*elts;

	elts = (t_game_elts *)p;
	if (key == 53 || (key > 122 && key < 127))
	{
		if (key == 53)
			exit(0);
		else if (key == 123)
			to_left(elts);
		else if (key == 124)
			to_right(elts);
		else if (key == 125)
			to_bottom(elts);
		else if (key == 126)
			to_top(elts);
		mlx_clear_window(elts->mlx, elts->win);
		manage_game(elts->mlx, elts->win, elts->map);
		str = ft_itoa(elts->moves);
		if (!str)
			exit(1);
		mlx_string_put(elts->mlx, elts->win, 15, 15, 0xFFFFFF, str);
		free(str);
	}
	return (0);
}
