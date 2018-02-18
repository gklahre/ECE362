##
## Makefile 
##

CC	= gcc

CFLAGS	= -Wall -Wshadow -Werror -Wvla -Wunreachable-code -g

VAL = valgrind --tool=memcheck --leak-check=full

## Build rule

proj1: main.c huff.c huff.h
	$(CC) $(CFLAGS) huff.c main.c -o proj1

clean:	
	rm -f Proj1.o

valgrind: proj1
	$(VAL) proj1 -c char_based_header/lorum.hch output/huffCode.code output/uncomp.code
valgrind2: proj1
	$(VAL) proj1 -b bit_based_header/lorum.hbt output/uncomp.bc  
%.o:	%.c
	$(CC) $(CFLAGS) -c $<
