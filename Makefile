SRC_DIR = src/
BUILD_DIR = build/debug
CC = clang++
SRC_FILES1 = $(wildcard $(SRC_DIR)/Classes/*.cpp)
SRC_FILES2 = $(wildcard $(SRC_DIR)/Console/*.cpp)
OBJ_NAME = main
INCLUDE_PATH = -Iinclude -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2
COMPILER_FLAGS = -std=c++17 -Wall -O0

default:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATH) ./src/main.cpp $(SRC_FILES1) $(SRC_FILES2) -o $(BUILD_DIR)/$(OBJ_NAME) -g3
