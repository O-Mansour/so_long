/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:53:25 by omansour          #+#    #+#             */
/*   Updated: 2023/01/21 03:25:39 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_lines(char **map)
{
	int	lines;

	lines = 0;
	while (map[lines])
		lines++;
	return (lines);
}

t_game_elts	*get_elts(char **map)
{
	t_game_elts	*elts;

	elts = (t_game_elts *)malloc(sizeof(t_game_elts));
	if (!elts)
	{
		show_error(3);
		exit (1);
	}
	elts->map = map;
	elts->width = ft_strlen(map[0]);
	elts->height = get_lines(map);
	elts->moves = 0;
	elts->p = get_coords(map, 'P');
	elts->rc = count_char(map, 'C');
	return (elts);
}
