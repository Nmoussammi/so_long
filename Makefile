# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 02:06:32 by nmoussam          #+#    #+#              #
#    Updated: 2022/05/25 18:52:01 by nmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
INC = so_long.h
INC_BONUS = so_long_bonus.h
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
CFILES = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
		 ./ft_printf/ft_functions.c ./ft_printf/ft_functions2.c \
		 ./ft_printf/ft_printf.c \
		 ./srcs/ft_map.c ./srcs/ft_check_error.c ./srcs/ft_check_map_elements.c \
		 ./srcs/mlx.c ./srcs/mouvement.c ./srcs/mlx_loop.c \
		 ./srcs/so_long.c
CFILES_BONUS = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
		 ./ft_printf/ft_functions.c ./ft_printf/ft_functions2.c \
		 ./ft_printf/ft_printf.c \
		 ./bonus/ft_check_error_bonus.c \
		 ./bonus/ft_check_map_elements_bonus.c \
		 ./bonus/ft_map_bonus.c \
		 ./bonus/mlx_bonus.c \
 		 ./bonus/mlx_loop_bonus.c  \
		 ./bonus/mouvement_bonus.c \
		 ./bonus/so_long_bonus.c \
  		 ./bonus/dollar_bonus.c \
		 ./bonus/enemy_bonus.c \
		 ./bonus/ft_move_enemy.c  \
  		 ./bonus/ft_print_move.c \
		./bonus/utils_bonus.c  \
		 ./bonus/mlx_destroy.c

OFILES = $(CFILES:.c=.o)
OFILES_BONUS = $(CFILES_BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OFILES)
	$(CC) -lmlx -framework OpenGL -framework AppKit $^ -o $@
bonus : $(NAME_BONUS)
$(NAME_BONUS) : $(OFILES_BONUS)
	$(CC) -lmlx -framework OpenGL -framework AppKit $^ -o $@
	
%.o:%.c $(INC) $(INC_BONUS)
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	$(RM) $(OFILES) $(OFILES_BONUS)
	
fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	
re: fclean all