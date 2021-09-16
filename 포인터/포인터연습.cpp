#include <stdio.h >
void swap1(int i, int j);
//
void swap2(int *i, int *j){
//i가 100 j가 200 
int temp=*i; //temp에 i의 주소값을 넣는다 
*i=*j; //i에 j의 주소값을 넣는다 
*j=temp; //j에 temp의 값을 넣는다 즉 temp는 i의 값을 가지고 있어서 i를 넣게된다 
//포인터 쓸 때 무조건 별 붙이기
//출력할때도 별 필요하고 형식자 필요함 
//호출할때 참조연산자 넣기!!!!!!! 
printf("%d/%d",*i,*j);
}
int main()
{
int number1 ,number2;
number1=100;
number2=200;
swap2(&number1,&number2);
 

}


