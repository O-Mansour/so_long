/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:45:41 by omansour          #+#    #+#             */
/*   Updated: 2023/01/24 15:50:56 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	leave_fct(void *param)
{
	exit (0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game_elts	*elts;
	char		**map;

	if (argc != 2)
	{
		show_error(1);
		return (0);
	}
	map = check_map(argv[1]);
	elts = get_elts(map);
	elts->mlx = mlx_init();
	if (!elts->mlx)
		return (0);
	elts->win = mlx_new_window(elts->mlx, elts->width * 50,
			elts->height * 50, "so_long");
	if (!elts->win)
		return (0);
	manage_game(elts->mlx, elts->win, elts->map);
	mlx_hook(elts->win, 2, 0, &clicks, elts);
	mlx_hook(elts->win, 17, 0, &leave_fct, elts);
	mlx_loop(elts->mlx);
	return (0);
}
