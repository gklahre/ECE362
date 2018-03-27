#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

long * MergeSort(long * array, long size){
	if(size == 1 || size == 0){
		return array;
	}
	long * aux = malloc(size*sizeof(long));
	long * ret = MergeSortArray(array,aux,size,1);
	if(ret == array){
		free(aux);
	}else{
		free(array);
	}
	return ret;

}
long * MergeSortArray(long * array, long * aux, long total, long size){
	if(size >= total){
		return array;
	}
	long loc = 0;
	long i = 0;
	long sub_num = 0;
	long first_min, first_max, sec_min, sec_max;
	long num_of_new_subsections = (total/(size*2)); //Calculates the number of merges to take place. Unfortunately, rather complicated.
	while(i < num_of_new_subsections){
		first_min = sub_num * size;
		sub_num++;
		first_max = sub_num * size;
		sec_min = first_max;
		sub_num++;
		sec_max = sub_num * size;
		loc = theMerge(array,aux,first_min,first_max,sec_min,sec_max,loc);
		i++;
	}
	if(total%(size*2)>size){
		loc = theMerge(array,aux,loc,loc+size,loc+size,total,loc);
	}else{
		while(loc < total){
			aux[loc] = array[loc];
			loc++;
		}
	}
	return MergeSortArray(aux,array,total,size*2);	
}
long theMerge(long * array,long * aux,long first_min,long first_max,long sec_min,long sec_max,long loc){
	while(first_min != first_max && sec_min != sec_max){
		if(array[first_min] < array[sec_min]){
			aux[loc] = array[first_min];
			first_min++;
		}else{
			aux[loc] = array[sec_min];
			sec_min++;
		}
		loc++;
	}
	while(first_min != first_max){
		aux[loc] = array[first_min];
		first_min++;
		loc++;
	}
	while(sec_min != sec_max){
		aux[loc] = array[sec_min];
		sec_min++;
		loc++;
	}
	return loc;

}


long quicksort(long * array,long size){
	QHelp(array,0,size-1);
	return EXIT_SUCCESS;
}

long QHelp(long * array,long front, long back){
	//Efficency notes: Check to see if changing which while loop has the equal sign has any effect on performance time.
	long pivot;
	if(back - front <= 1){
		return EXIT_SUCCESS;
	}
	if(back - front < 5){
		pivot = array[front];
	}else{
		pivot = MedianPivot(array,front,back);
	}
	long pivot_loc = lineswap(array,front,back,pivot);

	long i = QHelp(array,front,pivot_loc); //pivot loc is made up. Will need to be updated.
	i = QHelp(array,pivot_loc+1,back);
	return EXIT_SUCCESS;	
}

long MedianPivot(long * array,long front, long back){
	return BestOfThree(array,front,back);
	//Return the median of the five data polongs: first, first quad, median, third quad, last. Swap pivot number to the front.
}

long BestOfThree(long * array, long front, long back){
	long mid = (front + back)/2;
	if(array[front]> array[back]){
		if(array[back]>array[mid]){
			swap(array,front,back);
			return array[front];
		}
		if(array[front]>array[mid]){
			swap(array,front,mid);
			return array[front];
		}
		return array[front];
	}else{
		if(array[mid]>array[back]){
			swap(array,front,back);
			return array[front];
		}
		if(array[mid]>array[front]){
			swap(array,front,mid);
			return array[front];
		}
		return array[front];
	}
}

long lineswap(long * array,long front, long back, long pivot){
	while(1){
		while(pivot > array[front] && front <= back){
			front++; 
		}
		while(pivot < array[back] && back >= front){
			back--;
		}
		if(front>=back){
			return back;
		}
		swap(array,front,back);
	}

}

void swap(long * array,long first, long second){
	long temp = array[first];
	array[first] = array[second];
	array[second] = temp;
	return;
}





