# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 16:51:17 by stkabang          #+#    #+#              #
#    Updated: 2025/06/23 17:17:54 by kingstephan      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
LIBR = ranlib
INCLUDES = -I./ -I../libft
RM = rm -f
OBJ = $(SRCS:.c=.o)

SRCS = ft_itoa.c \
		ft_printf.c \
		print_func.c \
		print_func2.c \
		print_func3.c \
		ft_uitoa.c

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)
	$(LIBR) $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus