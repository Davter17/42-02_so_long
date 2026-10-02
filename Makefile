# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 20:39:17 by mpico-bu          #+#    #+#              #
#    Updated: 2025/04/12 15:42:18 by mpico-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRCS = 	src/main.c \
		src/map_reader.c \
		src/map_validate.c \
		src/map_checker.c \
		src/sprites_load.c \
		src/game_render.c \
		src/player_moves.c
OBJDIR = obj
OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(OBJS)))

CFLAGS = -Wall -Wextra -Werror -fPIC -g
CC = cc

LIBFT_URL = https://github.com/Davter17/MyLibrary.git
LIBFT_DIR = .deps/libft
LIBFT_INC = $(LIBFT_DIR)/inc
LIBFT_LIB = $(LIBFT_DIR)/libraryC.a

MINILIBX_URL = https://github.com/42Paris/minilibx-linux.git
MINILIBX_DIR = .deps/minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a

INCLUDES = -I$(LIBFT_INC) -I$(MINILIBX_DIR)

.PHONY: all clean fclean re

all: $(LIBFT_LIB) $(MINILIBX_LIB) $(OBJDIR) $(NAME)

$(OBJDIR):
	@printf "  \033[33m⚙\033[0m  Compiling %d files...\n" $(words $(OBJS))
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MINILIBX_LIB)
	@printf "  \033[32m✓\033[0m Compiled %d files → $(NAME)\n" $(words $(OBJS))
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_LIB) $(MINILIBX_LIB) -lX11 -lXext -lm -o $(NAME)

$(LIBFT_LIB):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		printf "  \033[33m⚙\033[0m  Cloning libft...\n"; \
		git clone $(LIBFT_URL) $(LIBFT_DIR) > /dev/null 2>&1; \
	fi
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) > /dev/null 2>&1

$(MINILIBX_LIB):
	@if [ ! -d "$(MINILIBX_DIR)" ]; then \
		printf "  \033[33m⚙\033[0m  Cloning minilibx-linux...\n"; \
		git clone $(MINILIBX_URL) $(MINILIBX_DIR) > /dev/null 2>&1; \
	fi
	@$(MAKE) --no-print-directory -C $(MINILIBX_DIR) > /dev/null 2>&1

clean:
	@printf "  \033[31m✗\033[0m  Removing object files...\n"
	@rm -rf $(OBJDIR)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		$(MAKE) --no-print-directory clean -C $(LIBFT_DIR) > /dev/null 2>&1; \
	fi
	@if [ -d "$(MINILIBX_DIR)" ]; then \
		$(MAKE) --no-print-directory clean -C $(MINILIBX_DIR) > /dev/null 2>&1; \
	fi

fclean: clean
	@printf "  \033[31m✗\033[0m  Removing $(NAME)...\n"
	@rm -f $(NAME)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		$(MAKE) --no-print-directory fclean -C $(LIBFT_DIR) > /dev/null 2>&1; \
	fi

re: fclean all

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@