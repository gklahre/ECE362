
#ifndef Sort_H
#define Sort_H

typedef struct _List {
	Node * node;
	struct _List * next;
	//struct _List * last;
} List;

typedef struct _Node{
	long value;
	stuct _Node * next;
} Node;

#endif //Sort_H
