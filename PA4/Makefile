

CC 	= gcc

CFLAGS	= -Wall -Wshadow -Werror -Wvla -Wunreachable-code -g

VAL 	= valgrind --tool=memcheck --leak-check=full

proj4: sorting.c sorting_main.c sorting.h
	$(CC) $(CFLAGS) sorting.c sorting_main.c -o proj4
clean: 
	rm -f proj4.o
test1: proj4
	$(VAL) proj4 IO/1mil.b IO/output.b
%.o:	%.c
	$(CC) $(CFLAGS) -c $<
