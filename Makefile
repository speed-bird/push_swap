# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 14:33:37 by jrobert           #+#    #+#              #
#    Updated: 2021/07/07 15:57:26 by jrobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES	= 	alter.c \
				input.c \
				min_max.c \
				ordering.c \
				push_swap.c \
				rotate.c \
				sort_few_three.c \
				sort_large_a.c \
				sort_large_b.c \
				sort_medium.c \
				utils.c
SRCS_DIR	= 	srcs/
SRCS		=	$(addprefix $(SRCS_DIR),$(SRCS_FILES))
OBJS		= 	$(SRCS:%.c=%.o)
EXE			=	push_swap
LIBPATH 	= 	-L libft
LIB     	= 	-lft
CFLAGS		= 	-Wall -Wextra -Werror -g -I includes -I libft/includes
LDFLAGS 	= 	$(LIBPATH) $(LIB) -o $(EXE)
			
$(EXE)			:	$(OBJS)
					$(MAKE) -C ./libft/
					gcc $(OBJS) $(LDFLAGS) 

all    			:	$(EXE)

clean 			:	
					rm -f $(OBJS)
					$(MAKE) clean -C ./libft/

fclean 			:	clean
					rm -f $(EXE)
					$(MAKE) fclean -C ./libft/
					
re				:	fclean all

.PHONY			: 	all clean fclean re


