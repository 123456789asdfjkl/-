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
void HeepAdjust(SqList &L,int s,int m )//������ĵ��� 
{
	int rc;
	int j;
	rc=L.r[s].key;
	for(j=2*s;j<m;j*=2)
	{
		if(j<m&&L.r[j].key<L.r[j+1].key)
		{
			++j;
		}
		if(!(rc<L.r[j].key))
		{
			break;
		}
		L.r[s].key=L.r[j].key;
		s=j;
	}
	L.r[s].key=rc;
 } 
void HeepSort(SqList &L)
{
	int i;
	int k;
	for(i=L.length/2;i>0;--i)
	{
		HeepAdjust(L,i,L.length);	
	}
	for(i=L.length;i>1;--i)
	{
		k=L.r[i].key;
		L.r[i].key=L.r[1].key;
		L.r[1].key=k;
		HeepAdjust(L,1,i-1);	
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
	HeepSort(L);
	Print(L); 
	return 0;
	
}
