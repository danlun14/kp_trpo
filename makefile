CC = gcc
CFLAGS = -c –Wall -Werror
EXECUTABLE = main
SOURCES = src/main.c src/command.c src/str.c
OBJECTS=$(SOURCES: .c=.o)

all:	$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o build/$@

clean:
	rm -rf *.o *.exe