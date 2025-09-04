# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 15:33:28 by stkabang          #+#    #+#              #
#    Updated: 2025/08/27 12:49:15 by kingstephan      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
LIBR = ranlib
RM = rm -f
OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)

SRCS = ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlcat.c ft_strlen.c ft_tolower.c ft_toupper.c \
	  ft_isalnum.c ft_isalpha.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
 	  ft_atoi.c ft_memset.c ft_bzero.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
 	  ft_memchr.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
 	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
 	  ft_putnbr_fd.c ft_split.c ft_strndup.c ft_strjoin_and_free.c ft_abs.c

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
 			 ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstdelone_bonus.c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)
	$(LIBR) $(NAME)

bonus: $(OBJ) $(BONUS_OBJ)
	$(LIBC) $(NAME) $(OBJ) $(BONUS_OBJ)
	$(LIBR) $(NAME)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus