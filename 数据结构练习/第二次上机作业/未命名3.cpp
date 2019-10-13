#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct{
 	BiTree d;
	int flag;
}dataelem;

typedef struct 
{
	dataelem data[MAXSIZE];
	int f,r;
}SeQueue;

BiTree CreateBiTree(BiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		T=NULL;
	else
	{
		    T=(BiTNode*)malloc(sizeof(BiTNode));
			if(!T)
				exit(0);
		    T->data=ch;
			CreateBiTree(T->lchild);
			CreateBiTree(T->rchild);
	}
	return T;
}
void LevelTraverse(BiTree &T)
{
	BiTree p;
   SeQueue q;
   q.f=0;
   q.r=0;
   if(T==NULL)
	   exit(0);   
	   q.data[q.r].d=T;
	   q.r=(q.r+1)%MAXSIZE;
   while(q.r!=q.f)
   {
	  p=q.data[q.f].d;
	  printf("%c",p->data);
	  q.f=(q.f+1)%MAXSIZE;
   if(p->lchild)
   {
	   q.data[q.r].d=p->lchild;
       q.r=(q.r+1)%MAXSIZE;
   }
   if(p->rchild)
   {
	   q.data[q.r].d=p->rchild;
       q.r=(q.r+1)%MAXSIZE;
   }
   }
   printf("\n");
}

void count(BiTree T)
{
    BiTree p;
   SeQueue q;
   int count=0,width=0,i=1;
   q.f=0;
   q.r=0;
   if(T==NULL)
	   exit(0);   
	   q.data[q.r].d=T;
	   q.data[q.r].flag=1;
	   q.r=(q.r+1)%MAXSIZE;
   while(q.r!=q.f)
   {
	   p=q.data[q.f].d;
	   if(q.data[q.f].flag!=i)
	   {i=q.data[q.f].flag;
	   count=1;}
	   count++;
	   if(width<count)
		  width=count;
	  q.f=(q.f+1)%MAXSIZE;
   if(p->lchild)
   {
	   q.data[q.r].d=p->lchild;
	   q.data[q.r].flag=q.data[q.f].flag+1;
       q.r=(q.r+1)%MAXSIZE;
   }
   if(p->rchild)
   {
	   q.data[q.r].d=p->rchild;
	   q.data[q.r].flag=q.data[q.f].flag+1;
       q.r=(q.r+1)%MAXSIZE;
   }
   }
   printf("%d",width);
   printf("\n");
}
main()
{
	BiTree T;
	int choice;
	do{
		system("cls");
	printf("===========================================================\n");
	printf("\n");
	printf("           1.�����������Ķ�������洢��ʾ\n");
	printf("           2.����ѭ��������Ʒǵݹ��㷨ʵ�ֶ������Ĳ�α���\n");
	printf("           3.��Ʒǵݹ��㷨��������Ŀ��\n");
	printf("           0.�˳�\n");
	printf("\n");
	printf("===========================================================\n");
	printf("��������Ҫ�����Ĳ���:\n");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice)
	{
	case 1:
		printf("�����������:\n");
		T=CreateBiTree(T);
		system("pause");
		break;
    case 2:
		printf("������Ķ�����:\n");
        LevelTraverse(T);
        system("pause");
		break;
	case 3:
		printf("����������Ŀ��:\n");
		count(T);
		system("pause");
	}
	}while(choice!=0);
}

