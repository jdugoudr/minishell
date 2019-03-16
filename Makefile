# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 13:52:36 by jdugoudr          #+#    #+#              #
#    Updated: 2019/03/15 14:22:20 by jdugoudr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
NAME = minishell
HEAD_DIR = includes
LIB_DIR = libft/
LIB_FT = libft/libft.a
LIB_HEAD = $(addprefix $(LIB_DIR), $(HEAD_DIR))
OBJ_DIR = objs/
VPATH = srcs \
		srcs/builtins \
		srcs/execution \
		srcs/parse \
		srcs/error \
		srcs/signal \
		srcs/prompt
VPATH += includes
SRCS = minishell.c \
	   minishell_error.c \
	   parse.c \
	   lexer.c \
	   lexer_utils.c \
	   parse_utils.c \
	   cd.c \
	   echo.c \
	   env.c \
	   unsetenv.c \
	   env_utils.c \
	   exec_bin.c \
	   path.c \
	   signal.c \
	   prompt.c
HEADERS = minishell.h \
		  minishell_error.h \
		  cd.h \
		  echo.h \
		  env.h \
		  exec_bin.h \
		  parse.h \
		  path.h
OBJS:= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): libft $(OBJ_DIR) $(OBJS)
	@$(CC) -o $@ $(OBJS) $(LIB_FT) -I $(HEAD_DIR) -I $(LIB_HEAD)

libft:
	@make -C $(LIB_DIR) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@echo $<
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD_DIR) -I $(LIB_HEAD)

$(OBJ_DIR):
	mkdir $@

clean:
	@make clean -C $(LIB_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re 
