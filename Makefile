CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SV_FILE = server.c
SV_OBJ = $(SV_FILE:.c=.o)

CLIENT_FILE = client.c
CLIENT_OBJ = $(CLIENT_FILE:.c=.o)

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SV_OBJ)
	$(CC) $(FLAGS) $(SV_OBJ) -o server

$(CLIENT) : $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -o client

clean :
	$(RM) $(SV_OBJ) $(CLIENT_OBJ)

fclean : clean
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY : clean

