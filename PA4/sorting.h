#ifndef SORTING_H
#define SORTING_H

int * merge_sort(int * array);
int * merge_sort_array(int * array,int * aux,,int total,int size);
int quicksort(int * array);
int q_help(int * array,int front, int back);
int median_pivot(int * array,int front,int back);
int best_of_three(int * array,int front,int back);
int lineswap(int * array,int front,int back);
void swap(int * array,int first,int second);
int print_sorted(int * array,char * filename);
int check_array(int * array);

#endif //SORTING_H