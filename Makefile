##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC		=       gcc

RM		=	rm -f

INCDIRS		=	$(addprefix -I, $(shell find ./include -type d -print))

CFLAGS		=        -Wall -Wextra -Wmissing-prototypes

CPPFLAGS	+=       $(INCDIRS)

NAME		=	strace

SRCS		=	./src/s_trace.c \
			./src/display_syscalls.c \
			main.c

OBJS            =       $(SRCS:.c=.o)

all             :       $(NAME)

$(NAME)         :       $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean           :
		$(RM) $(OBJS)

fclean          :       clean
			$(RM) $(NAME) *~ *#

re              :       fclean all

.PHONY		:	all clean fclean re
