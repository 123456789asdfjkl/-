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
void SelectSort(SqList &L)
{
	int i,j;
	int k;
	int a;
	for(i=1;i<=L.length;i++)
	{
		k=i;
		for(j=i;j<=L.length;j++)
		{
			if(L.r[k].key>L.r[j].key)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			a=L.r[k].key;
			L.r[k].key=L.r[i].key;
			L.r[i].key=a;
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
	SelectSort(L);
	Print(L);
	return 0;
 } 
