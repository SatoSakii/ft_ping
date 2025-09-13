NAME		=	ft_ping

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

OBJS_DIR 	=	.build
SRCS_DIR	=	srcs
INC_DIR		=	includes

SRCS		:=	main.c \
				print/print_information.c \
				print/print_error.c \
				parse/options_config.c \
				parse/options_core.c \
				parse/options_handler.c \
				parse/options_parser.c \
				network/dns_resolver.c \
				network/network_utils.c

SRCS		:=	$(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS		=	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(FLAGS) -I$(INC_DIR) $(OBJS) -o $(NAME)
	@echo " $(GREEN)$(BOLD)$(ITALIC)■$(RESET)  building	$(GREEN)$(BOLD)$(ITALIC)$(NAME)$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo " $(CYAN)$(BOLD)$(ITALIC)■$(RESET)  compiling	$(GRAY)$(BOLD)$(ITALIC)$<$(RESET)"
	@$(CC) $(FLAGS) -I$(INC_DIR) -o $@ -c $<

clean:
	@echo " $(RED)$(BOLD)$(ITALIC)■$(RESET)  cleaned	$(RED)$(BOLD)$(ITALIC)$(MLX_DIR)$(RESET)"
	@rm -rf $(OBJS_DIR)

fclean:
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

BLACK		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
MAGENTA		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
GRAY		=	\033[90m

BOLD		=	\033[1m
ITALIC		=	\033[3m

RESET		=	\033[0m
LINE_CLR	=	\33[2K\r