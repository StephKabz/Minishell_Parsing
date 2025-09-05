# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/15 18:50:18 by kingstephan       #+#    #+#              #
#    Updated: 2025/09/04 18:41:51 by kingstephan      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline
LIBFT = src/libft/libft.a
PRINTF = src/ft_printf/ft_printf.a
OBJ_DIR = obj
RM = rm -f
INCLUDES = -I./ -Isrc/libft -Isrc/ft_printf
SRCS = src/parsing_lexing/lexer/lexer_utils0.c \
		src/parsing_lexing/lexer/lexer_utils1.c \
		src/parsing_lexing/lexer/lexer_utils2.c \
		src/parsing_lexing/lexer/lexer_utils3.c \
		src/parsing_lexing/lexer/lexer_utils4.c \
		src/parsing_lexing/lexer/lexer_utils5.c \
		src/parsing_lexing/lexer/lexer_utils6.c \
		src/parsing_lexing/lexer/lexer.c \
		src/parsing_lexing/line_checker/line_check1.c \
		src/parsing_lexing/line_checker/line_check2.c \
		src/parsing_lexing/parser/parser_utils0.c \
		src/parsing_lexing/parser/parser_utils1.c \
		src/parsing_lexing/parser/parser_utils2.c \
		src/parsing_lexing/parser/parser.c \
		src/parsing_lexing/parser/print.c \
		src/parsing_lexing/main.c
		
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
all: $(NAME)
$(NAME): $(OBJ)
	@echo "📦 Building Libft and ft_printf..."
	@make -C src/libft
	@make -C src/ft_printf
	@echo "🛠  Linking Minishell..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(LDFLAGS) -o $(NAME)
	@echo "✅ Minishell compiled successfully."
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	$(RM) $(OBJ)
	@make clean -C src/libft
	@make clean -C src/ft_printf
	@echo "🧹  Cleaned Objects"
fclean: clean
	$(RM) $(NAME)
	@make fclean -C src/libft
	@make fclean -C src/ft_printf
	@echo "🧨 Full clean done."
re: fclean all
.PHONY: all clean fclean re