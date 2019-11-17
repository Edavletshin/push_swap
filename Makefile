# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galiza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 17:15:06 by galiza            #+#    #+#              #
#    Updated: 2019/11/09 18:21:23 by galiza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap
CH = checker
LB = lib

SRC_P = main_push_swap.c check_way.c commands0.c cut.c drum.c\
		extra_ft.c list_operations.c sort_funk.c\
		structs.c take_arg.c commands1.c gnl.c

SRC_C = main_checker.c check_way.c commands0.c cut.c drum.c\
		extra_ft.c list_operations.c sort_funk.c\
		structs.c take_arg.c commands1.c gnl.c

OBJ_P = $(SRC_P:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(LB) $(PS) $(CH)

$(LB):
	@cd ./ft_printf && make
$(PS):
	@gcc $(CFLAGS) $(SRC_P) ft_printf/libftprintf.a -o $(PS)

$(CH):
	@gcc $(CFLAGS) $(SRC_C) ft_printf/libftprintf.a -o $(CH)
ps:
	@rm $(PS)
	@gcc $(CFLAGS) $(SRC_P) ft_printf/libftprintf.a -o $(PS)

ch:
	@rm $(CH)
	@gcc $(CFLAGS) $(SRC_C) ft_printf/libftprintf.a -o $(CH)





clean:
	@rm -f $(OBJ_C) $(OBJ_P)
	@cd ./ft_printf && make clean

fclean: clean
	@cd ./ft_printf && make fclean
	@rm -f $(PS) $(CH)


re: fclean all

glu: fclean all clean
