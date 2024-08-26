TARGET = ./main.out
HDRS_DIR = \
		4.3
SRCS = \
		main.cpp \
		4.3.cpp
.PHONY: all, build, clean, run

$(TARGET):
		gcc -I $(HDRS_DIR) $(SRCS) -o $(TARGET)

all: clean build

build: $(TARGET)

clean:
		rm -rf $(TARGET)
run:
		$(TARGET)