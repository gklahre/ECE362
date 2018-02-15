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
	int size;
	while(current->next != NULL){
		size++;
		current = current->next;
	}
	Shell_list_help(head,size,1,swaps);
	return head;	
}

static Node * Shell_list_help(Node * head,int size, int n,double * swaps){
	if(n > size){
		return;
	}else{
		Shell_list_help(head,size,(3*n)+1,swaps);
	}
	List* l = Create_lists(head,n);
	list *sec = l;
	while(sec!=NULL){
		sec->node = insertion_sort_list(sec->node);
	}
	head = disolveLists(l);
	return head;
}


//Badly needs revision
static Node * insertion_sort_list(Node * head){
	Node * SortedT = head;
	head = head->next;
	Node * current = SortedT;
	while(head!=NULL){
		while(head->value < current->value){

		}
	}	
}

static List * Create_lists(Node * head,int n){
	int i = 1;
	List * l = malloc(sizeof(List));
	l->next = NULL;
	l->node = head;
	head = head->next;
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
	while(head != NULL){
		if(cur == NULL){
			cur = l;
		}
		temp = cur->node;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = head;
		head = head->next;
		temp->next->next = NULL;
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
	i = fscanf(input,"%ld",a);
	Node * head = malloc(sizeof(Node));
	head->value = a;
	Node * cur = head;
	FILE * input = open(filename,"r");
	i = fscanf(input,"%ld",a);
	while(i!=0){
		cur->next = malloc(sizeof(Node));
		cur->value = a;
		cur = cur->next;
		i = fscanf(input,"%ld",a);
	}
	return head;
}

int Save_From_List(char * filename,Node * head){
	FILE * output = open(filename,"w");
	long L;
	Node * temp;
	while(head != NULL){
		fprintf(output,"%ld",l);
		temp = head->next;
		free(head);
		head = temp;
	}
	return EXIT_SUCCESS;
}