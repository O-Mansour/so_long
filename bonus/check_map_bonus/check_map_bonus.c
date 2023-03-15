/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:27:36 by omansour          #+#    #+#             */
/*   Updated: 2023/01/24 08:00:57 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**check_map(char *str)
{
	char	**map;

	if (is_ber(str))
		exit(1);
	map = map_reading(str);
	if (!map)
		exit(1);
	if (check_char(map) || check_frame(map) || check_path(map))
	{
		ft_free(map);
		exit(1);
	}
	ft_free(map);
	map = map_reading(str);
	if (!map)
		exit(1);
	return (map);
}
