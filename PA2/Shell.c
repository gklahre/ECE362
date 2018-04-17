#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

static List * Create_lists(Node * head,int n);
static Node * disolveLists(List * head);
static Node * Shell_list_help(Node * head,int n,int size,double * swaps);
static Node * insertion_sort_list(Node * head,double * swaps);
static int Shell_Sort_Array_help(long * array,int ArraySize,int n,double * swps);

void Shell_Sort_Array(long * array,int size,double * cmp){
	printf("sized:%d\n",size);
	Shell_Sort_Array_help(array,size,1,cmp);
	return;
}

static int Shell_Sort_Array_help(long * array,int ArraySize,int n, double * swaps){
	int a; //Success checker.
	if(n < ArraySize){
		a = Shell_Sort_Array_help(array,ArraySize,(3*n)+1,swaps);
	}else{
		return EXIT_SUCCESS;
	}
	int i = 1; //Place within k-th array of first unsorted.
	int k = 0; //Offset in array. Starts at 0 and increments until 1 less than n.
	int s = (ArraySize - k) / n; //Size of k-th array. 
	int j; //Place within k-th array for sorting
	long temp; //Temporary variable for long swaping
	while(k<n){
		s = (ArraySize - k) / n;
		while(i<s){
			j = i;
			while(j> 0  && array[n*j+k]<array[n*(j-1)+k]){
				temp = array[(n*(j-1))+k];
				array[(n*(j-1))+k] = array[(n*j)+k];
				array[(n*j)+k] = temp;
				j--;
				(*swaps)++;
			}
			(*swaps)++;
			i++;
		}
		k++;
	}
	return EXIT_SUCCESS;
}

Node * Shell_Sort_List(Node * head,double * swaps){
	//Bunch of checks at the beginning to make sure the list is proper.
	Node * current = head;
	if(head == NULL){
		return NULL;
	}
	int size = 1;
	while(current->next != NULL){
		size++;
		current = current->next;
	}
	printf("size:%d\n",size);
	head = Shell_list_help(head,size,1,swaps);
	return head;	
}

static Node * Shell_list_help(Node * head,int size, int n,double * swaps){
	if(n >= size){
		return head;
	}else{
		head = Shell_list_help(head,size,(3*n)+1,swaps);
	}
	List* l = Create_lists(head,n);
	List *sec = l;
	int i = 0;
	while(i < n){
		sec->node = insertion_sort_list(sec->node,swaps);
		sec = sec->next;
		i++;
	}
	head = disolveLists(l);
	return head;
}


//Badly needs revision
/*
static Node * insertion_sort_list(Node * head){
	Node * SortedT = head;
	head = head->next;
	Node * current = SortedT;
	current->next = NULL;
	while(head!=NULL){
		//NEED CORNER CASE: First & LAST
		while(head->value < current->value){
			current = current->next;
		}
		current->next = head
		head = head->next;
		current->next->next = NULL;
		current = SortedT;

	}	
}
*/
static Node * insertion_sort_list(Node * head,double * swaps){
	Node * sortedT = head;
	Node * unsortedT = head->next;
	sortedT->next = NULL;
	Node * curS;
	Node * prevS;
	Node * temp;
	while(unsortedT != NULL){
		curS = sortedT;
		prevS = NULL;
		while(curS != NULL && unsortedT->value > curS->value){
			(*swaps)++;
			prevS = curS;
			curS = curS->next;
		}
		(*swaps)++;
		temp = unsortedT;
		unsortedT = unsortedT->next;
		if(curS == NULL){
			temp->next = NULL;
		}else{
			temp->next = curS;
		}
		if(prevS == NULL){
			sortedT = temp;
		}else{
			prevS->next = temp;
		}
	}
	return sortedT;
}

static List * Create_lists(Node * head,int n){
	int i = 1;
	List * l = malloc(sizeof(List));
	l->next = NULL;
	l->node = head;
	head = head->next;
	l->node->next = NULL;
	List * prev = l;
	Node * temp;
	List * cur = l;
	while(i<n){
		cur = malloc(sizeof(List));
		cur->node = head;
		head = head->next;
		cur->node->next = NULL;
		cur->next = NULL;
		prev->next = cur;
		prev = cur;
		i++;
	}
	cur->next = l;
	cur = l;
	while(head != NULL){
		temp = cur->node;
		cur->node = head;
		head = head->next;
		cur->node->next = temp;
		cur = cur->next;
	}	
	return l;
}

static Node * disolveLists(List * l){
	Node * head;
	List * curL;
	Node * curN;
	head = l->node;
	l->node = l->node->next;
	curL = l->next;
	curN = head;
	List * temp;
	while(curL->node != NULL){
		curN->next = curL->node;
		curL->node = curL->node->next;
		curL = curL->next;
		curN = curN->next;
	}

	l = curL->next;
	curL->next = NULL;
	while(l != NULL){
		temp = l->next;
		free(l);
		l = temp;
	}
	return head;
}

long * Load_Into_Array(char * filename,int * size){
	FILE * fp = fopen(filename,"r");
	if(fp == NULL){
		fclose(fp);
		return NULL;
	}	
	fseek(fp,0,SEEK_END);
	long i = ftell(fp);
	if(i%sizeof(long) != 0){
		fclose(fp);
		return NULL;
	}
	long * array = malloc(i);
	if(array == NULL){
		fclose(fp);
		return NULL;
	}
	fseek(fp,0,SEEK_SET);
	fread(array,i,1,fp);
	fclose(fp);
	(*size) = i/sizeof(long);
	return array;
}

Node * Load_Into_List(char * filename){
	long i;//EOF check
	long a;
	FILE* input = fopen(filename,"r");
	if(input == NULL){
		fclose(input);
		return NULL;
	}
	fseek(input,0,SEEK_END);
	i = ftell(input);
	if(i%sizeof(long) != 0){
		fclose(input);
		return NULL;
	}
	i = i/sizeof(long);
	if(i == 0){
		fclose(input);
		return NULL;
	}
	fseek(input,0,SEEK_SET);
	Node * cur;
	Node * prev = malloc(sizeof(Node));
	fread(&a,1,sizeof(long),input);
	prev->value = a;
	i--;
	Node * head = prev;
	while(i > 0){
		fread(&a,1,sizeof(long),input);
		cur = malloc(sizeof(Node));
		cur->value = a;
		cur->next = NULL;
		prev->next = cur;
		prev = cur;
		i--;
	}
	printf("here.\n");
	fclose(input);
	return head;
}

int Save_From_List(char * filename,Node * head){
	FILE * output = fopen(filename,"w");
	if(output == NULL){
		return EXIT_FAILURE;
	}
	//long L;
	Node * temp;
	while(head != NULL){
		fwrite(&(head->value),1,sizeof(long),output);
		temp = head->next;
		free(head);
		head = temp;
	}
	fclose(output);
	return EXIT_SUCCESS;
}

int Save_From_Array(char * filename,long * array, int size){
	FILE * output = fopen(filename,"w");
	if(output == NULL){
		return EXIT_FAILURE;
	}
	//Might want to go with for loop instead.
	fwrite(array,sizeof(long),size,output);
	fclose(output);
	free(array);
	return EXIT_SUCCESS;
}
