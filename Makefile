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
PRINTF_SRCS = $(PRINTF_DIR)*.c
PRINTF_OBJ = $(PRINTF_SRCS: .c=.o)

CC =  gcc 
FLAGS = -Wall -Wextra -Werror 
RM = rm -f 

all: $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS) 
	@$(CC) $(CFLAGS) $(PRINTF_OBJ) $(CLIENT_OBJS) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS) 
	@$(CC) $(CFLAGS) $(PRINTF_OBJ) $(SERVER_OBJS) -o $(SERVER_NAME)



bonus : $(BONUS_NAMEC) $(BONUS_NAMES)
$(BONUS_NAMEC) : $(BONUSC_OBJ)
	@$(CC) $(CFLAGS) $(PRINTF_OBJ) $(BONUSC_OBJ) -o $(BONUS_NAMEC)
$(BONUS_NAMES) : $(BONUSS_OBJ)
	@$(CC) $(CFLAGS) $(PRINTF_OBJ) $(BONUSS_OBJ) -o $(BONUS_NAMES)


clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(RM) $(PRINTF_DIR)*.o 
	$(RM) $(BONUSS_OBJ)
	$(RM) $(BONUSC_OBJ)
	

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)
	$(RM) $(BONUS_NAMEC) $(BONUS_NAMES)

 

re: fclean all

.PHONY = re clean fclean all bonus