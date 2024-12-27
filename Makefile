# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongjko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 21:37:24 by seongjko          #+#    #+#              #
#    Updated: 2023/08/23 21:37:26 by seongjko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = push_swap

BONUS_NAME = checker

CFLAGS = -Wall -Wextra -Werror

SRCS = element_two.c element_three_1.c element_three_2.c element_four.c \
		element_five.c find_pivot.c ft_atoi_p.c ft_calloc_p.c ft_strcmp_p.c \
		hard_coding.c input_parse_1.c input_parse_2.c main.c \
		send_max_to_stack_a.c send_only_group_to_stack_b_1.c \
		send_only_group_to_stack_b_2.c sort_groups_1.c \
		sort_groups_2.c sort_groups_3.c main.c

INST = instructions/push_a.c instructions/push_b.c instructions/ra_and_rb.c \
		instructions/reverse_rotate_a.c \
		instructions/reverse_rotate_b.c \
		instructions/rotate_a.c \
		instructions/rotate_b.c \
		instructions/rra_and_rrb.c \
		instructions/sa_and_sb.c \
		instructions/swap_a.c \
		instructions/swap_b.c 

B_SRCS = bonus/get_next_line_utils.c \
		bonus/get_next_line.c \
		bonus/instruction.c \
		bonus/main.c \
		ft_atoi_p.c ft_calloc_p.c ft_strcmp_p.c \
		input_parse_1.c input_parse_2.c 

B_INST = bonus/push_a_bonus.c bonus/push_b_bonus.c bonus/ra_and_rb_bonus.c \
		bonus/reverse_rotate_a_bonus.c \
		bonus/reverse_rotate_b_bonus.c \
		bonus/rotate_a_bonus.c \
		bonus/rotate_b_bonus.c \
		bonus/rra_and_rrb_bonus.c \
		bonus/sa_and_sb_bonus.c \
		bonus/swap_a_bonus.c \
		bonus/swap_b_bonus.c 

INCLUDE = -I ./
OBJS = $(SRCS:.c=.o)

all : $(NAME)

LIBFTA = ./libft/libft.a

$(NAME) : $(SRCS) $(INST)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(INCLUDE) ${LIBFTA} $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ 


.PHONY: bonus

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(B_SRCS) $(B_INST)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(INCLUDE) ${LIBFTA} $^ -o $@

.PHONY: libft
libft :
	$(MAKE) -C libft re

.PHONY : clean
clean:
	rm -f ${OBJS}
	$(MAKE) -C libft clean

.PHONY : fclean
fclean : clean
	rm -f ${NAME} checker
	$(MAKE) -C libft fclean

.PHONY : re
re : 
	$(MAKE) fclean 
	$(MAKE) all
