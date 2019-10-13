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
int Partition(SqList &L,int low,int high)//һ�ο��� 
{
	int pivotkey;
	L.r[0]=L.r[low];
	pivotkey=L.r[low].key;
	while(low<high)
	{
		while(low<high&&L.r[high].key>=pivotkey)
		{
			--high;			
		}
		L.r[low]=L.r[high];
		while(low<high&&L.r[low].key<=pivotkey)
		{
			++low;
		} 
		L.r[high]=L.r[low];
	}
	L.r[low]=L.r[0];
	return low;
	
}
void QSort(SqList &L,int low,int high)//�ȽϺ��� 
{
	int pivotloc;
	if(low<high)
	{
		pivotloc=Partition(L,low,high);
		QSort(L,low,pivotloc-1);
		QSort(L,pivotloc+1,high); 
	}
}
void QuickSort(SqList &L)//�������� 
{
	QSort(L,1,L.length);
}
int main()
{
	SqList L;
	Insert(L);
	Print(L);
	QuickSort(L);
	Print(L);
	return 0;	
} 
