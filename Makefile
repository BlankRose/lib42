# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 11:44:51 by flcollar          #+#    #+#              #
#    Updated: 2022/03/03 16:10:52 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_FOLDER = ./
LIB_NAME = ft
NAME = lib$(LIB_NAME).a

FLAGS = -Wall -Werror -Wextra
DANGER = $(FLAGS) -fsanitize=address -g3

SRC = ft_charCheck.c ft_charCheck2.c ft_charFind.c ft_charFind2.c \
	  ft_strManip.c ft_strAlloc.c ft_strFunc.c ft_split.c \
	  ft_memManip.c ft_memManip2.c ft_memAlloc.c ft_output.c \
	  ft_convert.c ft_maths.c ft_maths2.c ft_itoa.c \
	  ft_printf.c ft_bases.c
OBJ = $(SRC:.c=.o)

TEST = main.c
EXE = a.exe

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -c $(SRC)
	@ar -rs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(EXE)

re: fclean all

.PHONY: all clean fclean re