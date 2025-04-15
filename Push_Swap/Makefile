# Derleyici ve bayraklar
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Program adı
NAME = push_swap

# Libft kütüphanesi
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I. -I$(LIBFT_DIR)

# Kaynak dosyaları
SRC =	srcs/main.c \
		srcs/stack_init.c \
		srcs/stack_operation.c \
		srcs/stack_utils.c \
		srcs/operations.c \
		srcs/operations_push.c \
		srcs/operations_rotate.c \
		srcs/operations_reverse_rotate.c \
		srcs/radix_sort.c \
		srcs/normalize_stack.c \
		srcs/small_sort.c \
		srcs/input_validation.c 
# Obje dosyaları
OBJ = $(SRC:.c=.o)

# Header dosyası
HEADER = includes/push_swap.h

# Derleme kuralları
all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Temizleme kuralları
clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

# Phony hedefler
.PHONY: all clean fclean re