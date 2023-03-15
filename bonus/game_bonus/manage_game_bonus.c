/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:08:27 by omansour          #+#    #+#             */
/*   Updated: 2023/01/24 15:52:10 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*what_img(char c)
{
	if (c == 'C')
		return ("textures_bonus/c1.xpm");
	else if (c == 'E')
		return ("textures_bonus/e.xpm");
	else if (c == 'P')
		return ("textures_bonus/p.xpm");
	else if (c == '0')
		return ("textures_bonus/zero.xpm");
	else if (c == '1')
		return ("textures_bonus/one.xpm");
	return (NULL);
}

void	set_image(void *mlx, void *win, char c, t_coords *xy)
{
	char	*img_path;
	void	*img_ptr;
	int		wh;

	img_path = what_img(c);
	img_ptr = mlx_xpm_file_to_image(mlx, img_path, &wh, &wh);
	if (!img_ptr)
		exit(1);
	mlx_put_image_to_window(mlx, win, img_ptr, xy->x * 50, xy->y * 50);
	mlx_destroy_image(mlx, img_ptr);
}

void	manage_game(void *mlx, void *win, char **map)
{
	int			i;
	int			j;
	t_coords	*xy;

	i = 0;
	xy = (t_coords *)malloc(sizeof(t_coords));
	if (!xy)
	{
		show_error(3);
		exit (1);
	}
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			xy->x = j;
			xy->y = i;
			set_image(mlx, win, map[i][j], xy);
			j++;
		}
		i++;
	}
	free(xy);
}
