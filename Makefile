NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC = main.c \
      init.c \
      destroy.c \
      routine.c \
      utils.c \
      monitor.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
