/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:45:46 by omansour          #+#    #+#             */
/*   Updated: 2023/01/24 18:12:48 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_game_elts
{
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	char		**map;
	t_coords	*p;
	int			moves;
	int			rc;
}	t_game_elts;

char		**check_map(char *str);
void		show_error(int nb);
t_game_elts	*get_elts(char **map);
char		**map_reading(char *str);
int			check_frame(char **map);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
void		ft_free(char **map);
int			clicks(int key, void *param);
void		manage_game(void *mlx, void *win, char **map);
int			is_ber(char *str);
int			check_char(char **map);
int			check_path(char **map);
int			count_char(char **map, char c);
void		do_top(t_game_elts *elts);
void		do_bottom(t_game_elts *elts);
void		do_right(t_game_elts *elts);
void		do_left(t_game_elts *elts);
void		ft_putnbr_fd(int n, int fd);
t_coords	*get_coords(char **map, char c);

#endif
