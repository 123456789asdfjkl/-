#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
int ListInsert(LinkList &L,int i,int e)//��������ָ��λ�ò���Ԫ�� 
{
	LinkList p,s;
	int j;
	p=L;
	j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
	{
		return -1;
	}
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 0;
}
void CreateList(LinkList &L,int n)//���������� 
{
	int i;
	LinkList p;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=0;i<n;i++)
	{
		printf("��%d��Ԫ��Ϊ:",i+1);
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;	
	}	
}
void ListPrint(LinkList &L)//����������е�Ԫ�� 
{
	LinkList p;
	p=L->next;
	printf("�������е�Ԫ��Ϊ��\n");
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void ListSort(LinkList &L,int n)//�Ӵ�С���� 
{
	LinkList p,q;
	p=L->next;
	q=p->next;
	int j;
	int i;
	for(i=1;i<=n;i++)
	{
		while(q&&p)
		{
			if(q->data>p->data)
			{
				j=q->data;
				q->data=p->data;
				p->data=j;
			}
			q=q->next;
			p=p->next;
		}
		p=L->next;
		q=p->next;
	}
}
void ListSort1(LinkList &L,int n)//��С�������� 
{
	LinkList p,q;
	p=L->next;
	q=p->next;
	int j;
	int i;
	for(i=1;i<=n;i++)
	{
		while(q&&p)
		{
			if(q->data<p->data)
			{
				j=q->data;
				q->data=p->data;
				p->data=j;
			}
			q=q->next;
			p=p->next;
		}
		p=L->next;
		q=p->next;
	}
}
void DelectList(LinkList &L,int n)//ɾ��ָ��λ��Ԫ�ص�ֵ 
{
	LinkList p,q;
	int i;
	p=L->next;
	q=L;
	for(i=0;i<n-1;i++) 
	{
		p=p->next;
		q=q->next;
	}
	q->next=p->next;
	free(p);
}
int DelectList1(LinkList &L,int e)
{
	LinkList p,q;
	p=L->next;
	q=L;
	while(p)
	{
		if(p->data==e)
		{
			q->next=p->next;
			free(p);
			return 1;
		}
		p=p->next;
		q=q->next;				
	}
	printf("�����ڴ�Ԫ�أ�ɾ��ʧ��\n");
	return 0;	
} 
int main()
{
	LinkList L;
	int a;
	int n;
	int i;
	int e;
	int flag;
	while(true)
	{ 
		system("cls");
		printf("--------------------------------------\n");
		printf("0---------------------------------�˳�\n");
		printf("1---------------------------����������\n");
		printf("2-----------------------------����Ԫ��\n");
		printf("3-------------------------�Ӵ�С����\n");
		printf("4-------------------------��С��������\n");
		printf("5-----------ɾ��ָ��λ�õ�Ԫ��(��λ��)\n");
		printf("6-------------------------ɾ��ָ��Ԫ��\n");
		printf("7---------------------��ʾ�������Ԫ��\n");
		printf("��ѡ�����\n"); 
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("�����뵥����ĳ��ȣ�\n");
				scanf("%d",&n); 
				CreateList(L,n);
				ListPrint(L);
				break;
			case 2:
				printf("������Ҫ����Ԫ��λ��:\n");
				scanf("%d",&i);
				printf("������Ҫ����Ԫ��ֵ��\n");
				scanf("%d",&e);
				ListInsert(L,i,e);
				ListPrint(L);
				break;
			case 3:	
				ListSort(L,n);
				ListPrint(L);
				break;
			case 4:
				ListSort1(L,n);
				ListPrint(L);
				break;
			case 5:
				printf("������Ҫɾ��Ԫ�ص�λ�ã�\n");
				scanf("%d",&i);
				DelectList(L,i);
				ListPrint(L);
				break;
			case 6:
				printf("������Ҫɾ����Ԫ��ֵ��\n");
				scanf("%d",&e);
				flag=DelectList1(L,e);
				if(flag)
				{
					ListPrint(L);
				}
				break;
			case 7:
				ListPrint(L);
				break;
		}
		if(!a)
		{
			break;
		}
		system("pause");
	}
	return 0;	
} 
