# Compiler
CC = g++

# Compiler flags
CFLAGS = -Imyheaders

# Source files
SRCS = driver.cpp src/stack.cpp

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = dsprogram

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule to build the object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean the build directory
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: clean
