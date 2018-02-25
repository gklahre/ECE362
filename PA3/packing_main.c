#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packing.h"



int main(int argc, char ** argv){
	if(argc != 5){
		return EXIT_FALIURE
	}
	Tree * t = Load_binary_tree(argv[1]);
	if(t == NULL){
		printf("Something has gone wrong in loading.");
		return EXIT_FAILURE;
	}
	Print_Postorder(t,argv[2]);
	deallocateTree(t);
	return EXIT_SUCCESS;
}
