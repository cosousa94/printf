# nome do programa final
NAME = libftprintf.a

# compilador
CC = cc 

# flags de compilação
CFLAGS = -Wall -Wextra -Werror 

# arquivos fonte
SRC = ft_printf.c ft_printf_aux.c 

# arquivos objeto (substituindo .c por .o)
OBJ = $(SRC:.c=.o) 

# regra padrão
all: $(NAME)

# compilação do programa
$(NAME): $(OBJ)        
	@ar rcs $@ $^      

# regra para arquivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# limpa arquivos objeto
clean:
	rm -f $(OBJ)

# limpa arquivos objeto e o executável
fclean: clean
	rm -f $(NAME)

# reconstrói o projeto do zero
re: fclean all

# declara que estes alvos não são arquivos
.PHONY: all clean fclean re