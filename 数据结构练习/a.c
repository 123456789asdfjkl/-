#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int LNode;

typedef struct Ploy
{
	float coef;
	int expn;
	struct Ploy *next;
}Polynode,*LinkedList;
// �������ʽ��������

void Creat(LinkedList L)
{
	L=(LinkedList) malloc(sizeof(LNode));
	L->next=NULL;
} 
// ��������ͷ�Ŀյ����� 

void ListInput(LinkedList L) 
{
	int n,i;
	LinkedList p,q;
	L=(LinkedList) malloc(sizeof(LNode));
	L->next=NULL;
	q=L->next;
	printf("Input the length of ploy:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		LinkedList p=(LinkedList)malloc (sizeof(LNode));
		printf("please input the coef of ploy:\n");
		scanf("%f",&p->coef);
		printf("please input the expn of ploy:\n");
		scanf("%d",&p->expn);
		q->next=p;
		q=p;
	}
	q->next=NULL;
	
}
// ��������ͷ�ĵ�������һԪ����ʽ

void ListOutput(LinkedList L)
{ 
	LinkedList p;
	p=L->next;
	do
	{
	 	printf("ϵ��Ϊ%.2f,ֵΪ%d",p->coef,p->expn);
		p=p->next;
	}while(p!=NULL);
	
} 
// ���һԪ����ʽ��������Ԫ�� 

void Reverse(LinkedList L)
{
	LinkedList p,q;
	p=L->next;
	L->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		q=L->next;
		L->next=q;	
	} 
	printf("ԭ�����õĽ����");
	ListOutput(L);
}
// ʵ��һԪ����ʽ�ľ͵�����

void calculate(LinkedList L,int x)
{
	float sum=0;
	float y;
	int i;
	while(L!=NULL)
	{
		for(i=1;i<=L->expn;i++)
		{
			y=1*x;
		}
		sum+=y*L->coef;
	}
	printf("���Ϊ%f",sum);
} 
// ��������Ա�������ʽ��ֵ

 void add(LinkedList La,LinkedList Lb)
{
	LinkedList Lc,pc,pa,pb,ptr;
	float x;
	Creat(Lc);
	pc=Lc;
	pa=La->next;
	pb=Lb->next;
	while(pa!=NULL&&pb!=NULL)
	{
		if(pa->expn<pb->expn)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else if(pa->expn>pb->expn)
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
		else
		{
			x=pa->coef+pb->coef;
			if(x<=1e-6)
			{
				ptr=pa;
				pa=pa->next;
				free(ptr);
				ptr=pb;
				pb=pb->next;
				free(ptr);
			}
			else
			{
				pc=pa->next;
				pa->coef=x;
				pc=pa;
				pa=pa->next;
				ptr=pb;
				pb=pb->next;
				free(pb);
			}
		}
	} 
	if(pa==NULL)
	{
		pc->next=pb;
	}
	else
	{
		pc->next=pa;
	}
	ListOutput(Lc);
	
} 
//	������һԪ����ʽ�ϲ���һ������ʽ 

void main()
{
	LinkedList L,L1;
	int n,number;
	float x;
	do
	{
		system("cls");
//		�����һ������ 
		printf("------------------------------\n");
		printf("����һԪ����ʽ������---------1\n");
		printf("��ʾһԪ����ʽ������---------2\n");
		printf("�͵�����---------------------3\n");
		printf("��ֵ-------------------------4\n");
		printf("�ϲ���������ʽ---------------5\n");
		printf("�˳�-------------------------0\n");
		printf("�����\n");
		scanf("%d",&number);
		switch (number)
		{
			case 1:
				ListInput(L) ;
				break;
			case 2:
				printf("���ȴ���һԪ����ʽ������");
				ListInput(L) ;
				ListOutput(L);
				break;
			case 3:
				printf("���ȴ���һԪ����ʽ������");
				ListInput(L) ;
				Reverse(L);
				break;
			case 4:
				printf("���ȴ���һԪ����ʽ������");
				ListInput(L) ;
				printf("�������Ա�����ֵ��");
				scanf("%f",&x);
				calculate(L,x);
				break;
			case 5:
				printf("���ȴ���һԪ����ʽ������");
				ListInput(L) ;
				ListInput(L1);
				add(L,L1);
				break; 
		} 
	}while(number!=0);
	 
}

































