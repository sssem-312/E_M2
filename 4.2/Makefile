TARGET = ./4.2.out
HDRS_DIR = \
		4.2
SRCS = \
		4.2.cpp
.PHONY: all, build, clean, run

$(TARGET):
		gcc -I $(HDRS_DIR) $(SRCS) -o $(TARGET)

all: clean build

build: $(TARGET)

clean:
		rm -rf $(TARGET)
run:
		$(TARGET)