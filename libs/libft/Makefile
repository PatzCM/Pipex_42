# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 15:22:22 by palexand          #+#    #+#              #
#    Updated: 2024/11/06 17:38:43 by palexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Colors
NO_COLOR = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
CYAN = \033[0;96m

# Vari/alias that define the files that will be compilled together
RM = rm -f
# CFLAGS = Compiler flags that will be used to compile the files
CFLAGS = -Wall -Wextra -Werror
# SRCS = Source files that will be compiled together
LIBFT = ft_isalnum.c ft_itoa.c ft_memset.c ft_strlcpy.c ft_substr.c ft_isalpha.c \
			ft_memchr.c ft_split.c ft_strlen.c ft_tolower.c ft_atoi.c ft_isascii.c \
			ft_memcmp.c ft_strchr.c ft_strncmp.c ft_strdup.c ft_toupper.c ft_bzero.c ft_isdigit.c \
			ft_memcpy.c ft_strjoin.c ft_strnstr.c ft_strrchr.c ft_calloc.c ft_isprint.c \
			ft_memmove.c ft_strlcat.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

PRINTF = printf/ft_printf.c printf/ft_hexa_printf.c printf/ft_hexa_printf.c printf/ft_nbr_printf.c printf/ft_pointer_printf.c \
				 printf/ft_str_printf.c printf/ft_unbr_printf.c

GNL = gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c
SRCS = ${LIBFT} ${PRINTF} ${GNL}
# OBJS = Object files $(source: .c INPUT = .o OUTPUT) because when compiling a static library you need .o files.
OBJS = ${SRCS:.c=.o}
NAME = libft.a
#Name is the name of the file. .a is static library.
# all is the basic rule of makefile whenever there's no rule input.(make )
all: ${NAME}
	@echo "$(GREEN)All libraries compilation done!$(NO_COLOR)"

#Name calls the objects and then compiles (ar rc) calling the name of the file and objects to compile.
${NAME}: ${OBJS}  
	ar rcs ${NAME} ${OBJS} 

#Delete the .o files
clean:
	${RM} ${OBJS} 
	@echo "$(YELLOW)Cleaning libraries completed!$(NO_COLOR)"

#Delete the .o file with clean + remove .a file with $NAME.
fclean: clean
	${RM} ${NAME} 
	@echo "$(YELLOW)Cleaning libs .a and .o completed!$(NO_COLOR)"

#Clean everything (.o & .a) and recompile
re: fclean all
	@echo "$(GREEN)Recompilation done!$(NO_COLOR)"

#To not allow overlap of rules
.PHONY: re fclean clean all

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS = ${BONUS:.c=.o}
bonus: ${BONUS_OBJS} ${OBJS}
	ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}
	@echo "$(GREEN)All bonus libraries compilation done!$(NO_COLOR)"

.PHONY: bonus
