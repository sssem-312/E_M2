LIBNAME = libmstat.a
SRC = mstat.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
CFLAGS = -Wall -g
all: $(LIBNAME) main
# Создание статической библиотеки
$(LIBNAME): mstat.o
	ar rcs $@ $^
mstat.o: mstat.cpp mstat.h
	$(CC) $(CFLAGS) -c mstat.cpp
main.o: main.cpp mstat.h
	$(CC) $(CFLAGS) -c main.cpp
main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L. -lmstat
clean:
	rm -f $(OBJ) $(LIBNAME) main
.PHONY: all clean