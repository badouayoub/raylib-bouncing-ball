BIN=ball

CC= gcc
CFLAGS = -g -Wall -Wextra
LDFLAGS = $(shell pkg-config --libs --cflags raylib)

SOURCE_DIR = src
TARGET_DIR = build

SOURCE = $(SOURCE_DIR)/$(BIN).c
TARGET = $(TARGET_DIR)/$(BIN)

all:
	$(CC) $(SOURCE) $(CFLAGS) $(LDFLAGS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -rf $(TARGET_DIR)/*

gen:
	compiledb make
