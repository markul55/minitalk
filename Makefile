# Nazwy plików wykonywalnych
NAME_SERVER = server
NAME_CLIENT = client

# Pliki źródłowe
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

# Pliki obiektowe
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Libft
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Kompilator i flagi
CC = gcc
CFLAGS = -Wall -Wextra -Werror -no-pie

# Cele główne
all: $(LIBFT_LIB) $(NAME_SERVER) $(NAME_CLIENT)

# Kompilacja serwera
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) $(LIBFT_LIB)

# Kompilacja klienta
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(LIBFT_LIB)

# Kompilacja libft
$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

# Reguła do kompilacji plików .c do .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Czyszczenie obiektów
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C $(LIBFT_DIR) clean

# Całkowite czyszczenie
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make -C $(LIBFT_DIR) fclean

# Rekompilacja wszystkiego
re: fclean all

# Cele phony
.PHONY: all clean fclean re
