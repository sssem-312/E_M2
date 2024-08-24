TARGET = ./main.out
HDRS_DIR = \
		2.1
SRCS = \
		main.cpp \
		2.1.cpp
.PHONY: all, build, clean, run

$(TARGET):
		gcc -I $(HDRS_DIR) $(SRCS) -o $(TARGET)

all: clean build

build: $(TARGET)

clean:
		rm -rf $(TARGET)
run:
		$(TARGET)