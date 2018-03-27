#ifndef Sorting_H
#define Sorting_H

long * MergeSort(long * array,long size);
long * MergeSortArray(long * array,long * aux,long total,long size);
long quicksort(long * array,long size);
long QHelp(long * array,long front, long back);
long MedianPivot(long * array,long front,long back);
long BestOfThree(long * array,long front,long back);
long lineswap(long * array,long front,long back,long pivot);
void swap(long * array,long first,long second);
long theMerge(long * array,long * aux,long f_min,long f_max,long s_min,long s_max,long loc);

#endif
//Sorting_H
