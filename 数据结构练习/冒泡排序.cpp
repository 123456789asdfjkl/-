#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct {
	int key;//��¼������Ϣ 
}RedType;
typedef struct {
	RedType r[MAXSIZE+1];//��ȡ˳���Ԫ�� 
	int length;//˳���ĳ��� 
}SqList;
void Insert(SqList &L)// ����˳��� 
{
	int i;
	printf("������˳���ĳ��ȣ�");
	scanf("%d",&L.length);
	for(i=1;i<=L.length;i++)
	{
		printf("�������%d��Ԫ��",i);
		scanf("%d",&L.r[i].key);	
	} 
}
void qppx(SqList &L)
{
	int i; 
	int j;
	int t;
	int count=1;
	for(i=1;(i<=L.length)&&(count>0);i++)
	{
		count=0;
		for(j=1;j<=L.length-i;j++)
		{
			if(L.r[j].key>L.r[j+1].key)
			{
				t=L.r[j].key;
				L.r[j].key=L.r[j+1].key;
				L.r[j+1].key=t;
				count++;
			}
		}
	}
}
void Print(SqList &L)//��ӡ˳��� 
{
	int i;
	printf("����Ԫ��Ϊ��") ;
	for(i=1;i<=L.length;i++)
	{
		printf("%d ",L.r[i].key);	
	}
	printf("\n"); 
}
int main()
{
	SqList L;
	Insert(L);
	Print(L);
	qppx(L);
	Print(L);
	return 0;
}
