#ifndef Tree_H
#define Tree_H

typedef struct Tree{
	struct Tree * left;
	struct Tree * right;
	double width, height;
	int chInt;
} Tree;

void Print_Postorder(Tree * t,char * filename);
Tree * Load_binary_tree(char * filename);
void deallocateTree(Tree * t);
void Packing_it_in(Tree * head);
void printSize(Tree * t, char * filename);
void printCoor(Tree * t,char * filename);


#endif 
