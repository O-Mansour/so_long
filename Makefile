# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omansour <omansour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 21:55:42 by omansour          #+#    #+#              #
#    Updated: 2023/01/24 18:00:37 by omansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	so_long.c show_error.c\
				check_map/check_map.c check_map/check_map_fcts1.c check_map/check_map_fcts2.c check_map/check_map_fcts3.c\
				game/clicks.c game/clicks_fcts.c game/get_elts.c game/manage_game.c

SRC_B		=	bonus/so_long_bonus.c bonus/show_error_bonus.c\
				bonus/check_map_bonus/check_map_bonus.c bonus/check_map_bonus/check_map_fcts1_bonus.c\
				bonus/check_map_bonus/check_map_fcts2_bonus.c bonus/check_map_bonus/check_map_fcts3_bonus.c\
				bonus/game_bonus/clicks_bonus.c bonus/game_bonus/clicks_fcts_bonus.c\
				bonus/game_bonus/get_elts_bonus.c bonus/game_bonus/manage_game_bonus.c

LIBFT		=	libft/libft.a

FLAGS		=	-Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit

OBJS		=	${SRC:.c=.o}

OBJS_B		=	${SRC_B:.c=.o}

NAME		=	so_long

NAME_B		=	bonus/so_long_bonus

CC			=	cc

RM			=	rm -rf

all : ${NAME}

${LIBFT} :
	cd libft && make re && cd ..

${NAME} : ${LIBFT} ${OBJS}
	${CC} ${FLAGS} ${LIBFT} ${OBJS} -o ${NAME}

bonus : ${LIBFT} ${OBJS_B}
	${CC} ${FLAGS} ${LIBFT} ${OBJS_B} -o ${NAME_B}

clean :
	${RM} ${OBJS} ${OBJS_B}
	cd libft && make clean && cd ..

fclean : clean
	${RM} ${NAME} ${NAME_B} ${LIBFT}

re : fclean all
