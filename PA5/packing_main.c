#include <stdio.h>
#include <stdlib.h>
#include "packing.h"

Node ** get_input(char * filename,int * size);
void print_loc(char * filename,Node ** Node_set,int size);
void disolve(Node ** Node_set,int size);
Node * new_node(int boxNum,long H,long W,int Last);

int main(int argc, char ** argv){
	if(argc != 3){
		return EXIT_FAILURE;
	}
	int size;
	Node_set = get_input(argv[1],&size);
	location_get(Node_set,size);
	print_loc(argv[2],Node_set,size);
	disolve(Node_set,size);
	return EXIT_SUCCESS;
}

Node ** get_input(char * filename,int * size){
	int boxes;
	int check;
	char ch;
	FILE * input = fopen(filename,"r");
	fscanf(input,"%d\n",boxes);
	Node * New = NULL;
	Node * New = malloc(sizeof(void*)*(boxes+2));
	New[0] = new_node(0,0,0,0);
	New[(boxes+1)] = new_node(boxes+1,0,0,0);
	for(i=1,i<=boxes,i++){
		check = fscanf(input,"%d(%le,%le)\n",boxNum,boxH,boxW);
		if(check != 3){
			printf("Read error.");
			disolve(New);
			fclose(input);
			return NULL;
		}
		New[i] = new_node(boxNum,boxH,boxW,(boxes+1));
	}
	New[]
	i = 0;
	List * Prev = NULL;
	do{	
		List * First = malloc(sizeof(List));
		fread(input,sizeof(int),1,First->num);
		First->next = Prev;
		Prev = First;
		fread(input,sizeof(char),1,ch);
		i++;
	}while(ch != '\n');
	i = 0;
	List * List1 = Prev;
	Prev = NULL;
	do{
		List * Second = malloc(sizeof(List));
		fread(input,sizeof(int),1,Second->num);
		Second->next = Prev;
		Prev = Second;
		fread(input,sizeof(char),1,ch);
		i++;
	}while(ch != '\n' && ch != EOF);
	New[0]->Bot = List1
	New[0]->Right = Prev;
	fclose(input);
	*size = boxes;
	return New;

	//Alternative option New[i] = malloc(sizeof(Node)); That would save the trouble of a linked list.
}

void print_loc(char * filename,Node ** Node_set,int size){
	FILE * output = fopen(filename,"w");
	for(i=1;i<=size,i++){
		fprintf(output,"%d(%le,%le)\n",Node_set[i]->Num,Node_set[i]->xloc,Node_set[i]->yloc);
	}
	return;
}
void disolve(Node ** Node_set, int size){
	List * L;
	List * Next;
	for(i=0;i<size+2;i++){
		L = Node_set[i]->Bot;
		while(L != NULL){
			Next = L->Next;
			free(L);
			L = Next;
		}
		L = Node_set[i]->Right;
		while(L != NULL){
			Next = L->Next;
			free(L);
			L = Next;
		}
		free(Node_set[i]);
	}
	free(Node_set);
	return;
}

Node * new_node(int boxNum,long H,long W,int Last){
	Node * New = malloc(sizeof(Node));
	New->Num = boxNum;
	New->H = H;
	New->W = W;
	New->xloc = -1;
	New->yloc = -1;
	if(Last == 0){
		New->Bot = NULL;
		New->Right = NULL;
	}else{
		New->Bot = malloc(sizeof(List));
		New->Right = malloc(sizeof(List));
		New->Bot->num = Last;
		New->Right->num = Last;
		New->Bot->Next = NULL;
		New->Bot->Next = NULL;
	}
	return New;
}