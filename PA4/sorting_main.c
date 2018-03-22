#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"


int main(int argv, char ** argc){
	if(argv!= 3){
		return EXIT_FAILURE;
	}
	int a = 1;
	int * array;
	array = import_numbers(argv[1]);
	if(a == 1){
		merge_sort(array);
	}
	if(a == 2){
		quicksort(array);
	}
	int b = check_array(array);
	printf("Array sorted:%d/n",b);
	if(b==0){
		return EXIT_FAILURE;
	}
	print_sorted(array,argv[2]);
	

	free(array);
	return EXIT_SUCCESS;

}