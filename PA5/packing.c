#include <stdio.h>
#include <stdlib.h>
#include 'packing.h'
void location_get(Node ** Node_set,int size);
void create_edges(Node ** Node_set,int size);
void addRight(Node * F,Node * S);
void addBelow(Node * F,Node * S);
void traverse(Node ** Node_set);
void Bot_trav(Node ** Node_set);
void Right_trav(Node ** Node_set);
void bot_trav_rec(Node ** N, int num,int coor);
void Right_trav_rec(Node ** N, int num,int coor);


void location_get(Node ** Node_set,int size){
	create_edges(Node_set,size);
	traverse(Node_set);
	return;
}

void create_edges(Node ** Node_set,int size){
	List * List1 = Node_set[0]->Bot;
	while(List1 != NULL){
		boxNum = List1->num;
		List * cur = Node_set[0]->Right;
		a = 0 //Indicates which lists the edge needs to be added to.
		Node = Node_set[boxNum];
		prev = NULL;
		while(cur != NULL){
			if(cur->num == boxNum){
				a=1;
				if(prev == NULL){
					Node_set[0]->Right = cur->Next;
					free(cur);
					cur = Node_set[0]->Right;
				}else{
					prev->Next = cur->Next;
					free(cur);
					cur = prev->Next;
				}
			}else if(a=0){
				addRight(Node,Node_set[(cur->num)]);
				prev = cur;
				cur = cur->next;

			}else{
				addBelow(Node,Node_set[(cur->num)]);
				prev = cur;
				cur = cur->Next;
			}
		}
		List1 = List1->Next;
	}
	return;
}

void addRight(Node * F,Node * S){
	List * NewL = malloc(sizeof(List));
	NewL->num = S->Num;
	NewL->next = F->Right;
	F->Right = NewL;
	return;
}

void addBelow(Node * F,Node * S){
	List * NewL = malloc(sizeof(List));
	NewL->num = S->Num;
	NewL->next = F->Bot;
	F->Bot = NewL;
	return;
}

void traverse(Node ** Node_set){
	Bot_trav(Node_set);
	Right_trav(Node_set);
	return;
}

void Bot_trav(Node ** Node_set){
	List * L = Node_set[0]->Bot;
	while(L != NULL){
		bot_trav_rec(Node_set,L->num,0);
		L = L->Next;
	}
	return;
}

void bot_trav_rec(Node ** N, int num,int coor){
	if(coor <= N[num]->xloc){
		return;
	}
	N[num]->xloc = coor;
	coor = coor + N[num]->H;
	List * L = N[num]->Bot;
	while(L != NULL){
		bot_trav_rec(N,L->num,coor);
		L = L->Next;
	}
	return;
}

void Right_trav(Node ** Node_set){
	List * L = Node_set[0]->Bot;
	while(L != NULL){
		Right_trav_rec(Node_set,L->num,0);
		L = L->Next;
	}
	return;
}

void Right_trav_rec(Node ** N, int num, int coor){
	if(coor <= N[num]->yloc){
		return;
	}
	N[num]->yloc = coor;
	coor = coor + N[num]->W;
	List * L = N[num]->Right;
	while(L != NULL){
		Right_trav_rec(N,L->num,coor);
		L = L->Next;
	}
	return;

}