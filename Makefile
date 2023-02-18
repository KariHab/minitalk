SERVER = server
CLIENT = client 


#compiler && flags
CC =  gcc 
FLAGS = -Wall -Wextra -Werror 
RM = rm -f 

SRC = client.c\
	  server.c 


OBJS	=	$(SRCS:.c=.o)

PRINTF = libftprintf.a
PRINTF_DIR = ft_printf/
# Pour obtenir les .o de chaque .c 
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(SERVER) $(CLIENT)

# pour make la libft


$(SERVER) : 

$(CLIENT) : 


# Pour supprimer les .o qu' on a genere
clean:
	$(RM) $(OBJS)


# on clean tout donc .o et les exe
fclean: clean
	$(RM) $(NAME)



re: fclean all

.PHONY = re clean fclean all	