NAME = 	fdf

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -I$(LIBFT_DIR)/$(INCLUDES) -I$(MLX_DIR)

EXT_FLAGS = -lX11 -lm -lz -lXext

OPTI_FLAGS = -Ofast -march=native -flto -fno-signed-zeros -funroll-loops

DFLAGS = -MMD -MP

LIBFT_DIR = libft

LIBFT = libft.a

MLX_DIR = minilib

MLX = libmlx.a

SRC_DIR = srcs

BUILD_DIR = .build

SRC_FILES = main.c \
	    parsing.c \
	    ft_window.c \
		key_hook.c \
		multiply_mat.c \
		scale_mat.c \
		rotation_mat.c \
		world_mat.c \
		translation_mat.c \
		projection_mat.c \
		proj_utils.c \
		scale.c \
		translation.c \
		rotate_minus.c \
		rotation.c \
	    bresenham.c \
	    vertex_acces.c \
	    pars_utils.c \
		init_vertex.c\
		atovertex.c\

INCLUDES = includes

SRC = $(addprefix $(SRC_DIR)/, SRC_FILES)

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))

DEPS = $(OBJ:.o=.d)

.PHONY: all
all : $(NAME)


$(NAME) :  $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OPTI_FLAGS) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX) $(EXT_FLAGS)
.PHONY: mlx
$(MLX_DIR)/$(MLX): FORCE
	$(MAKE) -C $(MLX_DIR)

.PHONY: libf
$(LIBFT_DIR)/$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | $(BUILD_DIR) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEPS)

.PHONY: clean
clean :
	$(MAKE) -C $(LIBFT_DIR)/ clean
	$(MAKE) -C $(MLX_DIR)/ clean
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean : clean
	$(MAKE) -C $(LIBFT_DIR)/ fclean
	$(RM) $(NAME)

.PHONY: re
re : fclean
	$(MAKE) all

.PHONY: FORCE
FORCE:
