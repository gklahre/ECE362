
#ifndef SORT_H_
#define SORT_H_

typedef struct _Node{
	long value;
	struct _Node * next;
} Node;

typedef struct _List {
	struct _Node * node;
	struct _List * next;
	//struct _List * last;
} List;


long * Load_Into_Array(char * filename,int * size);
Node * Load_Into_List(char * filename);
int Save_From_List(char * filename,Node * head);
int Save_From_Array(char * filename,long * array,int size);
Node * Shell_Sort_List(Node * n,double * nCmps);
void Shell_Sort_Array(long * array,int size,double * nCmps);
#endif //Sort_H
