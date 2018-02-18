/*
 * huff.h
 *
 *  Created on: Feb 5, 2018
 *      Author: glenn
 */

#ifndef HUFF_H_
#define HUFF_H_

typedef struct Huffman{
	int ch;
	struct Huffman * left;
	struct Huffman * right;
} Huffman;

typedef struct stack {
	Huffman * h;
	struct stack * next;
} stack;

typedef struct CodeStack {
	int Stack[100];
	int top;
	int maxItems;
} CodeStack;

Huffman * Char_Tree_from_Header(FILE * input,long NumChar[3]);
Huffman * Bit_Tree_from_Header(FILE * input,long NumChar[3]);
stack * createBranchNode(stack * s);
Huffman * createLeafNode(int a);
void deallocateQueue(stack * s);
int DecompHelp(Huffman * h,FILE* input,int * a, int * b);
void * Decompress(FILE * input,FILE * output,Huffman * h,long a[3]);
int HCHelp(Huffman * h,CodeStack* CS,FILE*output);
void * Huffman_codes(FILE * output,Huffman * h);
void Pop(CodeStack * CS);
void Push(int a, CodeStack * CS);
stack * StackAdd(Huffman * h,stack * s);
void * printCharLine(Huffman* h,CodeStack * CS,FILE * output);
void resetByte(int*a,FILE*input,unsigned int*b);
void deallocateHuff(Huffman * h);

#endif /* HUFF_H_ */
