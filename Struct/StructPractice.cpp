#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100 //�迭�� ũ�� 
typedef struct {
	int row; //�� �� 
	int col; //�� �� 
	int value; //������ �� 
} element; //�� ����ü�� Ÿ���̸� 

typedef struct SparseMatrix {
	element data[MAX_TERMS]; //element ����ü Ÿ���� �迭 data[ũ��� 100] 
	int rows;	// ���� ����
	int cols;	// ���� ����
	int terms; 	// ���� ����
} SparseMatrix; //�� ����ü�� Ÿ�� �̸� 

SparseMatrix matrix_transpose2(SparseMatrix a) //main�Լ����� �迭����� �ٸ� �����鰪�鵵 a�� �����´� 
{
	SparseMatrix b;//SparseMatrix Ÿ���� ���� b 

	int bindex;		// ��� b���� ���� ���� ��ġ
	b.rows = a.rows; //main���� �����ִ� 6 
	b.cols = a.cols; //main���� �����ִ� 6
	b.terms = a.terms; //main���� �����ִ� 7

	if (a.terms > 0) { //����ü a�� terms �� ���� ���� 7�� 0���� ū��? yes 
		bindex = 0; //�ʱ�ȭ 
		for (int c = 0; c < a.cols; c++) { //c�� cols �� ���� ����(6)���� �ϳ� ���������� 
										  //�ε����� ����ִ� ���� �� �� �ּҰ� 0 �ִ밡 5�� 
			for (int i = 0; i < a.terms; i++) { // i�� terms(7)���� �ϳ� ���������� //�ε����� 7������ 0���� �����ϴϱ� 
												//�� c�� i �ݺ����� ���ؼ� ��� 30�� �ݺ��Ѵ�
			 
				if (a.data[i].col == c) { /*���� a�� �迭�� 0���ε��� ������ ���� c(0)�� ������? �ƴϿ��i�� ���� 
				��׷� a�� �迭�� 1�� �ε��� ������ ���� c(0)�� ������? �� ---- �Ʒ� �ڵ� ����*/
				 //����� c�� i�� Ž���� �� ������ c++�Ѵ� �� i�� 7���̳� �ε����� ���ƾ� c++�� �Ѵ� 
				
					b.data[bindex].row = a.data[i].col; /* b����ü�� data�迭��  0�� �ε��������� row�κ�(��)��
					 a����ü�� data�迭���� i��° �ε����� col(��)�� ����*/
					 
					b.data[bindex].col = a.data[i].row; /*b����ü�� data�迭���� 0�� �ε����� col(��)�κ���
					a����ü�� data�迭���� i��° �ε����� row(��)�� ����*/
					
					b.data[bindex].value = a.data[i].value; /*b����ü�� data�迭���� 0�� �ε����� �� �κ���
					a����ü�� data �迭���� i�� �ε����� ���� ����*/
					
					bindex++; //�ε����� ���� �ø��� i�� ���� �ø��� 6�� �ݺ��ϰ� bindex�� i�� 7���������� �ȴ�  
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a) // main������ result ����ü�� �����´� 
{
	printf("====================\n");
	for (int i = 0; i<a.terms; i++) {
		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("====================\n");
}

int main(void)
{   /************m�̶�� ����ü ����****************/
	SparseMatrix m = {
		{ { 0, 3, 7 },{ 1, 0, 9 },{ 1, 5, 8 },{ 3, 0, 6 },{ 3, 1, 5 },{ 4, 5, 1 },{ 5, 2, 2 } },
		6,
		6,
		7
	};
	/*********result ��� ����ü ����****************/
	SparseMatrix result;
    /*********result�� ����ü m �� ���� ä���� matrix_transpose2�� ����*******************/
	result = matrix_transpose2(m);
	matrix_print(result); //matrix_transpose2���� ���� ������ result�� �־����� ����  ����Ʈ �Լ��� ���� 
	return 0;
}
