SRCS	=	srcs/main.c srcs/launcher_mlx.c srcs/init_structs.c \
			srcs/ft_error.c srcs/get_map.c srcs/rendering.c \
			srcs/cardinal_vector.c srcs/get_elements_from_line.c \
			srcs/store_floor_ceiling.c srcs/raycasting.c srcs/key_hook.c\
			srcs/key_move.c srcs/checks_map.c srcs/check_elements.c \
			srcs/store_sprites.c srcs/textures.c srcs/minimap.c\
			srcs/handle_movement.c srcs/handle_mouse.c srcs/jump.c \
			srcs/color_n_effect.c \
			srcs/render_stuff.c \
			srcs/raycasting_utils.c \

NAME	=	Cub3D
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -MP -MMD -Imlx_linux -Ilibft -g

OBJDIR	=	objs
DEPDIR	=	dep
OBJ		=	$(SRCS:srcs/%.c=$(OBJDIR)/%.o)
DEP		=	$(SRCS:srcs/%.c=$(DEPDIR)/%.d)

LIBFT_DIR	=	libft
LIBFT_A		=	$(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	make -C mlx_linux/
	$(CC) $(OBJ) $(LIBFT_A) -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lXfixes -lm -lz -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(OBJDIR)/%.o: srcs/%.c
	@mkdir -p $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -MF $(DEPDIR)/$(<:srcs/%.c=%.d)

clean:
	rm -f $(OBJ)
	rm -rf $(DEPDIR)
	make -C $(LIBFT_DIR) clean
	make -C mlx_linux clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re

