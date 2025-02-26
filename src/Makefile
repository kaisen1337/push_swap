# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 09:46:12 by nkasimi           #+#    #+#              #
#    Updated: 2025/01/31 11:48:01 by nkasimi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = nchecker
CC = cc -g
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c libft.c ft_split.c l_list.c Errors.c utils.c \
       movement.c push_swap.c rotate.c sort.c tools_1.c tools_2.c main.c

BNS = ft_printf.c libft.c ft_split.c l_list.c Errors.c utils.c \
      movement.c push_swap.c rotate.c get_next_line.c \
      get_next_line_utils.c double_move.c main_checker.c

OBJS = $(SRCS:.c=.o)
OBJB = $(BNS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJB)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re