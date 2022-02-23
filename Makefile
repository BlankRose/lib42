# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 11:44:51 by flcollar          #+#    #+#              #
#    Updated: 2022/02/23 15:00:36 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRC = ft_charCheck.c ft_charCheck2.c ft_charFind.c ft_charFind2.c \
	  ft_strManip.c ft_strAlloc.c ft_strFunc.c ft_split.c \
	  ft_memManip.c ft_memManip2.c ft_memAlloc.c ft_output.c \
	  ft_convert.c ft_maths.c

OBJ = $(SRC:.c=.o)

$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
