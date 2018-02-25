#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Print_Postorder(Tree * t,char * filename);
Tree * Load_binary_tree(char * filename);

void Print_Postorder(Tree * t){
	if(t->left == NULL || t->right == NULL){
		printf("%d",t->value);
		return;
	}
	Print_Postorder(t->left);
	Print_Postorder(t->right);
	printf("%c",t->char);
	return;
}

Tree * Load_binary_tree(char * filename){
	int c;
	FILE * input = fopen(filename,"r");

	Tree * head;
	head = create_tree(input);
	c = fgetc(input);
	if(c != EOF){
		printf("\nNot at EOF.\n");
		deallocateTree(head);
		return NULL;
	}
	return head;
}


Tree * create_tree(FILE * input){
	int ch;
	ch = fgetc(input);
	if(ch == 'H' || ch == 'V'){
		Tree * head = allocateBranch(&ch);
		if(head == NULL){
			return NULL;
		}

		fseek(input,1,SEEK_CUR); //Push input past \n. Might cause issues with EOF. Checks might be needed.
		head->left = create_tree(input);
		if(head->left == NULL){
			deallocateNode(head);
			return NULL;
		}
		head->right = create_tree(input)
		if(head->right == NULL){
			deallocateTree(head->left);
			deallocateNode(head);
			return NULL;
		}
		return head;

	}else{
		fseek(input,-1,SEEK_CUR);
		int LeNum;
		double LeH, LeW;

		fscanf(input,"%d(%le,%le)\n",&LeNum,&LeW,&LeH);
		//Read entire line and place input
		Tree * leaf = allocateLeaf(LeNum,LeH,LeW);
		if(leaf == NULL){
			return NULL;
		}
		return leaf;

	}
}

Tree * allocateBranch(char ch){
	Tree * branch = malloc(sizeof(Tree));
	if(branch == NULL){
		return NULL;
	}
	branch->height = 0;
	branch->width = 0;
	branch->chInt = ch;
	return branch;
}

Tree * allocateLeaf(int n,double h, double w){
	Tree * leaf = malloc(sizeof(Tree));
	if(leaf == NULL){
		return NULL;
	}
	leaf->chInt = n;
	leaf->height = h;
	leaf->width = w;
	leaf->left = NULL;
	leaf->right = NULL;
	return leaf;
}

void deallocateTree(Tree * h){
	if(Tree->left != NULL){
		deallocateTree(h->left);
	}
	if(Tree->right != NULL){
		deallocateTree(h->right);
	}
	free(h);
	return;
}

void deallocateNode(Tree * b){
	free(b);
	return;
}

void printInorder(Tree * h){
	if(h->left == NULL){
		printf("%d\n",h->chInt);
		return;
	}
	printInorder(h->left);
	printf("%d\n",h->chInt);
	printInorder(h->right);
	return;
}

void Print_Postorder(Tree * h,char * filename){
	FILE * output = fopen(argv[2],"w");
	PP(h,output);
	fclose(output);
	return;
}

void PP(Tree * head,output){
	if(head->left == NULL || head->right == NULL){
		fprintf(output,"%d(%le,%le)\n",head->chInt,head->width,head->height);
	}
	PP(head->left,output);
	PP(head->right,output);
	fprintf(output,"%c\n",head->chInt);
	return;
}

void Packing_it_in(Tree * head){
	if(head->left == NULL || head->right== NULL){
		return;
	}
	Packing_it_in(head->left);
	Packing_it_in(head->right);
	if(head->chInt == 'V'){
		head->height = (head->left->height + head->right->height);
		head->width = fmax(head->left->width,head->right->width);
		return;
	}
	if(head->chInt == 'H'){
		head->width = (head->left->width + head->right->width);
		head->height = fmax(head->left->height,head->right->height);
	}
	return;
}

void printCoor(Tree * t,char * filename){
	FILE * output = fopen(filename,"w");
	coorRec(t,0,0,output);
	fclose(output);
}

void coorRec(Tree * t, double h, double w, FILE * output){
	if(t->left == NULL){
		fprintf(output,"%d(%le,%le)\n",t->chInt,w,h);
		return;
	}
	if(t->chInt == 'H'){
		coorRec(t->left,(h+t->right->height),w,output);
		coorRec(t->right,h,w,output);
		return;
	}
	if(t->chInt == 'V'){
		coorRec(t->left,h,w,output);
		coorRec(t->right,h,(w+t->left->width),output);
		return;
	}
	printf("If you reached here. Bad news.\n");
	return;
}

void printSize(Tree * t, char * filename){
	FILE* output = fopen(filename,"w");
	printSize(t,output);
	fclose(output);
}

void SizeRec(Tree * t,output){
	if(t->left == NULL){
		fprintf(output,"%d(%le,%le)\n",t->chInt,t->width,t->height);
	}
	fprintf(output,"%c(%le,%le)\n",t->chInt,t->width,t->height);
	SizeRec(t->left,output);
	SizeRec(t->right,output);
}