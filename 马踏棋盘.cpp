#include<stdio.h>  
#include <stdlib.h>  
#include<conio.h>  

#define N 8  
int cnt = 1;     // 记录马的位置  
int n = 1;
int chess[8][8] = { 0 };  //棋盘  

int move[8][2] = {
	{ 1,-2 },{ 2,-1 },
{ 2,1 },{ 1,2 },
{ -1,2 },{ -2,1 },
{ -2,-1 },{ -1,-2 }
};

void horse(int, int);
void printhorse();

int main()           //主函数  
{
	chess[0][0] = 1;
	horse(0, 0);
	return 0;
}
void horse(int x, int y)   //执行过程  
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

			}                     // 递归  
			else {
				printhorse();
				//  exit(0);  


			}
			chess[a][b] = 0;//修改ab的值归为0  
			cnt--;
		}
	}
}
void printhorse()          //输出马踏棋盘  
{
	int i, j;
	printf("输出第%d组解：\n", n++);
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
			printf("%3d ", chess[i][j]);
		printf("\n");
	}
}