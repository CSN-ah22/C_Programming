//�Է��� ���ڿ��� �������� ����ϴ� �� �� 
#include <stdio.h>
#include <stdlib.h> 
#define SIZE 100 //SIZE���� ���� ���ֱ� 
char arr[SIZE];
typedef struct {
	char arr[SIZE];
	struct node *next;
	int top = -1;//top ����� ���ÿ� �ʱ�ȭ �� �����Ͱ� �ƴ϶� int���̿��߸� �� if������ �����ʹ� �񱳰� �ȵ� ����ó���� ���ؼ� �񱳸� �ؾ���  
}stack;

void stack_init(stack *pstack) {
	
    pstack -> top;
}

int push(char data ,int top,stack *pstack){
	if(top>=(SIZE-1)){
		return data;
	}else{
		pstack->arr[pstack->top] =data; /*pstack �� arr�� ����Ų�� arr�� �ε����� pstack�� ����Ű��
		top�� ��°�� ���� �� ������ ��忡 data�� ���� �ִ´� �̰� pstack�� ����Ų�ٴ°� */
	}
	
}
int main() {
    stack stack;
    stack_init(&stack);
   stack input[5]={0};
 
 	
 	
 	for(int i=0; i<5; i++){
 		scanf("%s",input[i].arr);
 		push(input[i].arr); //����--arr�� �Լ�ó�� ��� �� �� ���ٴµ� �𸣰���.. 
	 }
	 return 0;
    
}
