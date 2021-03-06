# LIBRARY OUTPUT NAME
NAME = libftprintf.a

# PATHS #######################################################################
SRC_PATH = ./src
INCLUDES_PATH = ./includes
OBJ_PATH = ./obj
LIBRARIES_PATH = ./libraries

# FOLDER NAME #################################################################
OBJ_FOLDER = obj

# SOURCES #####################################################################
SRC_NAMES = ft_printf.c \
						ft_rule_identify.c \
						ft_rule_signed_int.c \
						ft_rule_unsigned_int.c \
						ft_rule_str.c \
						ft_rule_char.c \
						ft_rule_pointer.c \
						ft_rule_hex_lower.c \
						ft_rule_hex_upper.c \
						ft_rule_percent.c

# OBJECTS #####################################################################
OBJECT_NAMES = $(SRC_NAMES:.c=.o)
OBJECT_WITH_PATH = $(addprefix $(OBJ_PATH)/, $(OBJECT_NAMES))

# SCRIPTS/FLAGS ###############################################################
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
CC = gcc

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# MANDATORY DIRECTIVES                                                        #
# all - $(NAME) - clean - fclean - re                                         # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

all: library_dependences $(OBJ_FOLDER) $(NAME)

$(NAME): $(OBJECT_WITH_PATH)
	ar -rcs $(NAME) $(OBJECT_WITH_PATH) $(LIBRARIES_PATH)/libft/obj/*.o

# '$<': first dependence item		  
# '$@': target						  
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	${CC} ${FLAGS} -I ${INCLUDES_PATH} -c $< -o $@ 

clean:
	$(RM) $(OBJ_PATH)
	$(RM) $(LIBRARIES_PATH)/libft/obj

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBRARIES_PATH)/libft/*.a

re: fclean all

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Test                                                                        #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
test_unit:
	@make unit -C ./tests

test_integration:
	@make integration -C ./tests

test_original:
	@make original -C ./tests

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Auxiliary directives                                                        #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

library_dependences:
	@make -C ${LIBRARIES_PATH}/libft

# Create(if necessary) 'obj' folder in root
$(OBJ_FOLDER):
	@mkdir -p obj

.PHONY: all clean fclean re resolve_obj_folder