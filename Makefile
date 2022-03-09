# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:48:03 by flcollar          #+#    #+#              #
#    Updated: 2022/03/09 15:46:23 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
DANGER = $(FLAGS) -fsanitize=address -g3

CHARACTER_FOLDER = characters/
CHARACTER_FILES = ft_charCheck.c ft_charCheck2.c ft_charFind.c ft_charFind2.c
CHARACTER = $(addprefix $(CHARACTER_FOLDER), $(CHARACTER_FILES))

STRING_FOLDER = strings/
STRING_FILES = ft_strManip.c ft_strFunc.c ft_strAlloc.c ft_split.c
STRING = $(addprefix $(STRING_FOLDER), $(STRING_FILES))

MEMORY_FOLDER = memory/
MEMORY_FILES = ft_memManip.c ft_memManip2.c ft_memAlloc.c
MEMORY = $(addprefix $(MEMORY_FOLDER), $(MEMORY_FILES))

CONVERT_FOLDER = converters/
CONVERT_FILES = ft_itoa.c ft_convert.c ft_bases.c
CONVERT = $(addprefix $(CONVERT_FOLDER), $(CONVERT_FILES))

MATHS_FOLDER = maths/
MATHS_FILES = ft_maths.c ft_maths2.c
MATHS = $(addprefix $(MATHS_FOLDER), $(MATHS_FILES))

OUTPUT_FOLDER = output/
OUTPUT_FILES = ft_printf.c ft_output.c
OUTPUT = $(addprefix $(OUTPUT_FOLDER), $(OUTPUT_FILES))

SRC = $(CHARACTER) $(STRING) $(MEMORY) $(CONVERT) $(OUTPUT) $(MATHS)
OBJ = $(SRC:.c=.o)

TESTER = printfTester

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test:
	@make -C $(TESTER)

.PHONY: all clean fclean re test