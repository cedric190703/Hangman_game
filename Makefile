# Compiler
CC = g++
# Compiler flags
CFLAGS = -fsanitize=address -g -lm
# Executable name
EXEC = hangman

# Source files
SOURCES = main.cpp Ascii_code/ascii_code.cpp Game/Board.cpp Game/Game.cpp wordsBank/selectWord.cpp
# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(EXEC)

# Linking object files to create the executable
$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Compiling source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean command to remove object files and executable
clean:
	rm -f $(EXEC) $(OBJECTS)
