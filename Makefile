CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
NAME = lem-in
SRC = bread_first_module.c \
	bread_first_module_two.c \
	build_graph_module.c \
	build_graph_module_two.c \
	build_rooms_arr_module.c \
	get_next_line.c \
	list_ops.c \
	list_ops_two.c \
	main.c \
	output_module.c \
	parsing_module.c \
	parsing_module_three.c \
	parsing_module_two.c \
	path_finding_module.c \
	path_finding_module_two.c \
	ant_ops_module.c \
	ant_ops_module_two.c \


all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME):
	@echo "building binary file"
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) -I -lft $(LIBFT)

clean:
	@make clean -C libft/

fclean: clean
	@echo "delete $(NAME)"
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all