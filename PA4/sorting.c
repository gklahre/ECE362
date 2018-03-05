#include <stdio.h>
#include <stlib.h>

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
int merge_sort_array(int * arary, int * aux, int total, int size){
	if(size >= total){
		return array;
	}
	int loc = 0;
	int i = 0;
	int sub_num = 0;
	int first_min, first_max, sec_min, sec_max;
	int num_of_new_subsections = (((total/size)+1)/2); //Calculates the number of merges to take place. Unfortunately, rather complicated.
	while(i < num_of_new_subsections){
		first_min = sub_num * size;
		sub_num++;
		first_max = sub_num * size;
		sec_min = first_max;
		sub_num++;
		second_max = sub_num * size;
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
	int true_front = front;
	int true_back = back;
	while(pivot > array[front]){
		front++; 
	}
	while(pivot <= array[back]){
		back--;
	}

	q_help(array,true_front,pivot_loc); //pivot loc is made up. Will need to be updated.
	q_help(array,pivot_loc,true_back);
	return EXIT_SUCCESS;	
}

int median_pivot(int * array){
	//Return the median of the five data points: first, first quad, median, third quad, last. Swap pivot number to the front.
}
