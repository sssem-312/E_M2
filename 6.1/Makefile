LIBNAME = libmstat.a
SRC = mstat.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
# Опции компилятора
CFLAGS = -Wall -g

all: $(LIBNAME) main

# Создание статической библиотеки
$(LIBNAME): mstat.o
	ar rcs $@ $^

# Компиляция объекта mstat.o
mstat.o: mstat.cpp mstat.h
	$(CC) $(CFLAGS) -c mstat.cpp

# Компиляция объекта main.o
main.o: main.cpp mstat.h
	$(CC) $(CFLAGS) -c main.cpp

# Создание исполняемого файла
main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L. -lmstat

clean:
	rm -f $(OBJ) $(LIBNAME) main

.PHONY: all clean