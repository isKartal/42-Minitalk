NAME = minitalk
SERVER = server.c
CLIENT = client.c
FLAGS = -Wall -Wextra -Werror
SOBJS = server
COBJS = client
SERVER_OBJS = $(SERVER:.c=.o)
CLIENT_OBJS = $(CLIENT:.c=.o)

$(NAME): all

all: server client

server: $(SERVER_OBJS)
	gcc -o server $(FLAGS) $(SERVER_OBJS)

client : $(CLIENT_OBJS)
	gcc -o client $(FLAGS) $(CLIENT_OBJS)

clean:
	rm -f server.o client.o

fclean: clean
	rm -f server
	rm -f client

re: fclean all
