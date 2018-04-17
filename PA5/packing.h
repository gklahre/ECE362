#ifndef PACKING_H
#define PACKING_H

static struct Node{
	int Num;
	long W;
	long H;
	long xloc;
	long yloc;
	List * Bot;
	List * Right;	
}Node;

static struct List{
	int num;
	List * Next;
}List;

#endif

