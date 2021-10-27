SRC_DIR = src
BUILD_DIR = build/debug
CC = clang++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = main
INCLUDE_PATH = -Iinclude -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2
COMPILER_FLAGS = -std=c++17 -Wall -O0

default:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATH) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME) -g3
