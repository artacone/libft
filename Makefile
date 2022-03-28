# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvertie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 21:13:42 by rvertie           #+#    #+#              #
#    Updated: 2021/04/14 11:30:04 by rvertie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRC_DIR		=	./src/

OBJ_DIR		=	./obj/

HEADER_DIR	=	./include/

SRC			=	$(wildcard ${SRC_DIR}*.c)

HEADER		=	$(wildcard ${HEADER_DIR}*.h)

OBJ			=	$(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -MMD -O2

RM			=	rm -f


all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

re: fclean $(OBJ_DIR) all

.PHONY: all clean fclean re
