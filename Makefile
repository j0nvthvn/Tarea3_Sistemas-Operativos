# Makefile
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Iinclude

SRCDIR = src
BUILDDIR = build
BINDIR = bin
TARGET = $(BINDIR)/tarea3

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

.PHONY: all clean run debug

all: $(BINDIR) $(TARGET)

$(BINDIR):
	mkdir -p $(BINDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(TARGET): $(BUILDDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) $(BINDIR)

run: all
	./$(TARGET)

debug: CFLAGS += -g
debug: clean all
