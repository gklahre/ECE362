#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

void Merge_Sort(long * array, int size){
	//Not going to lie: if you had made it return the array rather than void I could skip the copy step and save a lot of time. But alas...constraints.
	if(size == 1 || size == 0){
		return;
	}
	long * aux = malloc(size*sizeof(long));
	long * ret = MergeSortArray(array,aux,size,1);
	if(ret == array){
		free(aux);
	}else{
		int i;
		for(i=0;i<size;i++){
			array[i] = aux[i];
		}	
		free(aux);
	}
	return;
}
long * MergeSortArray(long * array, long * aux, int total, int size){
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
long theMerge(long * array,long * aux,int first_min,int first_max,int sec_min,int sec_max,int loc){
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


long Quick_Sort(long * array,int size){
	QHelp(array,0,size-1);
	return EXIT_SUCCESS;
}

void QHelp(long * array,int front,int back){
	//Efficency notes: Check to see if changing which while loop has the equal sign has any effect on performance time.
	long pivot;
	if(back - front <= 1){
		return;
	}
	if(back - front < 3){
		pivot = array[front];
	}else{
		pivot = MedianPivot(array,front,back);
	}
	int pivot_loc = lineswap(array,front,back,pivot);

	QHelp(array,front,pivot_loc); //pivot loc is made up. Will need to be updated.
	QHelp(array,pivot_loc+1,back);
	return;	
}

long MedianPivot(long * array,int front,int back){
	int rng = (back - front);
	int lg = 0;
	if(rng > 3125){
		while(rng >= 5){
			rng = rng / 5;
			lg++;
		}
		lg = (lg/2) + 1;
		return median_insertion_sort(array,front,back,lg);		
	}else{
		return BestOfThree(array,front,back);
	}
}

long BestOfThree(long * array, int front, int back){
	int mid = (front + back)/2;
	if(array[front]> array[back]){
		if(array[back]>array[mid]){
			//swap(array,front,back);
			return array[back];
		}
		if(array[front]>array[mid]){
			//swap(array,front,mid);
			return array[mid];
		}
		return array[front];
	}else{
		if(array[mid]>array[back]){
			//swap(array,front,back);
			return array[back];
		}
		if(array[mid]>array[front]){
			//swap(array,front,mid);
			return array[mid];
		}
		return array[front];
	}
}

long median_insertion_sort(long * array, int front, int back, int points){
	//Using insertion sort to find the median because it is efficient on small arrays. I'm assuming this is allowed. If not.....................Please notify me by email so I can do a quick correction.
	int range = back - front;
	int gap =  range / points;
	int med =  (points / 2) + 1;
	int i = 1;
	int k;
	long x;
	while(i < points){
		x = array[front + i * gap];
		k = i - 1;
		while(k>=0 && x < array[front + gap * k]){
			array[front + gap * (k + 1)] = array[front + gap * k];
			k--;
		}
		array[front + gap * (k+1)] = x;
		i++;
	}
	//swap(array,front,(front + gap * med));
	return array[front + (gap * med)];
}

int lineswap(long * array,int front,int back,long pivot){
	while(1){
		while(pivot > array[front]&& front <= back){
			front++; 
		}
		while(pivot < array[back] && back>= front){
			back--;
		}
		if(front>=back){
			return back;
		}
		swap(array,front,back);
		//printf("here.\n");
	}
}

void swap(long * array,int first,int second){
	long temp = array[first];
	array[first] = array[second];
	array[second] = temp;
	return;
}





