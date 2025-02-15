# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 13:34:52 by fdiaz-gu          #+#    #+#              #
#    Updated: 2023/11/21 16:42:22 by fdiaz-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src
BONUS_DIR = ./bonus
SRC = check_args.c main.c push.c reverse_rotate.c rotate.c swap.c utils.c utils2.c utils3.c order.c order2.c utils4.c
BONUS = check_bonus.c checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c init_bonus.c list_bonus.c push_bonus.c reverse_rotate_bonus.c rotate_bonus.c split_bonus.c swap_bonus.c utils_bonus.c aux_bonus.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS:.c=.o))
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
AR = ar
ARFLAGS = rcs
RM = rm -rf

LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

NAME = push_swap

BONUS_NAME = checker

all: $(NAME)

.SILENT: $(OBJS)
$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR)
	@gcc $(CFLAGS) $(OBJS)  $(LIBFT) -o $(NAME)


bonus: $(BONUS_OBJS)
	@gcc $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)


clean:
	$(RM) $(OBJS)  $(LIBFT_A)

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)  $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_DIR) fclean

re: fclean
	@make all

.PHONY: all  clean fclean re bonus