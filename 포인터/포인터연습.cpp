#include <stdio.h >
void swap1(int i, int j);
//
void swap2(int *i, int *j){
//i�� 100 j�� 200 
int temp=*i; //temp�� i�� �ּҰ��� �ִ´� 
*i=*j; //i�� j�� �ּҰ��� �ִ´� 
*j=temp; //j�� temp�� ���� �ִ´� �� temp�� i�� ���� ������ �־ i�� �ְԵȴ� 
//������ �� �� ������ �� ���̱�
//����Ҷ��� �� �ʿ��ϰ� ������ �ʿ��� 
//ȣ���Ҷ� ���������� �ֱ�!!!!!!! 
printf("%d/%d",*i,*j);
}
int main()
{
int number1 ,number2;
number1=100;
number2=200;
swap2(&number1,&number2);
 

}


