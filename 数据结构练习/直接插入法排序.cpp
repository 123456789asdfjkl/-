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
void InsertSort(SqList &L)//ֱ�Ӳ������� 
{
	int i;
	int j;
	for(i=2;i<=L.length;i++)
	{
		if(L.r[i].key<L.r[i-1].key)
		{
			L.r[0].key=L.r[i].key;
			L.r[i].key=L.r[i-1].key;
			for(j=i-2;L.r[0].key<L.r[j].key;j--)
			{
				L.r[j+1].key=L.r[j].key;
			}
			L.r[j+1].key=L.r[0].key;
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
	printf("----------------------------\n");
	printf("�����Ľ��Ϊ:\n"); 
	InsertSort(L);
	Print(L);
	return 0;	
} 
