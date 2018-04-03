#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"
#include <string.h>

int main(int argc, char ** argv){
	if(argc != 4){
		return EXIT_FAILURE;
	}
	if(strlen(argv[1]) != 2){
		return EXIT_FAILURE;
	}
	//clock_t start,fine,io,sort;
	//start = clock();
	double comps;
	if(argv[1][1] == 'l'){
		Node * L;
		comps = 0;
		L = Load_Into_List(argv[2]);
		Node * cur = L;
		while(cur != NULL){
			printf("%ld\n",cur->value);
			cur = cur->next;
		}
		printf("\n");
		L = Shell_Sort_List(L,&comps);
		cur = L;
		while(cur != NULL){
			printf("%ld\n",cur->value);
			cur = cur->next;
		}		
		if(L == NULL){
			return EXIT_FAILURE;
		}
		Save_From_List(argv[3],L);
		printf("comps: %f\n",comps);
		return EXIT_SUCCESS;
	}else if(argv[1][1] == 'a'){
		long * array;
		int size = 0;
		int i;
		comps = 0;
		array = Load_Into_Array(argv[2],&size);
		for(i=0;i<size;i++){
			printf("%ld\n",array[i]);
		}
		printf("\n");
		Shell_Sort_Array(array,size,&comps);
		for(i=0;i<size;i++){
			printf("%ld\n",array[i]);
		}	   
		Save_From_Array(argv[3],array,size);
		printf("\nComps: %lf\n",comps);
		return EXIT_SUCCESS;
	}else{
		printf("First argument not -a or -l.");
		return EXIT_FAILURE;
	}
		//double comps;

	//Node * L = Load_into_list(argv[2]);
	//io = clock();
	//L = Shell_Sort_List(L,&comps);
	//sort = clock();
	//Save_From_List(L,argv[3]);
	//fine = clock();
	//double Sort_time = (sort - io) / CLOCKS_PER_SEC;
	//printf("Sort Time: %d",Sort_time);
	//int size;
	//double comps2;

	//long * array = Load_Into_Array(argv[2],&size);
	//Shell_Sort_Array(array,size,&comps2);
	//Save_From_Array(array,argv[4],size);
	//return EXIT_SUCCESS;
}
