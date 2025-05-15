CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = build/queue-array

BUILD_DIR = build

SRCS = main.c queue-array.c
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(BUILD_DIR) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: $(TARGET)
	@printf "\n"
	@printf "Running: "
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean