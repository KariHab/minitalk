# Librairy names
NAME = 
SERVER = server
CLIENT = client 

PRINTF = ./ft_printf/libftprintf.a
PRINTF_DIR = ./ft_printf


SRC_C = client.c
SRC_S = server.c


#compiler && flags
CC =  gcc 
FLAGS = -Wall -Wextra -Werror 
RM = rm -f 
INCLUDE = -I include


$(NAME): all

all: $(PRINTF_DIR) $(PRINTF) $(SERVER) $(CLIENT)

# pour make la libft
$(PRINTF):
		$(MAKE) -C $(PRINTF_DIR)

#pour faire les compilations des mes server + clients
$(SERVER): $(PRINTF)
	@ $(CC) $(CFLAG) $(SRC_S) $(PRINTF) -o $(SERVER)

$(CLIENT): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_C) $(PRINTF) -o $(CLIENT)


# Pour supprimer les .o qu' on a genere
clean:
	$(RM) $(CLIENT) $(SERVER)
	$(RM) $(PRINTF_DIR)*.o


# on clean tout donc .o et les exe
fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY = re clean fclean all