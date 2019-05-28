MD = mkdir -p
RM = rm -rf
CC = g++
BIN_DIR = bin
INCLUDE_DIR = include
MAIN_TARGET = $(BIN_DIR)/nn
OBJ_DIR = $(BIN_DIR)/obj
OBJ = $(addprefix $(OBJ_DIR)/, main.o)
DEPS = $(patsubst %,$(INCLUDE_DIR)/%, NN/Activation.h)
CFLAGS = -I$(INCLUDE_DIR) -g

all: clean directories $(MAIN_TARGET)

$(OBJ_DIR)/%.o: src/%.cpp $(DEPS)
	$(CC) -c $(CFLAGS) $< -o $@

$(MAIN_TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(BIN_DIR)

directories:
	$(MD) $(BIN_DIR)
	$(MD) $(OBJ_DIR)

