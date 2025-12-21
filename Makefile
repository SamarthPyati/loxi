CC=cc
OPT=-O0
DEBUG=1
INCLUDES=-I.
CFLAGS=-Wall -Wextra -std=c17 $(OPT) $(INCLUDES)

DEPS=interpreter.c

TARGET=loxc

all: build 

build: $(DEPS)
ifeq ($(strip $(DEBUG)), 1)
	$(CC) $(CFLAGS) -g -o $(TARGET) $<
else
	$(CC) $(CFLAGS) -o $(TARGET) $< 
endif

# Doing platform check
platform_check: 
	$(info System  : $(shell uname -m))
	$(info Platform: $(shell uname -s))		

platform:=$(shell uname -s)

.PHONY: clean
clean: $(TARGET)
	@echo "Removing build artifacts ..."
	@rm $(TARGET)

ifeq ($(platform), Darwin)
	@echo "Platform: $(platform)"
	@rm -rf $(TARGET).dSYM
else 
	($error "Unknown platform: $(platform)")
endif