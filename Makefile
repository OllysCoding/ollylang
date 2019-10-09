CFLAGS = -O
CC = g++
SRC = src/main.cpp src/Logger/Logger.cpp src/FileHandler/FileHandler.cpp src/InputStream/InputStream.cpp
OBJ = $(SRC:.cpp = .o)
lang: $(OBJ)
	$(CC) $(CFLAGS) -o lang $(OBJ)
clean:
	rm -f core *.o 