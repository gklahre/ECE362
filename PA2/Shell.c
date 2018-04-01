#include <stdio.h>
#include <stdlib.h>

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
		while(i<s){
			j = i
			if(array[n*j+k]<array[n*(j-1)+k]){
				temp = array[(n*(j-1))+k];
				array[(n*(j-1))+k] = array[(n*j)+k];
				array[(n*j)+k] = temp;
				j--;
				*swaps++;
			}
			i++;
		}
		k++;
	}
	return EXIT_SUCCESS;
}

Node * Shell_Sort_List(Node * head,double * swaps){
	//Bunch of checks at the beginning to make sure the list is proper.
	Node * current = head;
	int size = 0;
	while(current->next != NULL){
		size++;
		current = current->next;
	}
	Shell_list_help(head,size,1,swaps);
	return head;	
}

static Node * Shell_list_help(Node * head,int size, int n,double * swaps){
	if(n >= size){
		return head;
	}else{
		head = Shell_list_help(head,size,(3*n)+1,swaps);
	}
	List* l = Create_lists(head,n);
	list *sec = l;
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
		while(curS != NULL && unsortedT->value > sortedT->value){
			*swaps++;
			prevS = curS;
			curS = curS->next;
		}
		*swaps++;
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
	while(i<n){
		List * cur = malloc(sizeof(List));
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
	curN = head
	while(curL->node != NULL){
		curN->next = curL->node;
		curL = curL->next;
		curN = curN->next;
	}
	curN->node = NULL;
	while(l != NULL){
		temp = l->next;
		free(l);
		l = temp;
	}
	return head;
}

long * Load_Into_Array(char * filename,int * size){
	int i; //Checks to see if we've reached the end of the file.
	int size = 0; 
	int n = 101; //Array size;
	long * array = malloc(sizeof(long)*n);
	FILE * input = open(filename,"r");
	do{
		i = fscanf(input,"%ld",a);
		array[size] = a;
		size++;
		if(size==n){
			array = realloc(array,sizeof(long)*(2*n));
			n = 2*n;	
		}
	}while(i != 0);
	return array;
}

Node * Load_Into_List(char * filename){
	int i;//EOF check
	long a;
	FILE* input = fopen(filename,"r");
	i = fread(&a,1,sizeof(long),a);
	//NEED CORNER CASE
	Node * head = malloc(sizeof(Node));
	head->value = a;
	Node * cur = head;
	i = fread(&a,1,sizeof(long),input);
	while(i!=1){
		cur->next = malloc(sizeof(Node));
		cur->value = a;
		cur = cur->next;
		i = fread(&a,1,sizeof(long),input);
	}
	fclose(input);
	return head;
}

int Save_From_List(char * filename,Node * head){
	FILE * output = open(filename,"w");
	//long L;
	Node * temp;
	while(head != NULL){
		fwrite(head->value,1,sizeof(long),output);
		temp = head->next;
		free(head);
		head = temp;
	}
	fclose(output);
	return EXIT_SUCCESS;
}

int Save_From_Array(char * filename,long * array, int size){
	FILE * output = open(filename,"w");
	int i = 0; //iterator

	//Might want to go with for loop instead.
	while(i < size){
		fprintf(output,"%ld",array[i]);
	}

	free(array);
	
}