//입력한 문자열을 역순으로 출력하는 구 현 
#include <stdio.h>
#include <stdlib.h> 
#define SIZE 100 //SIZE잊지 말고 써주기 
char arr[SIZE];
typedef struct {
	char arr[SIZE];
	struct node *next;
	int top = -1;//top 선언과 동시에 초기화 꼭 포인터가 아니라 int형이여야만 함 if문에서 포인터는 비교가 안됨 예외처리를 위해서 비교를 해야함  
}stack;

void stack_init(stack *pstack) {
	
    pstack -> top;
}

int push(char data ,int top,stack *pstack){
	if(top>=(SIZE-1)){
		return data;
	}else{
		pstack->arr[pstack->top] =data; /*pstack 은 arr을 가리킨다 arr의 인덱스는 pstack이 가리키는
		top의 번째와 같다 즉 상위의 노드에 data의 값을 넣는다 이걸 pstack이 가리킨다는것 */
	}
	
}
int main() {
    stack stack;
    stack_init(&stack);
   stack input[5]={0};
 
 	
 	
 	for(int i=0; i<5; i++){
 		scanf("%s",input[i].arr);
 		push(input[i].arr); //오류--arr를 함수처럼 사용 할 수 없다는데 모르겠음.. 
	 }
	 return 0;
    
}
