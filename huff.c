/*
 * huff.c
 *
 *  Created on: Feb 5, 2018
 *      Author: glenn
 */
#include <stdio.h>
#include "huff.h"
#include <stdlib.h>

Huffman * Char_Tree_from_Header(FILE * input,long start[3]){
	//Creates Huffman Tree from the input.
	//Don't forget about the aditional zero at the end of thej header.
	int b = 0;//Number of branch nodes
	int l = 1;//Number of leaf nodes
	int ch;
	Huffman * h;
	fseek(input,0,SEEK_SET);
	fread(start,sizeof(long),3,input);
	
	
	fseek(input,24,SEEK_SET);
	ch = fgetc(input);
	if(ch != '1'){
		printf("Header didn't start with a 1.");
		return NULL;
	}
	ch = fgetc(input);
	h = createLeafNode(ch);
	ch = fgetc(input);
	if(ch == 0){
		return h;
	}
	stack * s = StackAdd(h, NULL);
	fseek(input,-1,SEEK_CUR);
	do{
		ch = fgetc(input);
		if(ch=='1'){
			h = createLeafNode(fgetc(input));
			s = StackAdd(h,s);
			l++;
		}else if(ch=='0'){
			if(b<(l-1)){
				s = createBranchNode(s);
			}
			b++;
		}else{
			printf("Corrupted AF.");
			return NULL;
		}
	}while(b<l);
	h = s->h;
	deallocateQueue(s);
	return h;
}


void deallocateQueue(stack * s){
	if(s->next!=NULL){
		deallocateQueue(s->next);
	}
	free(s);
	return;
}

Huffman * createLeafNode(int input){
	Huffman * a = malloc(sizeof(Huffman));
	a->ch = input;
	a->left = NULL;
	a->right = NULL;
	return a;
}

stack * createBranchNode(stack * s){
	Huffman * b = malloc(sizeof(Huffman));
	b->right = s->h;
	b->left = s->next->h;
	s->next->h = b;
	stack * r = s->next;
	free(s);
	return r;
}

stack * StackAdd(Huffman * h, stack * top){
	stack * s = malloc(sizeof(stack));
	s->h = h;
	s->next = top;
	return s;
}

Huffman * Bit_Tree_from_Header(FILE * input,long NumChar[3]){
	//Same as above, just more squigly. Consider anti-corruption.
	fread(NumChar,sizeof(long),3,input);
	//Find 3 long int's at the beginning before this point. One of them is HuffChar.
	stack * s = NULL;
	fseek(input,24,SEEK_SET);
	unsigned int ch;
	unsigned int sch;
	unsigned int b = 0;
	int mask= 0x01;
	int pos = 7;
	int i = 0;
	int l = 0;
	int bytes = 1;
	Huffman * h;

	ch = fgetc(input);
	
	do{
		 b = ch >> pos;
		 b = b & mask;
		 pos--;
		 if(pos<0){
		 	resetByte(&pos,input,&ch);
			bytes++;
		 }
		 if(b == 1){
		 	sch = ch << (7-pos);//SOLVE ON PAPER PLS.
		 	ch = fgetc(input);
		 	b = ch >> (pos+1);
		 	b = b | sch;
		 	h = createLeafNode(b);
			if(l==0){
				s = StackAdd(h,NULL);
			}else{
		 	s = StackAdd(h,s);
			}
			l++;
		 }else if(b == 0){
			
			if(i<(l-1)){
				s = createBranchNode(s);
			}
		 	i++;
		}else{
			printf("big issue.\n\n");
			return NULL;
		}


	}while(i<l);
	h = s->h;
	deallocateQueue(s);
	//fseek(input,NumChar[2],SEEK_SET);
	return h;
}

void * Decompress(FILE* input, FILE* output, Huffman* head,long numChar[3]){
	//Uses tree to decompress the file. Stops at EOF character.
	fseek(input,(numChar[1]+24),SEEK_SET);
	int pos = 7;
	int a = fgetc(input); // Input character in use
	int i = 0;
	int ch;
	
	while(i < numChar[2]){
		ch = DecompHelp(head,input,&a,&pos);
		fprintf(output,"%c",ch);
		i++;
	}
	return NULL;
}

void * Huffman_codes(FILE * output2, Huffman * head){
	//Write a file that contains all the huffman codes on the tree.
	int a;
	CodeStack * CS = malloc(sizeof(CodeStack));
	CS->top = 0;
	CS->maxItems = 100;
	a = HCHelp(head,CS,output2);
	if(a != 1){
		printf("Help");
	}
	free(CS);
	return NULL;
}

int HCHelp(Huffman * head,CodeStack * CS,FILE * output2){
	if(head->left == NULL && head->right== NULL){\
		printCharLine(head,CS,output2);
		Pop(CS);
		return 1;
	}else{
		Push(0,CS);
		HCHelp(head->left,CS,output2);
		Push(1,CS);
		HCHelp(head->right,CS,output2);
		Pop(CS);
		return 1;
	}
}

void * printCharLine(Huffman * head, CodeStack * CS, FILE * output2){
	int i=0;
	fprintf(output2,"%c : ",head->ch);
	while(i<(CS->top)){
		fputc(CS->Stack[i]+48,output2);
		i++;
	}
	fputc('\n',output2);
	return NULL;
}

void Push(int a,CodeStack * CS){
	CS->Stack[(CS->top)] = a;
	CS->top = (CS->top) + 1;
	return;
}

void Pop(CodeStack * CS){
	CS->top = (CS->top) - 1;
	return;
}

int DecompHelp(Huffman * head,FILE * input, int * a, int * pos){
	int c;
	if(head->left == NULL && head->right == NULL){
		return head->ch;
	}else if(head->left == NULL || head->right == NULL){
		printf("ERROR IN DECOMPRESSION. IMPROPER HUFF.");
		return -1;
	}else{
		int mask = 0x01;
		int b = 0;
		if(*pos == 0){
			b  = mask & *a;
			if(b == 1){
			
				head = head->right;
			}else if(b== 0){
				
				head = head->left;
			}else{
				printf("ERROR IN DECOMP HELP. MASKING AND POS WRONG.");
				return -1;
			}
			*a = fgetc(input);
			*pos = 7;
			c = DecompHelp(head,input,a,pos);
		}else{
			b = *a >> *pos;
			b = mask & b;
			*pos = *pos - 1;
			if(b == 0){
				
				c = DecompHelp(head->left,input,a,pos);
			}
			if(b == 1){
				
				c = DecompHelp(head->right,input,a,pos);
			}
		}

	}
	return c;
}

void resetByte(int * pos,FILE * input,unsigned int * ch){
	*pos = 7;
	*ch = fgetc(input);
}

void deallocateHuff(Huffman * h){
	if(h->left==NULL && h->right==NULL){
		free(h);
		return;
	}else{
		deallocateHuff(h->left);
		deallocateHuff(h->right);
		free(h);
		return;
	}
}
