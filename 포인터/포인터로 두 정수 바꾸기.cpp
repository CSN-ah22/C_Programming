#include <stdio.h>
int main(void){
	int i, j;
	i=10;
	int *temp;
	temp=&i;
	j=*temp;
	*temp=20;
	i=*temp;
	printf("%d/%d",i,j);
}
