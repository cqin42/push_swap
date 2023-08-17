# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cqin <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 15:19:00 by cqin              #+#    #+#              #
#    Updated: 2023/05/17 12:02:38 by cqin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SRCS_NAME = push_swap.c

SRCS = big_stack.c initialisation.c intructions_utils.c mov.c positions.c \
       push.c reverse_rotate.c rotate.c small_stack.c swap.c \
       utils.c

SRCS_BONUS = checker.c get_next_line/get_next_line.c \
	     get_next_line/get_next_line_utils.c

OBJ_NAME = $(SRCS_NAME:.c=.o)

OBJ_SRCS = $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc -Wall -Werror -Wextra

RM =rm -f

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

.c.o:
	${CC} -c $< -o ${<:.c=.o}

all : $(LIBFT) $(NAME)

bonus : $(BONUS)

$(LIBFT) :
	make -C $(LIBFT_PATH)
	ar rcs $(LIBFT)

$(NAME) : $(OBJ_NAME) $(OBJ_SRCS) $(LIBFT)
	$(CC) $(OBJ_NAME) $(OBJ_SRCS) -o $(NAME) $(LIBFT)

$(BONUS) : $(OBJ_SRCS) $(OBJ_BONUS) $(LIBFT)
	$(CC) $(OBJ_SRCS) $(OBJ_BONUS) -o $(BONUS) $(LIBFT)

clean :
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJ_NAME) $(OBJ_SRCS) $(OBJ_BONUS)

fclean : clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME) $(BONUS) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
