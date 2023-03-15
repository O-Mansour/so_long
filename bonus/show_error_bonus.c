/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:56:20 by omansour          #+#    #+#             */
/*   Updated: 2023/01/24 17:50:10 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	show_error(int nb)
{
	if (nb == 1)
		write(1, "Error\nThe number of arguments isn't correct.\n", 45);
	else if (nb == 2)
		write(1, "Error\nThe open() function failed.\n", 34);
	else if (nb == 3)
		write(1, "Error\nThe malloc() function failed.\n", 36);
	else if (nb == 4)
		write(1, "Error\nThe read() function failed.\n", 34);
	else if (nb == 10)
		write(1, "Error\nThe extension (.ber) isn't correct.\n", 42);
	else if (nb == 11)
		write(1, "Error\nUnexpected new line in the map.\n", 38);
	else if (nb == 12)
		write(1, "Error\n1 exit, 1 start & collectibles just needed.\n", 45);
	else if (nb == 13)
		write(1, "Error\nCan't exit or to take all the collectibles.\n", 50);
	else if (nb == 14)
		write(1, "Error\nLess than 2 lines in the map.\n", 36);
	else if (nb == 15)
		write(1, "Error\nThe frame isn't correct.\n", 31);
}
