CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SERVER = server
CLIENT = client

SV_FILE = server.c minitalk_utils.c
SV_OBJ = $(SV_FILE:.c=.o)

CLIENT_FILE = client.c minitalk_utils.c
CLIENT_OBJ = $(CLIENT_FILE:.c=.o)

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SV_BONUS_FILE = server_bonus.c minitalk_utils_bonus.c
SV_BONUS_OBJ = $(SV_BONUS_FILE:.c=.o)

CLIENT_BONUS_FILE = client_bonus.c minitalk_utils_bonus.c
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_FILE:.c=.o)

all : $(SERVER) $(CLIENT) 

$(SERVER) : $(SV_OBJ)
	$(CC) $(FLAGS) $(SV_OBJ) -o $(SERVER)

$(CLIENT) : $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -o $(CLIENT)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS) : $(SV_BONUS_OBJ)
	$(CC) $(FLAGS) $(SV_BONUS_OBJ) -o $(SERVER_BONUS)

$(CLIENT_BONUS) : $(CLIENT_BONUS_OBJ)
	$(CC) $(FLAGS) $(CLIENT_BONUS_OBJ) -o $(CLIENT_BONUS)

%.o : %.c minitalk.h
	$(CC) $(FLAGS) -c $< -o $@

%.o : %.c minitalk_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(SV_OBJ) $(CLIENT_OBJ)
	$(RM) $(SV_BONUS_OBJ) $(CLIENT_BONUS_OBJ)

fclean : clean
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)

re : fclean all bonus

.PHONY : clean

