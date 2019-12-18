# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bantario <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 13:57:13 by bantario          #+#    #+#              #
#    Updated: 2019/11/27 16:28:11 by bantario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = srcs

DIR_O = objs

HEADER = includes

SOURCES = float.c number.c parser.c display.c string.c  base_numbers.c define.c ft_printf.c define_nb.c display_nb.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT) fclean && make -C $(LIBFT)
		@cp libft/libft.a ./$(NAME)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "OK"

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
		@mkdir -p $(DIR_O)
		@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
		@rm -f $(OBJS)
		@rm -rf $(DIR_O)
		@make clean -C $(LIBFT)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re all clean
