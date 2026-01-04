NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(SRC_DIR)/commands/push.c \
	$(SRC_DIR)/commands/swap.c \
	$(SRC_DIR)/commands/rotate.c \
	$(SRC_DIR)/commands/reverse_rotate.c \
	$(SRC_DIR)/push_swap/handle_errors.c \
	$(SRC_DIR)/push_swap/init_a_to_b.c \
	$(SRC_DIR)/push_swap/init_b_to_a.c \
	$(SRC_DIR)/push_swap/main.c \
	$(SRC_DIR)/push_swap/sort_stacks.c \
	$(SRC_DIR)/push_swap/sort_chunks.c \
	$(SRC_DIR)/push_swap/sort_radix.c \
	$(SRC_DIR)/push_swap/sort_helpers.c \
	$(SRC_DIR)/push_swap/init_helpers.c \
	$(SRC_DIR)/push_swap/stack_init.c \
	$(SRC_DIR)/push_swap/stack_utils.c \
	$(SRC_DIR)/push_swap/stack_utils_2.c \
	$(SRC_DIR)/push_swap/stack_utils_3.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re