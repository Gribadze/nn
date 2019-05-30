MD = mkdir -p
RM = rm -rf
# sources
SRC_DIR = src
_SOURCES = main.cpp Neuron.cpp Layer.cpp Matrix.cpp
SOURCES = $(patsubst %,$(SRC_DIR)/%, $(_SOURCES));
# dependencies
INCLUDE_DIR = include
_DEPS = NN/Activation.h NN/Neuron.h NN/Matrix.h NN/Layer.h
DEPS = $(patsubst %,$(INCLUDE_DIR)/%, $(_DEPS))
# target
BIN_DIR = bin
MAIN_TARGET = $(BIN_DIR)/nn
OBJ_DIR = $(BIN_DIR)/obj
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o, $(SOURCES))
# compiler
CC = g++
CFLAGS = -I$(INCLUDE_DIR) -g
# build options
all: clean directories $(MAIN_TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) -c $(CFLAGS) $< -o $@

$(MAIN_TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(BIN_DIR)

directories:
	$(MD) $(BIN_DIR)
	$(MD) $(OBJ_DIR)

