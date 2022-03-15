# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:48:03 by flcollar          #+#    #+#              #
#    Updated: 2022/03/15 16:55:23 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
DANGER = $(FLAGS) -fsanitize=address -g3

#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

# STRING MANIPULATIONS
STRING_FOLDER = strings/
STRING_FILES = is_alphanum.c is_special.c is_set.c set_char.c set_string.c \
			   duplicate.c split.c compare.c strLength.c applyFunc.c search.c
STRING = $(addprefix $(STRING_FOLDER), $(STRING_FILES))

# MEMORY MANIPULATIONS
MEMORY_FOLDER = memory/
MEMORY_FILES = allocations.c changeMem.c checkMem.c
MEMORY = $(addprefix $(MEMORY_FOLDER), $(MEMORY_FILES))

# CONVERTERS
CONVERT_FOLDER = converters/
CONVERT_FILES = itoa.c bases.c misc.c
CONVERT = $(addprefix $(CONVERT_FOLDER), $(CONVERT_FILES))

# MATHEMATICS
MATHS_FOLDER = maths/
MATHS_FILES = limits.c nbrLength.c vector.c
MATHS = $(addprefix $(MATHS_FOLDER), $(MATHS_FILES))

# DATA MANAGER
DATA_FOLDER = data/
DATA_FILES = list_create.c list_modify.c list_destroy.c
DATA = $(addprefix $(DATA_FOLDER), $(DATA_FILES))

# IN & OUT HANDLERS
IN_OUT_FOLDER = inout/
IN_OUT_FILES = getNextLine.c printf.c write.c
IN_OUT = $(addprefix $(IN_OUT_FOLDER), $(IN_OUT_FILES))

# ALL SOURCES TOGHETER
SRC = $(CHARACTER) $(STRING) $(MEMORY) $(CONVERT) $(IN_OUT) $(MATHS) $(DATA)
OBJ = $(SRC:.c=.o)

#==--------------------------------------==#
# *                                      * #
#                   RULES                  #
# *                                      * #
#==--------------------------------------==#

all: $(NAME)

.c.o:
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@ar -rs $(NAME) $(OBJ)

bonus: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re