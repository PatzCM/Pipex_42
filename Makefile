#/******************************************************************************/
#/*                                                                            */
#/*        Created by: Patricia Monteiro                                       */
#/*           Makefile for the Pipex project																	  */
#/*                                                                            */
#/******************************************************************************/

define	HEADER

██████╗ ██╗██████╗ ███████╗██╗  ██╗     
██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝
██████╔╝██║██████╔╝█████╗   ╚███╔╝ 
██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ 
██║     ██║██║     ███████╗██╔╝ ██╗
╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝
                                   
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢠⣶⣶⣶⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⣷⣄⢀⣸⣿⣿⣿⣿⣄⠀⣴⣿⣿⣶⣄⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀
⠀⠀⢀⣴⣦⣤⣠⣾⣿⣿⣿⠟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣀⣤⣤⡄⠀
⠀⠀⣾⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⢙⣿⣿⣿⣿⣿⡿⠋⢹⣿⣿⣿⣿⣿⣿⣿⡆
⠀⠀⠉⠻⣿⣿⣿⡿⠁⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⠃⠀⠻⠿⠃⣿⣿⣿⣿⠋⠀
⣡⣀⣀⣼⣿⣿⣿⡇⠀⠀⣠⡟⠉⠙⢿⣿⣿⡿⠉⠀⢀⣨⣤⣴⣿⣿⣿⣿⣀⣀
⢸⣿⣿⣿⣿⣿⣿⣷⣠⣾⣿⣿⣦⡄⣠⡿⠃⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠁⠀⣠⡾⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠀⠀⠀⢙⣿⣿⣿⣿⣿⠿⠿⠟⠁⠀⣠⣾⣧⡀⠀⠈⠻⣿⣿⣿⣿⣿⣿⡏⠀⠀
⠀⠀⣵⣿⣿⣿⣿⣿⠁⣾⡀⠀⢠⣾⣿⣿⣿⣿⣦⡀⠀⠈⢻⣿⣿⣿⣿⣿⣶⡀
⠀⠀⢻⣿⣿⣿⣿⣿⣼⣿⡟⠀⣼⣿⣿⣿⣿⣿⣿⣿⣦⣤⣾⣿⣿⣿⣿⣿⣿⠃
⠀⠀⠀⠙⠉⠁⠈⣻⣿⣿⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠀⠉⠙⠁⠀
⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⠿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠙⠻⢿⠏⠀⠀⢸⣿⣿⣿⣿⠀⠀⠘⠿⠿⠛⠁⠀⠀⠀⠀

endef
export HEADER

# Colors

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
PURPLE = \033[0;35m
PINK = \033[0;95m

# Name of the project

NAME = pipex

INCLUDES = -I includes

# Directories
#
SRCDIR = srcs

SRCS = main.c utils.c 

OBJS = $(SRCS:.c=.o)

# Compiler and flags

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
LIBS = ./libs/libft/libft.a
RM = rm -f
AR = ar rcs

# Rules

all: deps $(NAME)
	@echo	"$(GREEN)$ Dependencies done! \n $(PURPLE)$$HEADER $(NO_COLOR)"

deps:
	@make -C libs/libft

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled$(RESET)"

clean: 
	@$(RM) $(OBJS)
	@echo "$(YELLOW)$(NAME) objects removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) removed$(RESET)"

re: fclean all

header:
	@echo "$$HEADER"

norminette:
	@norminette $(SRCDIR) $(INCLUDES)
	@echo "$(GREEN)Norminette done$(RESET)"

.PHONY: all clean fclean re header norminette
