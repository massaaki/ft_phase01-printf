# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# LIBFT BUILDING DESCRIPTION	                                                #
# Create a 'out' folder in root if necessary                                  #
# Generate compiled .c files in ./out dir                                     #
# Generate a librar in root                                                   #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# LIBRARY OUTPUT NAME
NAME = libft.a

# PATHS #######################################################################
SRC_PATH = ./src
INCLUDES_PATH = ./includes
OBJ_PATH = ./obj

# FOLDER NAME #################################################################
OBJ_FOLDER = obj

# SOURCES #####################################################################
SRC_NAMES = ft_strlen.c ft_bzero.c ft_memset.c ft_memcpy.c \
	  ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	  ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
	  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	  ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
	  ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	  ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	  ft_itoa_unsigned.c ft_llong_i_to_hex.c \
	  ft_unsigned_i_to_hex.c
SRC_WITH_PATH = $(addprefix $(SRC_PATH)/, $(SRC_NAMES))

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

all: $(OBJ_FOLDER) $(NAME)

# ar -rcs: generate library 
$(NAME): $(OBJECT_WITH_PATH)
	ar -rcs $(NAME) $(OBJECT_WITH_PATH)


# '$<': first dependence item		  
# '$@': target						  
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	${CC} ${FLAGS} -I ${INCLUDES_PATH} -c $< -o $@ 

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	${RM} ${NAME}

re: fclean all

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Auxiliary directives                                                        #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Create(if necessary) 'obj' folder in root
$(OBJ_FOLDER):
	@mkdir -p obj


.PHONY: all clean fclean re resolve_obj_folder