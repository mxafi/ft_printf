# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 15:25:10 by malaakso          #+#    #+#              #
#    Updated: 2022/11/26 01:08:24 by malaakso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
LIBFT			=	libft.a
COMPILER		=	cc

H_FOLDER		=	includes
C_FOLDER		=	src
OBJ_FOLDER		=	obj
LIBFT_FOLDER	=	libft
FOLDER_LIST		=	$(H_FOLDER) $(C_FOLDER) $(OBJ_FOLDER) $(LIBFT_FOLDER)

H_FILES			=	ft_printf.h ft_printf_utils.h ft_printf_hex_utils.h
C_FILES			=	ft_printf.c ft_printf_utils.c ft_printf_hex_utils.c

H_PATHS			=	$(addprefix $(H_FOLDER)/, $(H_FILES))
C_PATHS			=	$(addprefix $(C_FOLDER)/, $(C_FILES))
OBJ_PATHS		=	$(addprefix $(OBJ_FOLDER)/, $(patsubst %.c, %.o, $(C_FILES)))

C_FLAGS			=	-Wall -Wextra -Werror
C_FLAGS			+=	-g -Wconversion

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_PATHS) Makefile $(LIBFT_FOLDER)/$(LIBFT)
	ar rucs $@ $(OBJ_PATHS) $(LIBFT_FOLDER)/$(LIBFT)

$(OBJ_PATHS): $(OBJ_FOLDER)/%.o:$(C_FOLDER)/%.c $(H_PATHS) Makefile
	$(COMPILER) $(C_FLAGS) -I $(H_FOLDER) -I $(LIBFT_FOLDER) -c $< -o $@

$(LIBFT_FOLDER)/$(LIBFT): $(FOLDER_LIST)
	$(MAKE) -C $(LIBFT_FOLDER)

$(FOLDER_LIST):
	mkdir $@

.PHONY: print_files
print_files:
	@echo "H paths:   $(H_PATHS)"
	@echo "C paths:   $(C_PATHS)"
	@echo "OBJ paths: $(OBJ_PATHS)"
	@echo "C flags:   $(C_FLAGS)"
	@echo ""

.PHONY: debug
debug: $(NAME)
	$(COMPILER) $(C_FLAGS) src/test.c $(NAME) $(LIBFT_FOLDER)/$(LIBFT) -I includes -I libft

.PHONY: clean
clean:
	-@rm -f $(OBJ_PATHS)
	-$(MAKE) fclean -C $(LIBFT_FOLDER)

.PHONY: fclean
fclean: clean
	-@rm -f $(NAME)

.PHONY: re
re: fclean all
