.PHONY =all clean
AR=ar
CC=gcc
FLAGS= -Wall -g
all: libmylib.a stringProg
stringProg: main.o libmylib.a
	$(CC) $(FLAGS) -o stringProg main.o libmylib.a
libmylib.a:string.o
	$(AR) -rcs libmylib.a string.o
string.o:string.c stringlib.h
	$(CC) $(FLAG) -c string.c stringlib.h
main.o:main.c stringlib.h
	$(CC) $(FLAGS) -c main.c 
clean:
	rm -f *.o *.a *.so *.out *.gch stringProg
