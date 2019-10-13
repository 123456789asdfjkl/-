#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct CSNode{
	char data;
	struct CSNode *fc,*nb;
}CSNode,*CSTree;
typedef struct{
	CSTree a[MAXSIZE];
	int top;
}SeqStack;
typedef struct{
	CSTree c[MAXSIZE];
	int f,r;
}SeqQueue;
void CreateCSTree(CSTree &T)//������������ʾ��������ɭ�� ��������������� 
{
	char a;
	scanf("%c",&a);
	if(a=='#')
	{
		T=NULL;
	}
	else
	{
		if(!(T=(CSTree)malloc(sizeof(CSNode))))
		{
			exit(-2);
		}
		T->data=a;
		CreateCSTree(T->fc);
		CreateCSTree(T->nb);		
	}	 
}
void xgbl(CSTree T)//�ȸ���������ɭ�� 
{
	CSTree p;
	SeqStack s;
	s.top=-1;
	p=T;
	while(p)
	{
		while(p)
		{
			printf("%c ",p->data);
			if(p->nb)
			{
				if(s.top==MAXSIZE-1)
				{
					exit(-2);
				}
				s.a[++s.top]=p->nb;
			}
			p=p->fc;
		}
		if(s.top!=-1)
		{
			p=s.a[s.top--];
		}
	}
	printf("\n");
}
void hgbl(CSTree T)//�����������ɭ�� 
{
	CSTree p;
	p=T;
	SeqStack s;
	s.top=-1;
	while(p||s.top!=-1)
	{
		while(p)
		{
			if(s.top==MAXSIZE-1)
			{
				exit(-2);
			}
			else
			{
				s.a[++s.top]=p;
				p=p->fc;
			}
		}
		if(s.top!=-1)
		{
			p=s.a[s.top--];
			printf("%c ",p->data);
			p=p->nb;
		}
	}
	printf("\n");
}
void ccbl(CSTree T)//��α�������ɭ�� 
{
	CSTree p;
	p=T;
	SeqQueue q;
	q.r=q.f=0;
	while(p)
	{
		while(p)
		{
			printf("%c ",p->data);
			if(p->fc)
			{
				if((q.r+1)%MAXSIZE!=q.f)
				{
					q.c[q.r]=p->fc;
					q.r=(q.r+1)%MAXSIZE;
				}
				else
				{
					exit(-2);
				}
			}
			p=p->nb;
		}
		if(q.f!=q.r)
		{
			p=q.c[q.f];
			q.f=(q.f+1)%MAXSIZE;
		}
	}
	printf("\n");
}
int main()
{
	CSTree T;
	printf("�밴�ȸ���������һ��������ʾ�����ɵ�ɭ�֣�\n"); 
	CreateCSTree(T);
	printf("��ɭ�ֵ��ȸ��������Ϊ��\n");
	xgbl(T);
	printf("��ɭ�ֵĺ���������Ϊ��\n");
	hgbl(T);
	printf("��ɭ�ֵĲ�α������Ϊ��\n");
	ccbl(T);
}
