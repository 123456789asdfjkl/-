#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct CSNode{
	char data;
	struct CSNode *fc,*nb;
}CSNode,*CSTree;
//ɭ�ֵĺ����ֵܱ�ʾ��

typedef struct
{CSTree data[MAXSIZE];
int top;
}SeqStack;
//ջ

typedef struct
{CSTree data[MAXSIZE];
int f,r;
}SeQueue;
//����

void CreateCSTree(CSTree &T)
{
	char ch;
	scanf("%c",&ch);
    if(ch=='#')
		T=NULL;
	else
	{
		T=(CSNode*)malloc(sizeof(CSNode));
		T->data=ch;
		CreateCSTree(T->fc);
		CreateCSTree(T->nb);
	}
}
//�Զ�������洢�ķ�ʽ����ɭ��

void InorderTraverse(CSTree T)
{
	SeqStack s;
	CSTree p;
	s.top=-1;
	p=T;
	while(p||(s.top!=-1))
	{
		while(p)
		{
		 if(s.top==MAXSIZE-1)
		   exit(0);
		 s.data[++s.top]=p;
		 p=p->fc;
		}
		if(s.top!=-1)
		{
			p=s.data[s.top--];
			printf("%c",p->data);
			p=p->nb;
		}
	}
	printf("\n");
}
//ʵ��ɭ�ֵ��������

void count(CSTree &T)
{
   CSTree p;
   SeQueue q;
   int count=0;
   q.f=0;
   q.r=0;
   if(!T)
     printf("��ɭ��Ϊ�գ�Ҷ�ӽ����Ϊ%d",count);
   q.data[q.r++]=T;
   while(q.f!=q.r)
   {
	   p=q.data[q.f++];
	   if(!p->fc)
	     count++;
	   else
		   q.data[q.r++]=p->fc;
       if(p->nb)
	    q.data[q.r++]=p->nb;
   }
   printf("��ɭ�ֵ�Ҷ�ӽ����Ϊ%2d",count);
   printf("\n");
}
//����ɭ����Ҷ�ӽ��ĸ���

void yOn(CSTree &T)
{
   CSTree p;
   SeQueue q;
   int k=0;
   q.f=0;
   q.r=0;
   if(T==NULL)
   {
	   printf("�˶�����Ϊ��ȫ������\n");
       return;
   }
   q.data[q.r++]=T;
   while(k!=1)
   {
	   p=q.data[q.f++];
	   if(p->fc==NULL)
	   {   if(p->nb!=NULL)
		    printf("�˶�����������ȫ������\n");
	   else
	        k=1;
	   }
	   else
	   {
		   q.data[q.r++]=p->fc;
		   if(p->nb!=NULL)
			   q.data[q.r++]=p->nb;
		   else
		   k=1;
	   }
   }
   while(q.f!=q.r)
   {
	   p=q.data[q.f++];
	   if((p->fc!=NULL)||(p->nb!=NULL))
	   { 
		  printf("�˶�����������ȫ������\n");
	      return;
	   }
   }
    printf("�˶�����Ϊ��ȫ������\n");
}
//�ж�ɭ�ֶ�Ӧ�Ķ������Ƿ�Ϊ��ȫ������

int main()
{
	CSTree T;
	printf("�����Զ�������洢��ɭ��:\n");
    CreateCSTree(T);
	InorderTraverse(T);
	count(T);
    yOn(T);
    return 0;
}
