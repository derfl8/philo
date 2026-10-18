CC		= cc
CFLAGS	= -Wall -Wextra -Werror -pthread -g
NAME	= philo
HEADER	= philo.h
SRCS	=		\
philo.c			\
utils.c			\
pthread.c		\
init.c			\
monitor.c		\

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
