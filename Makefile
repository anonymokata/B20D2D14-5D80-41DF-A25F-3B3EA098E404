CC = gcc
CFLAGS = -Wall -I./include
LIBS = -L./lib

.PHONY: test clean

all: lib/libRomanNumberMath.so lib/libRomanNumberMathDebug.so bin/RomanNumberMathTest

test: 
	bin/RomanNumberMathTest

clean:
	rm -rf bin/* obj/* lib/*

lib/libRomanNumberMath.so: obj/RomanNumberMath.o
	$(CC) --shared -o $@ $^

lib/libRomanNumberMathDebug.so: obj/RomanNumberMathDebug.o
	$(CC) --shared -o $@ $^

bin/RomanNumberMathTest: obj/tests.o lib/libRomanNumberMathDebug.so
	$(CC) -o $@ $< $(shell pkg-config --libs check) $(LIBS) -lRomanNumberMathDebug -Wl,-rpath,./lib

obj/RomanNumberMath.o: src/RomanNumberMath.c
	$(CC) -c -fPIC $(CFLAGS) -o $@ $^

obj/RomanNumberMathDebug.o: src/RomanNumberMath.c
	$(CC) -c -g -fPIC $(CFLAGS) -o $@ $^

obj/tests.o: test/RomanNumberMath.c
	$(CC) -c -g $(CFLAGS) $(shell pkg-config --cflags check) -o $@ $(LIBS) $^

