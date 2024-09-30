# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/29 21:02:43 by eahmeti           #+#    #+#              #
#    Updated: 2024/09/29 21:17:11 by eahmeti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de la lib
NAME = libft.a

# Compilateur et flags

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoires
SRCDIR = srcs
INCDIR = includes

# Fichiers sources et objets
SRC = $(addprefix $(SRCDIR)/, \
	 ft_putchar.c \
	 ft_swap.c \
	 ft_putstr.c \
	 ft_strlen.c \
	 ft_strcmp.c \
)

OBJ = $(SRC:.c=.o)

# Targets

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
