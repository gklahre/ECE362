#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packing.h"



int main(int argc, char ** argv){
	if(argc != 5){
		return EXIT_FAILURE;
	}
	clock_t first = clock();
	Tree * t = Load_binary_tree(argv[1]);
	if(t == NULL){
		printf("Something has gone wrong in loading.");
		return EXIT_FAILURE;
	}
	clock_t second = clock();
	Print_Postorder(t,argv[2]);
	clock_t third = clock();
	//PrintInorder(t,argv[3]);
	Packing_it_in(t);
	clock_t forth = clock();
	printSize(t,argv[3]);
	clock_t fifth = clock();
	printCoor(t,argv[4]);
	clock_t sixth = clock();

	clock_t load = (second - first)/ CLOCKS_PER_SEC;
	clock_t pP = (third - second)/ CLOCKS_PER_SEC;
	clock_t pack = (forth - third)/ CLOCKS_PER_SEC;
	clock_t dim = (fifth - forth)/ CLOCKS_PER_SEC;
	clock_t coor = (sixth - fifth)/ CLOCKS_PER_SEC;
	prinf("Load: %f\nPostorder: %f\nPacking: %f\nDimensions: %f\nCoordinates: %f\n",load,pP,pack,dim,coor);
	deallocateTree(t);


	return EXIT_SUCCESS;
}
