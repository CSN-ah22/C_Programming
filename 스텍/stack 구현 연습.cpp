#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int key;
	struct node  *next;
}Node;

Node *top = NULL;

int pop(void){
	Node *temp;
	int ret;
	if(top==NULL){
		return-1;
	}
	else{
		ret = top->key;
		temp = top;
		free(temp);
		top = top -> next;
		return ret;
	}
}
int main(void){
	pop();
}
