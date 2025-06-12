# Makefile
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
LDFLAGS = -lncurses

# Source files
SRC = ../src/main.c ../lib/ui/tui.c

# Object files
OBJ = $(SRC:.c=.o)

# Output executable name
TARGET = ctyper

# Default target
all: $(TARGET)

# Link the object files into the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

