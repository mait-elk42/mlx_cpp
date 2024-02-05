NAME = libft.a
SRC = ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c \
	ft_strtrim.c ft_bzero.c ft_memchr.c  ft_putnbr_fd.c \
	ft_strlcpy.c ft_substr.c ft_isalnum.c ft_memcmp.c  \
	ft_putstr_fd.c  ft_strlen.c  ft_tolower.c ft_isalpha.c \
	ft_memcpy.c  ft_split.c   ft_strmapi.c ft_toupper.c \
	ft_isascii.c ft_memmove.c ft_strchr.c  ft_strncmp.c \
	ft_isdigit.c ft_memset.c  ft_striteri.c   ft_strnstr.c \
	ft_isprint.c ft_putchar_fd.c ft_strjoin.c ft_strrchr.c \
	ft_calloc.c ft_strdup.c get_next_line.c get_next_line_utils.c \
	ft_lstadd_back.c  ft_lstdelone.c ft_lstmap.c \
	ft_lstadd_front.c ft_lstiter.c ft_lstnew.c \
	ft_lstclear.c ft_lstlast.c ft_lstsize.c \
	ft_prtf_int.c ft_printf.c  ft_prtf_uint.c \
	ft_prtf_pointer.c ft_prtf_str.c ft_prtf_uinthex.c \
	ft_putbits.c
SRC_OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(SRC_OBJ)
	ar rc $(NAME) $(SRC_OBJ)
%.o: %.c libft.h
	cc $(CFLAGS) -c $<
clean:
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
