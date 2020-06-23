CC = gcc
CFLAGS = -Wall -Werror 

.PHONY: clean all

all: ./bin/src/sort ./bin/ctest/test 

./bin/src/sort: ./build/main.o ./build/sort.o ./build/command.o ./build/str.o
		$(CC) $(CFLAGS) -o ./bin/src/sort ./build/main.o ./build/sort.o build/command.o ./build/str.o

./build/main.o: ./src/main.c
		$(CC) $(CFLAGS) -o build/main.o -c src/main.c

./build/sort.o: ./src/sort.c
		$(CC) $(CFLAGS) -o build/sort.o -c src/sort.c

./build/command.o: ./src/command.c
		$(CC) $(CFLAGS) -o build/command.o -c src/command.c

./build/str.o: ./src/str.c
		$(CC) $(CFLAGS) -o build/str.o -c src/str.c

./bin/ctest/test: ./build/tests.o ./build/sort.o ./build/command.o ./build/str.o 
		$(CC) -I thirdparty -I src -Wall -o ./bin/ctest/test  ./build/tests.o ./build/sort.o build/command.o ./build/str.o 

./build/tests.o: ./tests/main.c
		$(CC) -I thirdparty -I src -Wall -o build/tests.o -c tests/main.c

clean:
	rm -rf build/*.o build/*.d

