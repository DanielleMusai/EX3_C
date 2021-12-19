AR= ar
CC = gcc
NAME_ = stringProg
FLAGS = -Wall -Werror -g

all : $(NAME_)
$(NAME_): $(stringProg.o)
	$(CC) $(stringProg.o) -o $(NAME_)
stringProglib.o: stringProglib.c stringProglib.h
	$(CC) $(FLAGS) -c stringProglib.c
stringProg.o: stringProg.c
	$(CC) $(FLAGS) -c stringProg.c

.PHONY = all clean
clean:
	rm -f *.o *.a stringProg
