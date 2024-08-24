# Через make не получилось, поэтому каждый раз в новом терминале:
# export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH

LIBNAME = libmdyn.so
SRC = mdyn.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
CFLAGS = -Wall -fPIC

all: $(LIBNAME) main

$(LIBNAME): mdyn.o
	$(CC) -shared -o $@ $^

# Компиляция объекта mdyn.o
mdyn.o: mdyn.cpp mdyn.h
	$(CC) $(CFLAGS) -c mdyn.cpp

# Компиляция объекта main.o
main.o: main.cpp mdyn.h
	$(CC) $(CFLAGS) -c main.cpp

# Создание исполняемого файла
main: main.o $(LIBNAME)
	$(CC) -o $@ $^ -L. -lmdyn

clean:
	rm -f $(OBJ) $(LIBNAME) main

.PHONY: all clean