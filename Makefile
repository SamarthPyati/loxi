OPT_LEVEL	:= 0
DEBUG		:= 1
CPPFLAGS	:= -Isrc
CFLAGS		:= -Wall -Wextra -std=c17 $(CPPFLAGS)

ifeq ($(strip $(DEBUG)), 1)
CFLAGS += -g -DDEBUG
endif

TARGET	:= loxi
SRC 	:= $(wildcard src/*.c)
OBJ 	:= $(patsubst src/%.c, build/%.o, $(SRC))

# TIP: Ensure the build directory exists before creating object files
$(OBJ): | build

.PHONY: all build clean
all: $(TARGET)

build: 
	@mkdir -p build

build/%.o: src/%.c
	$(CC) $(CFLAGS) -O$(OPT_LEVEL) -c -o $@ $<

$(TARGET): $(OBJ) | build
	$(CC) $(CFLAGS) -O$(OPT_LEVEL) -o $@ $^

platform:=$(shell uname -s)

.PHONY: clean
clean:
	@echo "Removing build artifacts ..."
	@rm -f $(TARGET)
	@rm -rf build

ifeq ($(platform), Darwin)
	@echo "Platform: $(platform)"
	@rm -rf $(TARGET).dSYM
else
	$(error Unsupported platform: $(platform))
endif