CC=gcc
AR= ar
OBJECT= stringProg.o
FLAGS = -Wall -g

all : $(stringProg)
	$(CC) $(OBJECT) -o $(stringProg)

stringProglib.o:  stringProg.c stringProglib.h
$(CC) $(FLAGS) -c  stringProglib.h

stringProg.o: stringProg.c
$(CC) $(FLAGS) -c stringProg.c

.PHONY = clean all

clean:
	rm -f *.o *.a *.so stringProg
	
