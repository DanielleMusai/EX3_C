.PHONY =all clean
AR=ar
CC=gcc
FLAGS= -Wall -g
all: libmy.a stringProg
stringProg:  libmy.a
	$(CC) $(FLAGS) -o stringProg libmy.a
libmy.a:stringProg.o
	$(AR) -rcs libmy.a stringProg.o
stringProg.o:stringProg.c stringProglib.h
	$(CC) $(FLAG) -c stringProg.c stringProglib.h

clean:
	rm -f *.o *.a *.so *.out *.gch stringProg
