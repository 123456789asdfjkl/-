#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct{
	int i;//����Ԫ�����±� 
	int j;//����Ԫ�����±� 
	int e;//����Ԫ��ֵ 
}Triple;
typedef struct{
	Triple data[MAXSIZE];
	int mu;//��������� 
	int nu;//��������� 
	int tu;//�������Ԫ�ĸ��� 
}TSMatrix;
int main()
{
	TSMatrix a;
	a.mu=3;
	a.nu=5;
	a.tu=5;
	a.data[1].i=1;
	a.data[1].j=2;
	a.data[1].e=14;
	a.data[2].i=1;
	a.data[2].j=5;
	a.data[2].e=-5;
	a.data[3].i=2;
	a.data[3].j=2;
	a.data[3].e=-7;
	a.data[4].i=3;
	a.data[4].j=1;
	a.data[4].e=36;
	a.data[5].i=3;
	a.data[5].j=4;
	a.data[6].e=28;
	
}
