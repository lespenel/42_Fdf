NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -Ofast -I$(INCLUDES)

DFLAGS = -MMD -MP

SRC =	ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_toupper.c \
		  ft_tollower.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strnstr.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_atoi.c \
		  ft_atoi_hex.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_strtok.c \
		  ft_strtok.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_strjoin_free_s1.c \
		  get_next_line.c \
		  ft_strn2join_free_s1.c \
		  ft_split_charset.c \
		  ft_split_free.c \
		  count_words.c \
		  ft_lstnew_bonus.c \
	      ft_lstadd_front_bonus.c \
	      ft_lstsize_bonus.c \
	      ft_lstlast_bonus.c \
	      ft_lstadd_back_bonus.c \
	      ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c \
		  ft_lstiter_bonus.c \
		  ft_lstmap_bonus.c	\
		  vector_init.c \
		  add_vector.c \
		  add_multiple_vector.c \
		  add_str_vector.c \
		  clear_vector.c \

INCLUDES = includes

BUILD_DIR = .build

SRC_DIR = srcs

MY_OBJECT = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

DEPS = $(OBJ:.o=.d)

-include $(DEPS)

.PHONY: all
all : $(NAME)

$(NAME) : $(MY_OBJECT)
	ar rc $(NAME) $(MY_OBJECT)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean :
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean : clean
	$(RM) $(NAME)

.PHONY: re
re : fclean all
