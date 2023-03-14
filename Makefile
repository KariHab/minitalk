# Librairy names
SERVER_NAME = server
CLIENT_NAME = client
BONUS_NAMEC = client_bonus
BONUS_NAMES = server_bonus

SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
BONUSS_SRCS = server_bonus.c
BONUSS_OBJ = $(BONUSS_SRCS:.c=.o)

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
BONUSC_SRCS = client_bonus.c
BONUSC_OBJ = $(BONUSC_SRCS:.c=.o)

PRINTF_DIR = ft_printf/


#compiler && flags
CC =  gcc 
FLAGS = -Wall -Wextra -Werror 
RM = rm -f 
#INCLUDES = -I$(PRINTF_DIR) + enlever les includes dans gcc 


all: $(SERVER_NAME) $(CLIENT_NAME)


#pour faire les compilations des mes server + clients
$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(PRINTF_DIR)*.c $(CLIENT_OBJS) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(PRINTF_DIR)*.c $(SERVER_OBJS) -o $(SERVER_NAME)
	
#pour les regles du bonus
bonus : $(BONUS_NAMEC) $(BONUS_NAMES)
$(BONUS_NAMEC) : $(BONUSC_OBJ)
	$(CC) $(CFLAGS) $(PRINTF_DIR)*.c $(BONUSC_OBJ) -o $(BONUS_NAMEC)
$(BONUS_NAMES) : $(BONUSS_OBJ)
	$(CC) $(CFLAGS) $(PRINTF_DIR)*.c $(BONUSS_OBJ) -o $(BONUS_NAMES)

# Pour supprimer les .o qu' on a genere
clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(RM) $(PRINTF_DIR)*.o 
	$(RM) $(BONUSS_OBJ)
	$(RM) $(BONUSC_OBJ)
	
# on clean tout donc .o et les exe
fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)
#$(RM) $(PRINTF_DIR)$(PRINTF) 
	$(RM) $(BONUS_NAMEC) $(BONUS_NAMES)
 

re: fclean all

.PHONY = re clean fclean all bonus