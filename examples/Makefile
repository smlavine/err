# Flags
CPPFLAGS =
CFLAGS = -std=c89 -Wall -Wextra -pedantic `sdl2-config --cflags`
LDFLAGS = -L$(PREFIX)/lib `sdl2-config --libs`

# compiler and linker
CC = cc

examples = files hello sdl weekday

all: options $(examples)

options:
	@echo 'examples build options:'
	@echo "CPPFLAGS = $(CPPFLAGS)"
	@echo "CFLAGS   = $(CFLAGS)"
	@echo "LDFLAGS  = $(LDFLAGS)"
	@echo "CC       = $(CC)"

files: files.c ../err.c
	$(CC) -o $@ $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $?

hello: hello.c ../err.c
	$(CC) -o $@ $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $?

sdl: sdl.c ../err.c
	$(CC) -o $@ $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $?

weekday: weekday.c ../err.c
	$(CC) -o $@ $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $?

clean:
	rm -f $(examples)

.PHONY: all options $(examples) clean
