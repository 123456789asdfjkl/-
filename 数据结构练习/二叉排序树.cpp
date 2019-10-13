#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct 
{
	BiTree data[MAX];
	int top;
}SeqStack;
void CreatBiTree(BiTree &T)//����������������������� 
{
	int ch;
	scanf("%d",&ch);
	if(ch==0)
	{
		T=NULL;
	}
	else
	{
		if(!(T=(BiTree)malloc(sizeof(BiTree))))
		{
			exit(-2);
		}
		T->data=ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
}
int IsBalance(BiTree &T)//�ж϶������Ƿ�Ϊ���������� 
{	
	SeqStack S;
	BiTree p;
	S.top=-1;
	int k=0;
	int flag=1; 
	p=T;
	while(p||S.top!=-1)
	{
		while(p)
		{
			if(S.top==MAX-1)
			{
				exit(0);
			}
			S.data[++S.top]=p;
			p=p->lchild;
		}
		if(S.top!=-1)
		{
			p=S.data[S.top--];
			if(k<p->data)
			{
				k=p->data;
			}
			else
			{
				printf("���Ƕ���������\n"); 
				flag=0;
				return 0;
			}
			p=p->rchild;
		}
	}
	if(flag)
	{
		printf("�Ƕ���������\n");
		return 1;
	}
}
void isexist(BiTree &T,int k)//�ж��Ƿ����ֵΪk�Ľڵ� 
{
	BiTree p;
	p=T;
	int flag=0;
	while(p)
	{
		if(k==p->data)
		{
			printf("����\n");
			flag=1;
			return;
		}
		if(k>p->data)
		{
			p=p->rchild;
		}
		if(k<p->data)
		{
			p=p->lchild;
		}
	}
	if(!flag)
	{
		printf("������\n");
	}
	
}
int main()
{
	BiTree T;
	int k,l;
	CreatBiTree(T);
	l=IsBalance(T);
	if(l)
	{
	
		scanf("%d",&k);
		isexist(T,k);
	}
	return 0;
} 
