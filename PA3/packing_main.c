#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "packing.h"



int main(int argc, char ** argv){
	if(argc != 5){
		return EXIT_FALIURE
	}
	clock_t first = clock();
	Tree * t = Load_binary_tree(argv[1]);
	if(t == NULL){
		printf("Something has gone wrong in loading.");
		return EXIT_FAILURE;
	}
	clock_t load = clock();
	Print_Postorder(t,argv[2]);
	clock_t post = clock();
	deallocateTree(t);
	clock_t loadFin = load - first;
	clock_t pP = post - load;
	clock_t 
	return EXIT_SUCCESS;
}
