#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct BiTNode{
	char data;
	struct BiTNode *lc,*rc;
}BiTNode ,*BiTree;
typedef struct {
	BiTree t;
	int flag;
}Element;
typedef struct{
	Element a[MAXSIZE];
	int i;
}SeqStack;
typedef struct{
	Element b[MAXSIZE];
	int f;
	int r;
}SeqQueue;
void CreateBiTree(BiTree &T)//���������� ��������������� 
{
	char a;
	scanf("%c",&a);
	if(a=='#')
	{
		T=NULL;
	}
	else
	{
		if(!(T=(BiTree)malloc(sizeof(BiTNode))))
		{
			exit(-2);
		}
		T->data=a;
		CreateBiTree(T->lc);
		CreateBiTree(T->rc);		
	}	 
}
void ccbl(BiTree &T)//�������Ĳ�α��� 
{
	SeqQueue l;
	BiTree p;
	p=T;
	l.f=0;
	l.r=0;
	int count=1;
	l.b[l.r++].t=p;
	while(l.f!=l.r)
	{
		if(p->lc)
		{
			if(l.r>=MAXSIZE)
			{
				exit(-2);
			}
			l.b[l.r++].t=p->lc;
			count++;
		}
		if(p->rc)
		{
			if(l.r>=MAXSIZE)
			{
				exit(-2);
			}
			l.b[l.r++].t=p->rc;
			count++;
		}
		p=l.b[++l.f].t;
	}
	for(l.r=0;l.r<count;l.r++)
	{
		printf("%c ",l.b[l.r].t->data);
	}
	printf("\n");
	
	
}
void WidthAndDeepth(BiTree &T)//��������Ŀ�ȡ���Ⱥ�Ԫ�ظ��� �����ڵ���Ϊ1���ӽڵ�Ϊ���ڵ���+1�� 
{
	int a[2];
	SeqQueue l;
	BiTree p;
	p=T;
	l.f=0;
	l.r=0;
	int count=1;
	int deepth=0;
	int width=0;
	int k=1;
	int num=0;
	l.b[l.r].t=p;
	l.b[l.r].flag=1;
	l.r++;
	while(l.f!=l.r)
	{
		if(p->lc)
		{
			if(l.r>=MAXSIZE)
			{
				exit(-2);
			}
			l.b[l.r].t=p->lc;
			l.b[l.r].flag=l.b[l.f].flag+1;
			l.r++;
			count++;
		}
		if(p->rc)
		{
			if(l.r>=MAXSIZE)
			{
				exit(-2);
			}
			l.b[l.r].t=p->rc;
			l.b[l.r].flag=l.b[l.f].flag+1;
			l.r++;
			count++;
		}
		p=l.b[++l.f].t;
	}
	for(l.r=0;l.r<count;l.r++)
	{
		if(l.b[l.r].flag==k)
		{
			num++;
			if(num>width)
			{
				width=num;
			}
		}
		else
		{
			num=1;
			k=l.b[l.r].flag;
		}
	}
	deepth=k;
	printf("�ö����������Ϊ%d\n",deepth);
	printf("�ö������Ŀ��Ϊ%d\n",width);
	printf("�ö�������Ԫ�ظ���Ϊ%d\n",count);
	
}
void xxbl(BiTree &T)//������������� 
{
	SeqStack q;
	BiTree p;
	q.i=-1;
	p=T;
	while(p)
	{
		while(p)
		{
			printf("%c ",p->data);
			if(p->rc)
			{
				if(q.i==MAXSIZE-1)
				{
					exit(-2);
				}
				else
				{
					q.a[++q.i].t=p->rc;
				}
			}
			p=p->lc;
		}
		if(q.i!=-1)
		{
			p=q.a[q.i--].t;
		}
	}
} 
void zxbl(BiTree &T)//������������� 
{
	SeqStack s;
	BiTree p;
	p=T;
	s.i=-1;
	while(p||s.i!=-1)
	{
		while(p)
		{
			if(s.i==MAXSIZE-1)
			{
				exit(-2);
			}
			else
			{
				s.a[++s.i].t=p;
				p=p->lc;
			}
		}
		if(s.i!=-1)
		{
			printf("%c ",s.a[s.i].t->data);
			p=s.a[s.i].t->rc;
			s.i--;
		}
	}
}
void hxbl(BiTree &T)//������������� 
{
	SeqStack s;
	BiTree p;
	p=T;
	s.i=-1;
	do
	{
		while(p)
		{
			s.a[++s.i].t=p;
			s.a[s.i].flag=0;
			p=p->lc;
		}
		while((s.i>-1)&&(s.a[s.i].flag==1))
		{
			p=s.a[s.i--].t;
			printf("%c ",p->data);
		}
		if(s.i!=-1)
		{
			s.a[s.i].flag=1;
			p=s.a[s.i].t;
			p=p->rc; 
		}
	}while(s.i>-1);
}
int main()
{
	BiTree T;
	printf("�밴�����������һ��������\n");
	CreateBiTree(T);
	printf("��α��������\n"); 
	ccbl(T);
	WidthAndDeepth(T);
	printf("���������������\n");
	xxbl(T);
	printf("\n");
	printf("�������������:\n");
	zxbl(T);
	printf("\n");
	printf("�������������:\n");
	hxbl(T);
	return 0;
}
