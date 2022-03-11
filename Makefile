# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:48:03 by flcollar          #+#    #+#              #
#    Updated: 2022/03/11 10:45:02 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
DANGER = $(FLAGS) -fsanitize=address -g3

CHARACTER_FOLDER = characters/
CHARACTER_FILES = checkAlpha.c checkSpecial.c changeChar.c search.c
CHARACTER = $(addprefix $(CHARACTER_FOLDER), $(CHARACTER_FILES))

STRING_FOLDER = strings/
STRING_FILES = checkStr.c changeStr.c duplicate.c applyFunc.c split.c strLength.c
STRING = $(addprefix $(STRING_FOLDER), $(STRING_FILES))

MEMORY_FOLDER = memory/
MEMORY_FILES = allocations.c changeMem.c checkMem.c
MEMORY = $(addprefix $(MEMORY_FOLDER), $(MEMORY_FILES))

CONVERT_FOLDER = converters/
CONVERT_FILES = itoa.c bases.c misc.c
CONVERT = $(addprefix $(CONVERT_FOLDER), $(CONVERT_FILES))

MATHS_FOLDER = maths/
MATHS_FILES = limits.c nbrLength.c vector.c
MATHS = $(addprefix $(MATHS_FOLDER), $(MATHS_FILES))

OUTPUT_FOLDER = output/
OUTPUT_FILES = printf.c write.c
OUTPUT = $(addprefix $(OUTPUT_FOLDER), $(OUTPUT_FILES))

SRC = $(CHARACTER) $(STRING) $(MEMORY) $(CONVERT) $(OUTPUT) $(MATHS)
OBJ = $(SRC:.c=.o)

TESTER = printfTester

all: $(NAME)

.c.o:
	@gcc $(FLAGS) -o $@ -c $<
	
$(NAME): $(OBJ)
	@ar -rs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re