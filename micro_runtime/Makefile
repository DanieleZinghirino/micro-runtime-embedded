TARGET := micro_runtime
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build

CC := gcc

C_STD := -std=c11

WARNINGS := -Wall -Wextra -Werror
OPTIMIZE := -O2
DEBUG_FLAGS := -g3

INCLUDES := -I$(INC_DIR)

CFLAGS := $(C_STD) $(WARNINGS) $(OPTIMIZE)
LDFLAGS :=

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEPS := $(OBJ:.o=.d)

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

debug: CFLAGS := $(C_STD) $(WARNINGS) $(DEBUG_FLAGS) $(INCLUDES)
debug: clean all

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)

.PHONY: all clean debug