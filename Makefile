# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/25 14:36:59 by mtomanar          #+#    #+#              #
#    Updated: 2026/05/28 19:28:50 by mtomanar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do compilador
CC = cc

# Flags de compilação
CFLAGS = -Wall -Wextra -Werror

# Nome do arquivo executável final
INCLUDES = -I.
BIN = bin
NAME = libftprintf.a
HEADER = ft_printf.h

# Arquivos fonte
SRCS = 	ft_printf.c \
				ft_putchar.c 


# Arquivos objeto gerados na compilação
OBJS = $(patsubst %.c,$(BIN)/%.o,$(SRCS))

# Regra principal (executada ao digitar apenas 'make')
all: $(NAME)

# Como gerar o executável a partir dos objetos
$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

# Como gerar arquivos objeto a partir dos fontes
$(BIN)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@



# Regra para limpar os arquivos gerados (make clean)
clean:
	rm -rf $(BIN)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus