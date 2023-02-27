# Librairy names
SERVER_NAME = server
CLIENT_NAME = client


SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

PRINTF_DIR = ft_printf/


#compiler && flags
CC =  gcc 
FLAGS = -Wall -Wextra -Werror 
RM = rm -f 
INCLUDES = -I$(PRINTF_DIR)



all: $(SERVER_NAME) $(CLIENT_NAME)


#pour faire les compilations des mes server + clients
$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(PRINTF_DIR)*.c $(CLIENT_OBJS) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(PRINTF_DIR)*.c $(SERVER_OBJS) -o $(SERVER_NAME)
	

# Pour supprimer les .o qu' on a genere
clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(RM) $(PRINTF_DIR)*.o 
	
# on clean tout donc .o et les exe
fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)
	# $(RM) $(PRINTF_DIR)$(PRINTF)


re: fclean all

.PHONY = re clean fclean all