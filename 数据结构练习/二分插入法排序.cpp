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
void BinaryInsertSort(SqList &L)//���ֲ��ҷ��������� 
{
	int i;
	int low;
	int high;
	int m;
	int j;
	for(i=2;i<=L.length;i++)
	{
		L.r[0].key=L.r[i].key;
		low=1;
		high=i-1;
		while(low<=high){
			m=(high+low)/2;
			if(L.r[0].key<L.r[m].key)
			{
				high=m-1;
			}
			else
			{
				low=m+1;
			}
		}
		for(j=i-1;j>=high+1;j--)
		{
			L.r[j+1].key=L.r[j].key;
		}
		L.r[high+1].key=L.r[0].key;
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
	BinaryInsertSort(L);
	printf("�����Ľ��Ϊ:\n");
	Print(L);
	return 0;	
} 
