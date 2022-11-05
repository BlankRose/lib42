# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:48:03 by flcollar          #+#    #+#              #
#    Updated: 2022/05/18 16:46:21 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

# EXECUTABLE
# Defines the executable's name and the arguments for 'make run/test'

NAME			= libft.a
ARGUMENTS		= 


# COMPILATION
# Configurations for compilation

LANGUAGE		= c
COMPILER		= default
LIB_FILES		= 
LIB_FOLDER		= 
INCLUDES		= 
LINKER_PARAMS	= 
DEFINES			= BUFFER_SIZE=10000
COMPILE_PARAMS	= -Wall -Werror -Wextra -g3
ifneq ($(OS), Windows_NT)
	LINKER_PARAMS += -fsanitize=address
endif

# SOURCE CODE
# List of all source codes

# STRING MANIPULATIONS
STRING_FOLDER = strings$(FOLD)
STRING_FILES = is_alphanum is_special is_set set_char set_string \
			   duplicate split compare strLength applyFunc search \
			   join
STRING = $(addprefix $(STRING_FOLDER), $(STRING_FILES))

# MEMORY MANIPULATIONS
MEMORY_FOLDER = memory$(FOLD)
MEMORY_FILES = allocations changeMem checkMem free
MEMORY = $(addprefix $(MEMORY_FOLDER), $(MEMORY_FILES))

# CONVERTERS
CONVERT_FOLDER = converters$(FOLD)
CONVERT_FILES = itoa bases bases2 strings misc
CONVERT = $(addprefix $(CONVERT_FOLDER), $(CONVERT_FILES))

# MATHEMATICS
MATHS_FOLDER = maths$(FOLD)
MATHS_FILES = limits nbrLength power overflow range divide
MATHS = $(addprefix $(MATHS_FOLDER), $(MATHS_FILES))

# DATA MANAGER
DATA_FOLDER = data$(FOLD)
DATA_FILES = list_create list_modify list_destroy list_fetch \
			btree_create btree_destroy struct_init sort
DATA = $(addprefix $(DATA_FOLDER), $(DATA_FILES))

# IN & OUT HANDLERS
IN_OUT_FOLDER = inout$(FOLD)
IN_OUT_FILES = lines print write
IN_OUT = $(addprefix $(IN_OUT_FOLDER), $(IN_OUT_FILES))

GENERIC_FILES	= $(CHARACTER) $(STRING) $(MEMORY) $(CONVERT) $(IN_OUT) $(MATHS) $(DATA)
GENERIC_FOLDER	= 



#==--------------------------------------==#
# *                                      * #
#              SPECIAL MACROS              #
# *                                      * #
#==--------------------------------------==#

# LANGUAGE CORRECTOR
ifneq (, $(filter CPP CPp Cpp cPP cPp cpP cpp c++ C++, $(LANGUAGE)))
	FILE_EXTENSION := .cpp
else ifneq (, $(filter C c, $(LANGUAGE)))
	FILE_EXTENSION := .c
else
	FILE_EXTENSION := .$(LANGUAGE)
endif

# BASIC MACROS
ifneq ($(GENERIC_FOLDER), )
	GENERIC_FOLDER += $(FOLD)
endif
SRC 		= $(foreach file, $(GENERIC_FILES), $(GENERIC_FOLDER)$(file)$(FILE_EXTENSION))
OBJ			= $(SRC:$(FILE_EXTENSION)=.o)
LINKS		= $(EXT_BINARIES) $(LINKER_PARAMS)
FLAGS		= $(addprefix -L, $(LIB_FOLDER)) \
			  $(addprefix -l, $(LIB_FILES)) \
			  $(addprefix -I, $(INCLUDES)) \
			  $(addprefix -D, $(DEFINES)) \
			  $(COMPILE_PARAMS)

# SYSTEM CONTROL
ifeq ($(OS), Windows_NT)
	FOLD	= \\
	NOERR	= || exit 0
	SILENT	= > NUL 2>&1
	STOP	= && exit 1
else
	FOLD	= /
	NOERR	= || true
	SILENT	= > /dev/null 2>&1
	STOP	= && false
endif
CONTINUE	= $(SILENT) $(NOERR)

# PRE-GENERATED COMMANDS
ifeq ($(OS), Windows_NT)
	CMD_PRINT	= echo
	CMD_CLEAR	= del /f /q
	CMD_EXE		= .exe
else
	CMD_PRINT	= printf
	CMD_CLEAR	= rm -f
endif

# DEFAULT COMPILER SELECTOR
ifeq ($(COMPILER), default)
	ifeq ($(FILE_EXTENSION), .cpp)
		COMPILER = c++
	else ifeq ($(FILE_EXTENSION), .c)
		COMPILER = gcc
	else
		COMPILER = gcc
	endif
endif



#==--------------------------------------==#
# *                                      * #
#             DISPLAY MESSAGES             #
# *                                      * #
#==--------------------------------------==#

# SYNTAX SEQUENCES
ESC			= 
ifneq ($(OS), Windows_NT)
	NEWLINE	= \n
	QUOTE	= "
	BREAK	= \r
endif
RED			= $(ESC)[0;31m
GRN			= $(ESC)[0;32m
YLW			= $(ESC)[0;33m
BLU			= $(ESC)[0;34m
NUL			= $(ESC)[0m
END			= $(ESC)[0m$(NEWLINE)
BACK		= $(ESC)[2K$(BREAK)

# GENERAL COMBINAISONS
MSG_WORK	= $(QUOTE)$(BACK)$(YLW)
MSG_GOOD	= $(QUOTE)$(BACK)$(GRN)
MSG_ERROR	= $(QUOTE)$(BACK)$(RED)
MSG_WRET	= $(END)$(QUOTE)
MSG_NRET	= $(NUL)$(QUOTE)

# COMPILING MESSAGES
GET_NEEDING	= $(MSG_WORK)ƒ Fetching dependencies ...$(MSG_NRET)
CMP_NEEDING	= $(MSG_WORK)ƒ Compiling dependencies ...$(MSG_NRET)
CMP_WORKING	= $(MSG_WORK)ƒ Compiling $@ ...$(MSG_NRET)
CMP_SUCCESS	= $(MSG_GOOD)√ The library $(NAME) has been compiled successfully!$(MSG_WRET)
CMP_FAILURE	= $(MSG_ERROR)ø The library $(NAME) failed to compile!$(MSG_WRET)

# CLEARING MESSAGES
CLR_NEEDING	= $(MSG_WORK)ƒ Cleaning dependencies ...$(MSG_NRET)
CLR_WORKING	= $(MSG_WORK)ƒ Cleaning files ...$(MSG_NRET)
CLR_SUCCESS	= $(MSG_GOOD)√ Objects has been cleared!$(MSG_WRET)
CLR_FAILURE	= $(MSG_ERROR)ø Objects couldn't be cleared!$(MSG_WRET)

# MISC MESSAGES
NON_COMPAT	= $(MSG_ERROR)ø This rule is not compatible yet with your OS $(OS)$(MSG_WRET)



#==--------------------------------------==#
# *                                      * #
#              MAKEFILE RULES              #
# *                                      * #
#==--------------------------------------==#

a: all
all: $(NAME)

d: dependencies
dependencies:
ifneq ($(REPOSITORIES), )
	@$(CMD_PRINT) $(GET_NEEDING)
	@$(GET_REPOS)
endif
ifneq ($(REQUIERD), )
	@$(CMD_PRINT) $(CMP_NEEDING)
	@$(MAKE_REQUIERD)
endif

.c.o:
	@$(CMD_PRINT) $(CMP_WORKING)
	@$(COMPILER) $(FLAGS) -o $@ -c $<

.cpp.o:
	@$(CMD_PRINT) $(CMP_WORKING)
	@$(COMPILER) $(FLAGS) -o $@ -c $<

$(NAME): dependencies $(OBJ)
	@$(CMD_PRINT) $(CMP_WORKING)
	@ar -rsc $(NAME) $(OBJ)
	@$(CMD_PRINT) $(CMP_SUCCESS)

c: clean
clean:
	@$(CMD_PRINT) $(CLR_WORKING)
	@$(CMD_CLEAR) $(OBJ) $(SILENT)
	@$(CMD_PRINT) $(CLR_SUCCESS)

fc: fclean
fclean: clean
	@$(CMD_CLEAR) $(NAME) $(SILENT)

re: remake
remake: fclean all

.PHONY: all dependencies clean fclean libclean remake

# Personnal free to use template
# BY Rosie ~
