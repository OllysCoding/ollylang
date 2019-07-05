CFLAGS = -O
CC = g++
SRC = src/main.cpp src/logger.cpp
OBJ = $(SRC:.cpp = .o)
lang: $(OBJ)
	$(CC) $(CFLAGS) -o lang $(OBJ)
clean:
	rm -f core *.o 