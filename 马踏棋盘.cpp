#include<stdio.h>  
#include <stdlib.h>  
#include<conio.h>  

#define N 8  
int cnt = 1;     // ��¼���λ��  
int n = 1;
int chess[8][8] = { 0 };  //����  

int move[8][2] = {
	{ 1,-2 },{ 2,-1 },
{ 2,1 },{ 1,2 },
{ -1,2 },{ -2,1 },
{ -2,-1 },{ -1,-2 }
};

void horse(int, int);
void printhorse();

int main()           //������  
{
	chess[0][0] = 1;
	horse(0, 0);
	return 0;
}
void horse(int x, int y)   //ִ�й���  
{
	int i;
	int a, b;
	for (i = 0; i<N; i++)
	{
		a = x + move[i][0];
		b = y + move[i][1];
		if (a >= 0 && a<N&&b >= 0 && b<N && !chess[a][b])
		{
			chess[a][b] = ++cnt;
			if (cnt<64)
			{
				horse(a, b);

			}                     // �ݹ�  
			else {
				printhorse();
				//  exit(0);  


			}
			chess[a][b] = 0;//�޸�ab��ֵ��Ϊ0  
			cnt--;
		}
	}
}
void printhorse()          //�����̤����  
{
	int i, j;
	printf("�����%d��⣺\n", n++);
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
			printf("%3d ", chess[i][j]);
		printf("\n");
	}
}