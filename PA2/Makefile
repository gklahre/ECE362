##
## Makefile 
##

CC	= gcc

CFLAGS	= -Wall -Wshadow -Werror -Wvla -Wunreachable-code -g

VAL = valgrind --tool=memcheck --leak-check=full

## Build rule

proj2: Shell.c sorting_main.c sorting.h
	$(CC) $(CFLAGS) Shell.c sorting_main.c -o proj2

clean:	
	rm -f proj2.o

valgrind: proj2
	$(VAL) proj2 -a samples/15.b output1.b
valgrind2: proj2
	$(VAL) proj2 -l samples/15.b output2.b 
%.o:	%.c
	$(CC) $(CFLAGS) -c $<
