#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
static long PrintSorted(long * array,char * filename,long size);
static int CheckArray(long * array, long size);
static long * ImportNumbers(char * filename,long * size);


int main(int argc, char ** argv){
	if(argc!= 3){
		return EXIT_FAILURE;
	}
	int a = 2;
	long * array;
	long size;
	array = ImportNumbers(argv[1],&size);
	if(array == NULL){
		printf("Import failure.\n");
		return EXIT_FAILURE;
	}
	if(a == 1){
		MergeSort(array,size);
	}
	if(a == 2){
		quicksort(array,size);
	}
	if(array == NULL){
		printf("Sort failure\n");
		return EXIT_FAILURE;
	}
	int b = CheckArray(array,size);
	printf("Array sorted:%d\n",b);
	if(b==0){
		free(array);
		return EXIT_FAILURE;
	}
	PrintSorted(array,argv[2],size);
	

	free(array);
	return EXIT_SUCCESS;

}
static long PrintSorted(long * array,char * filename, long size){
	FILE* fp = fopen(filename,"w");
	if(fp == NULL){
		return EXIT_FAILURE;
	}
	fwrite(array,sizeof(long),size,fp);
	fclose(fp);
	return EXIT_SUCCESS;
}
static int CheckArray(long * array,long size){
	long i = 1;
	printf("len:%ld\n",size);
	while(i<size && array[i-1]<array[i]){
		i++;
	}
	if(i < size){
		printf("%ld\n",i);
		return(0);
	}
	return(i);
}
static long * ImportNumbers(char * filename,long * size){
	FILE * fp = fopen(filename,"r");
	if(fp == NULL){
		printf("Bad import name.\n");
		return NULL;
	}
	fseek(fp,0,SEEK_END);
	*size = ftell(fp);
	if((*size)%sizeof(long) != 0){
		fclose(fp);
		printf("Improper format.\n");
		return NULL;
	}
	*size = (*size)/sizeof(long);
	if(size == 0){
		fclose(fp);
		printf("File is empty.\n");
		return NULL;
	}
	printf("El:%ld\n",*size);
	long * array = malloc((*size)*(sizeof(long)));
	if(array == NULL){
		fclose(fp);
		printf("Malloc failed.");
		return NULL;
	}
	fseek(fp,0,SEEK_SET);
	fread(array,(*size)*sizeof(long),1,fp);
	fclose(fp);
	return array;	
}
