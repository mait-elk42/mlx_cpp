# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 22:11:55 by mait-elk          #+#    #+#              #
#    Updated: 2024/02/05 17:45:13 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= main.cpp
OBJS= $(SRCS:.cpp=.o)
LIBFT= libft_adv/libft.a

all: $(OBJS) $(LIBFT)
	c++ $(OBJS) $(LIBFT) -o game -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	make -C libft_adv
%.o: %.c
	cc -c $< -I include

clean:
	rm -f $(OBJS)