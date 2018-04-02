#ifndef SORTING_H
#define SORTING_H

void Merge_Sort(long * array,int size);
long * MergeSortArray(long * array,long * aux,int total,int size);
long Quick_Sort(long * array,int size);
void QHelp(long * array,int front, int back);
long MedianPivot(long * array,int front,int back);
long BestOfThree(long * array,int front,int back);
int lineswap(long * array,int front,int back,long pivot);
void swap(long * array,int first,int second);
long theMerge(long * array,long * aux,int f_min,int f_max,int s_min,int s_max,int loc);
long median_insertion_sort(long * array, int front, int back, int points);

#endif //SORTING_H

