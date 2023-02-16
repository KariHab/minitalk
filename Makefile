SERVER = server
CLIENT = client 


#compiler && flags
CC =  gcc 
FLAGS = -Wall -Wextra -Werror 
RM = rm -f 

SRC = client.c\
	  server.c 


OBJS	=	$(SRCS:.c=.o)

LIBFT = libft.a
LDIR = libft/

# Pour obtenir les .o de chaque .c 
$(NAME): $(OBJS) $(LDIR)$(LIBFT)
	cp $(LDIR)$(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

all: $(LDIR)$(LIBFT) $(SERVER) $(CLIENT)

# pour make la libft
$(LDIR)$(LIBFT):
	$(MAKE) -C $(LDIR)

$(SERVER) : 

$(CLIENT) : 


# Pour supprimer les .o qu' on a genere
clean:
	$(RM) $(OBJS)
	$(RM) $(LDIR)*.o

# on clean tout donc .o et les exe
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LDIR)$(LIBFT)


re: fclean all

.PHONY = re clean fclean all	