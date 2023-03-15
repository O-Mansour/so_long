/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_fcts2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:51:17 by omansour          #+#    #+#             */
/*   Updated: 2023/01/24 17:51:03 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	same_length(char **map)
{
	int	i;
	int	length;

	i = 1;
	length = ft_strlen(map[0]);
	while (map[i])
	{
		if (length != (int)ft_strlen(map[i]))
			return (0);
		i++;
	}
	if (i < 3)
	{
		show_error(14);
		return (0);
	}
	return (length);
}

int	check_frame(char **map)
{
	int	i;
	int	length;
	int	lines;

	i = 0;
	length = same_length(map);
	if (length == 0)
		return (show_error(15), 1);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][length - 1] != '1')
			return (show_error(15), 1);
		i++;
	}
	lines = i;
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[lines - 1][i] != '1')
			return (show_error(15), 1);
		i++;
	}
	return (0);
}

int	count_char(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_char(char **map)
{
	int	c;
	int	p;
	int	e;
	int	k;

	c = -1;
	p = 0;
	e = 0;
	while (map[++c])
	{
		p = -1;
		while (map[c][++p])
			if (map[c][p] != '0' && map[c][p] != '1' && map[c][p] != 'C'
				&& map[c][p] != 'E' && map[c][p] != 'P')
				k = 100;
	}
	c = count_char(map, 'C');
	p = count_char(map, 'P');
	e = count_char(map, 'E');
	if (c == 0 || p != 1 || e != 1 || k == 100)
	{
		show_error(12);
		return (1);
	}
	return (0);
}
