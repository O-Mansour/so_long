/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_fcts3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:14:40 by omansour          #+#    #+#             */
/*   Updated: 2023/01/24 08:01:39 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

t_coords	*get_coords(char **map, char c)
{
	int			i;
	int			j;
	t_coords	*ccoords;

	i = -1;
	ccoords = (t_coords *)malloc(sizeof(t_coords));
	if (!ccoords)
	{
		show_error(3);
		exit(1);
	}
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
			{
				ccoords->x = j;
				ccoords->y = i;
				return (ccoords);
			}
		}
	}
	return (NULL);
}

void	correct_path(char **map, int x, int y, int *ptr)
{
	if (map[y][x] == 'E')
	{
		ptr[0] += 1;
		map[y][x] = '1';
		return ;
	}
	else if (map[y][x] == 'C')
		ptr[1] += 1;
	else if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	correct_path(map, x + 1, y, ptr);
	correct_path(map, x - 1, y, ptr);
	correct_path(map, x, y - 1, ptr);
	correct_path(map, x, y + 1, ptr);
}

int	check_path(char **map)
{
	int			*ptr;
	int			rc;
	t_coords	*start;

	ptr = malloc(sizeof(int) * 2);
	if (!ptr)
	{
		show_error(3);
		return (1);
	}
	ptr[0] = 0;
	ptr[1] = 0;
	rc = count_char(map, 'C');
	start = get_coords(map, 'P');
	correct_path(map, start->x, start->y, ptr);
	free(start);
	if (ptr[0] != 1 || ptr[1] != rc)
	{
		free (ptr);
		show_error(13);
		return (1);
	}
	free (ptr);
	return (0);
}
