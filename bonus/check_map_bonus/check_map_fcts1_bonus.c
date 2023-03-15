/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_fcts1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:03:34 by omansour          #+#    #+#             */
/*   Updated: 2023/01/24 08:01:13 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	free (s1);
	return (p);
}

int	is_ber(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.' || !str[i - 4] || str[i - 4] == '/')
	{
		show_error(10);
		return (1);
	}
	return (0);
}

char	**split_by_nl(char *data)
{
	char	**map;
	int		i;

	i = 0;
	if (data[0] == '\n' || data[ft_strlen(data) - 1] == '\n')
	{
		show_error(11);
		free (data);
		return (NULL);
	}
	while (data[++i])
	{
		if (data[i] == '\n')
		{
			if (data[i + 1] == '\n')
			{
				show_error(11);
				free (data);
				return (NULL);
			}
		}
	}
	map = ft_split(data, '\n');
	free(data);
	return (map);
}

char	*ret_data(int fd, char **data)
{
	int		n;
	char	*cpy;

	n = 1;
	cpy = malloc(sizeof(char) * 11);
	if (!cpy)
	{
		show_error(3);
		return (NULL);
	}
	while (n > 0 && *data)
	{
		n = read(fd, cpy, 10);
		if (n == -1)
		{
			show_error(4);
			return (NULL);
		}
		cpy[n] = '\0';
		*data = ft_strjoin(*data, cpy);
		if (!*data)
			show_error(3);
	}
	free(cpy);
	return (*data);
}

char	**map_reading(char *str)
{
	int		fd;
	char	*data;
	char	**map;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		show_error(2);
		return (NULL);
	}
	data = malloc(sizeof(char));
	if (!data)
	{
		show_error(3);
		return (NULL);
	}
	data[0] = '\0';
	data = ret_data(fd, &data);
	if (!data)
		return (NULL);
	close (fd);
	map = split_by_nl(data);
	return (map);
}
