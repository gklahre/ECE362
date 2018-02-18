/*
 * main.c
 *
 *  Created on: Feb 5, 2018
 *      Author: glenn
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huff.h"

int main(int argc, char* argv[]){
	if(argc < 4){
		printf("Not enough arguments.");
		return EXIT_FAILURE;
	}
	if (strlen(argv[1])!=2){
		printf("Improper argument 1.");
		return EXIT_FAILURE;
	}
	if(argv[1][0]!='-'){
		printf("Improper argument 1.");
		return EXIT_FAILURE;
	}
	long FileInfo[3];
	if(argv[1][1]=='b'){
		if(argc!=4){
			printf("Improper number of arguments for bitwise header.");
			return EXIT_FAILURE;
		}
		FILE * input = fopen(argv[2],"r");
		if(input==NULL){
			return EXIT_FAILURE;
		}
		FILE * output = fopen(argv[3],"w");
		if(output==NULL){
			fclose(input);
			return EXIT_FAILURE;
		}
		Huffman * h = Bit_Tree_from_Header(input,FileInfo);
		if(h==NULL){
			fclose(input);
			fclose(output);
			return EXIT_FAILURE;
		}
		//Huffman_codes(output,h);
		Decompress(input,output,h,FileInfo);
		deallocateHuff(h);
		fclose(input);
		fclose(output);
		return EXIT_SUCCESS;

	}
	if(argv[1][1]=='c'){
		if(argc!=5){
			printf("Improper # of args for char header.");
			return EXIT_FAILURE;
		}
		FILE * input = fopen(argv[2],"r");
		if(input==NULL){
			printf("Help.");
			return EXIT_FAILURE;
		}
		FILE * output1 = fopen(argv[3],"w");
		if(output1==NULL){
			fclose(input);
			printf("HELP ME.");
		   
			return EXIT_FAILURE;
		}
		FILE * output2 = fopen(argv[4],"w");
		if(output2 == NULL){
			fclose(input);
			fclose(output1);
			printf("HALP.");
			return EXIT_FAILURE;
		}
		Huffman * h = Char_Tree_from_Header(input,FileInfo);
		if(h==NULL){
			return EXIT_FAILURE;
		}
		Huffman_codes(output1,h);
		
		Decompress(input,output2,h,FileInfo);
		deallocateHuff(h);
		fclose(input);
		fclose(output1);
		fclose(output2);
		return EXIT_SUCCESS;
	}
	printf("Improper argument 1.");
	return EXIT_FAILURE;
}

