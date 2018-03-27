#include <stdio.h>
#include <stlib.h>
#include "sorting.h"

int * merge_sort(int * array){
	int a = sizeof(array);
	if(a == 1 || a == 0){
		return array;
	}
	int * aux = malloc(a*sizeof(int));
	int * ret = merge_sort_array(array,aux,a,1);
	if(ret == array){
		free(aux);
	}else{
		free(array);
	}
	return ret;
}

int * merge_sort_array(int * arary, int * aux, int total, int size){
	if(size >= total){
		return array;
	}
	int loc = 0;
	int i = 0;
	int sub_num = 0;
	int first_min, first_max, sec_min, sec_max;
	int num_of_new_subsections = (total/(size*2)); //Calculates the number of merges to take place. Unfortunately, rather complicated.
	while(i < num_of_new_subsections){
		first_min = sub_num * size;
		sub_num++;
		first_max = sub_num * size;
		sec_min = first_max;
		sub_num++;
		sec_max = sub_num * size;
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
		i++;
	}
	while(loc < total){
		aux[loc] = array[loc];
		loc++;
	}
	return merge_sort_array(aux,array,total,size*2);	
}

int quicksort(int * array){
	int size = sizeof(array);
	q_help(array,0,size-1);
	return EXIT_SUCCESS;
}

int q_help(int * array,int front, int back){
	//Efficency notes: Check to see if changing which while loop has the equal sign has any effect on performance time.
	if(front-back < 1){
		return EXIT_SUCESS;
	}
	if(back - front < 5){
		pivot = array[front];
	}else{
		int pivot = median_pivot(array,front,back);
	}
	pivot_loc = lineswap(array,front,back);

	q_help(array,front,pivot_loc-1); //pivot loc is made up. Will need to be updated.
	q_help(array,pivot_loc+1,back);
	return EXIT_SUCCESS;	
}

int median_pivot(int * array,int front, int back){
	return best_of_three(array,front,back);
	//Return the median of the five data points: first, first quad, median, third quad, last. Swap pivot number to the front.
}

int best_of_three(int * array, int front, int back){
	int mid = (front + back)/2;
	if(array[front]> array[back]){
		if(array[back]>array[mid]){
			swap(array,front,back);
			return array[front];
		}
		if(array[front]>array[mid])
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

median_insertion_sort(int * array, int front, int back, int points){
	int range = front - back;
	int gap =  range / points
	int med =  (points / 2) + 1;
	int i = 1;
	int j;
	int x;
	while(i < points){
		x = array[front + i * gap];
		j = i - 1;
		while(x < array[front + gap * j] && j >= 0){
			array[front + gap * (j + 1)] = array[front + gap * j];
			j--;
		}
		array[front + gap * (j+1)] = x;
		i++;
	}
	swap(array,front,(front + gap * med));
	return array[front];
}

int lineswap(int * array,int front, int back){
	int tf = front;
	front = front + 1;
	while(1){
		while(pivot > array[front]){
			front++; 
		}
		while(pivot <= array[back]){
			back--;
		}
		if(front<back){
			swap(array,tf,back);
			return back;
		}
		swap(array,front,back);
	}
}

void swap(int * array,int first, int second){
	int temp = array[first];
	array[first] = array[second];
	array[second] = temp;
	return;
}

int print_sorted(int * array,char * filename){
	int i = 0;
	FILE* fp = fopen(filename,"w");
	while(i < len(array)){
		fputs(fp,sizeof(char),1,array[i]);
		i++;
	}
	fclose(fp);
}

int check_array(int * array){
	i = 1;
	while(array[i-1]<array[i] && i<len(array)){
		i++;
	}
	if(i < len(array)){
		return(0);
	}
	return(1);
}