#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100 //배열의 크기 
typedef struct {
	int row; //행 값 
	int col; //열 값 
	int value; //데이터 값 
} element; //이 구조체의 타입이름 

typedef struct SparseMatrix {
	element data[MAX_TERMS]; //element 구조체 타입의 배열 data[크기는 100] 
	int rows;	// 행의 개수
	int cols;	// 열의 개수
	int terms; 	// 항의 개수
} SparseMatrix; //이 구조체의 타입 이름 

SparseMatrix matrix_transpose2(SparseMatrix a) //main함수에서 배열값들과 다른 변수들값들도 a로 가져온다 
{
	SparseMatrix b;//SparseMatrix 타입의 변수 b 

	int bindex;		// 행렬 b에서 현재 저장 위치
	b.rows = a.rows; //main에서 써져있던 6 
	b.cols = a.cols; //main에서 써져있던 6
	b.terms = a.terms; //main에서 써져있던 7

	if (a.terms > 0) { //구조체 a의 terms 즉 셀의 개수 7이 0보다 큰가? yes 
		bindex = 0; //초기화 
		for (int c = 0; c < a.cols; c++) { //c가 cols 즉 열의 개수(6)보다 하나 작을때까지 
										  //인덱스에 들어있는 열의 값 중 최소가 0 최대가 5임 
			for (int i = 0; i < a.terms; i++) { // i가 terms(7)보다 하나 작을때까지 //인덱스가 7개지만 0부터 시작하니까 
												//즉 c와 i 반복문을 곱해서 모두 30번 반복한다
			 
				if (a.data[i].col == c) { /*만약 a의 배열중 0번인덱스 에서의 열이 c(0)와 같나요? 아니요→i값 증가 
				→그럼 a의 배열중 1번 인덱스 에서의 열이 c(0)와 같나요? 네 ---- 아래 코드 실행*/
				 //참고로 c는 i의 탐색이 다 끝나야 c++한다 즉 i가 7번이나 인덱스를 돌아야 c++를 한다 
				
					b.data[bindex].row = a.data[i].col; /* b구조체의 data배열중  0번 인덱스에서의 row부분(행)은
					 a구조체의 data배열에서 i번째 인덱스의 col(열)과 같다*/
					 
					b.data[bindex].col = a.data[i].row; /*b구조체의 data배열에서 0번 인덱스의 col(열)부분은
					a구조체의 data배열에서 i번째 인덱스의 row(행)과 같다*/
					
					b.data[bindex].value = a.data[i].value; /*b구조체의 data배열에서 0번 인덱스의 값 부분은
					a구조체의 data 배열에서 i번 인덱스의 값과 같다*/
					
					bindex++; //인덱스의 값을 올린다 i의 값도 올린다 6번 반복하고 bindex와 i는 7값을가지게 된다  
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a) // main에서의 result 구조체를 가져온다 
{
	printf("====================\n");
	for (int i = 0; i<a.terms; i++) {
		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("====================\n");
}

int main(void)
{   /************m이라는 구조체 생성****************/
	SparseMatrix m = {
		{ { 0, 3, 7 },{ 1, 0, 9 },{ 1, 5, 8 },{ 3, 0, 6 },{ 3, 1, 5 },{ 4, 5, 1 },{ 5, 2, 2 } },
		6,
		6,
		7
	};
	/*********result 라는 구조체 생성****************/
	SparseMatrix result;
    /*********result에 구조체 m 값 으로 채워진 matrix_transpose2를 넣음*******************/
	result = matrix_transpose2(m);
	matrix_print(result); //matrix_transpose2에서 계산된 값들을 result에 넣었으니 이제  프린트 함수에 넣음 
	return 0;
}
