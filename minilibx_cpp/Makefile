SRCS=mlx_cpp_api.c
OBJS=$(SRCS:.c=.o)
LIBNAME=mlx_cpp.a
NAME=mlx_cpp.a

all: $(LIBNAME)
	c++ main.cpp $(LIBNAME) -o main -I include -L lib -lmlx -framework OpenGL -framework AppKit

$(LIBNAME): $(OBJS)
	ar -crs $(LIBNAME) $(OBJS)

%.o: %.c
	cc -c $< -o $@ -I include

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBNAME)

re: fclean all
