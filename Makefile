# PROGRAM NAME
NAME = libftprintf.a

# PATHS
LIBFT_PATH = ./libft
OBJ_PATH = ./obj
SRC_PATH = ./src

FILES = test1.c test2.c test3.c

SRCS = ${addprefix ${SRC_PATH}/,${FILES}}
OBJS = ${addprefix ${SRC_PATH}/,${FILES:.c=.o}}

all:
	@echo $(MAKE)


library:
	make -C ${LIBFT_PATH}