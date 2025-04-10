# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 20:39:17 by mpico-bu          #+#    #+#              #
#    Updated: 2025/04/09 16:20:22 by mpico-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRCS = 	src/main.c \
		src/map_reader.c \
		src/map_validate.c \
		src/map_checker.c
OBJDIR = obj
OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(OBJS)))

CFLAGS = -Wall -Wextra -Werror -fPIC
CC = cc

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -Ilibft

MINILIBX = ./minilibx-linux/libmlx.a

.PHONY: all clean fclean re libft_clean libft_fclean

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MINILIBX)  -L./libft -lft -L./minilibx-linux -lmlx -lX11 -lXext -lm -o $(NAME)
	chmod +x $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	@make -C minilibx-linux

clean: libft_clean
	rm -rf $(OBJDIR)

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all

libft_clean:
	$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
