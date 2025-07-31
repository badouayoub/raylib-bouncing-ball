CC= gcc
CFLAGS = -g -Wall -Wextra
LDFLAGS = $(shell pkg-config --libs --cflags raylib)
SOURCE_DIR = src
SOURCE = $(SOURCE_DIR)/ball.c
TARGET_DIR = build
TARGET = $(TARGET_DIR)/ball

all:
	$(CC) $(SOURCE) $(CFLAGS) $(LDFLAGS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -rf $(TARGET_DIR)/*

gen:
	jq --null-input '[{"directory": "$(shell pwd)", "file": "$(SOURCE)", "command": "$(CC) $(SOURCE) $(CFLAGS) $(LDFLAGS) -O $(TARGET)"}]' > compile_commands.json
