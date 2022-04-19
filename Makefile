# LIBRARY OUTPUT NAME
NAME = libftprintf.a

# PATHS #######################################################################
SRC_PATH = ./src
INCLUDES_PATH = ./includes
OBJ_PATH = ./obj
LIBRARIES_PATH = ./libraries

# SOURCES #####################################################################
SRC_NAMES = ft_printf.c

# OBJECTS #####################################################################
OBJECT_NAMES = $(SRC_NAMES:.c=.o)
OBJECT_WITH_PATH = $(addprefix $(OBJ_PATH)/, $(OBJECT_NAMES))

# SCRIPTS/FLAGS ###############################################################
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
CC = gcc

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# MANDATORY DIRECTIVES                  									  #
# all - $(NAME) - clean - fclean - re   									  # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

all: library_dependences resolve_obj_folder $(NAME)

$(NAME): $(OBJECT_WITH_PATH)
	ar -rcs $(NAME) $(OBJECT_WITH_PATH) $(LIBRARIES_PATH)/libft/obj/*.o

# '$<': first dependence item		  
# '$@': target						  
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	${CC} ${FLAGS} -I ${INCLUDES_PATH} -c $< -o $@ 

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all



# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Auxiliary directives    													  #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

library_dependences:
	@make -C ${LIBRARIES_PATH}/libft

# Create(if necessary) 'obj' folder in root
resolve_obj_folder:
	@mkdir -p obj

.PHONY: all clean fclean re resolve_obj_folder