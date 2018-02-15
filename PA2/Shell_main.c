#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char ** argv){
	if(argc != 5){
		return EXIT_FAILURE;
	}
	if(argv[1] != 1){
		return EXIT_FAILURE;
	}
	double comps;

	clock_t start,fine,io,sort;
	start = clock()
	Node * L = Load_into_list(argv[2]);
	io = clock();
	L = Shell_Sort_List(L,&comps);
	sort = clock();
	Save_From_List(L,argv[3]);
	fine = clock();
	double Sort_time = (sort - io) / CLOCKS_PER_SEC;
	printf("Sort Time: %d",Sort_time);
	int size;
	double comps2;

	long * array = Load_Into_Array(argv[2],&size);
	Shell_Sort_Array(array,size,&comps2);
	Save_From_Array(array,argv[4],size);
	return EXIT_SUCCESS;
}