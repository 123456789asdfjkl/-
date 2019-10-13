#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkedList;
void CreateList(LinkedList &L,int n)//���������� 
{
	int i;
	LinkedList p;
	L=(LinkedList)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=0;i<n;i++)
	{
		printf("��%d��Ԫ��Ϊ:",i+1);
		p=(LinkedList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;	
	}	
}
void SortList(LinkedList &L)//�������ѡ������ 
{
	LinkedList p,q,t;
	int a;
	for(p=L->next;p;p=p->next)
	{
		t=p;
		for(q=p->next;q;q=q->next)
		{	
			if(t->data>q->data)
			{
				t=q;	
			}	
		}
		if(p->data!=t->data)
		{
			a=t->data;
			t->data=p->data;
			p->data=a;	
		}	
	} 
}
void PrintList(LinkedList &L)//��ӡ��� 
{
	LinkedList p;
	p=L->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;	
	} 
	printf("\n");
}
int main()
{
	int n;
	LinkedList L;
	printf("�����뵥����ĳ��ȣ�");
	scanf("%d",&n);
	CreateList(L,n);
	PrintList(L);
	SortList(L);
	printf("����Ľ��Ϊ\n"); 
	PrintList(L);	
} 
