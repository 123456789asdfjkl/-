#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
	char data;
	struct BiTNode *lc,*rc;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T)//���������� 
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
void exchange(BiTree T)//�ݹ��㷨�������н������Һ��� 
{
	BiTree p; 
	if(T->lc||T->rc)
	{
		p=T->lc;
		T->lc=T->rc;
		T->rc=p;
		if(T->lc)
		{
			exchange(T->lc);
		}
		if(T->rc)
		{
			exchange(T->rc);
		}
	}
}
void xxbl(BiTree &T)//�ݹ鷨������������� 
{
	if(T)
	{
		printf("%c",T->data);
		xxbl(T->lc);
		xxbl(T->rc);
	}
}
void zxbl(BiTree &T)//�ݹ鷨������������� 
{
		if(T)
	{
		zxbl(T->lc);
		printf("%c",T->data);
		zxbl(T->rc);
	}
}
int main()
{
	BiTree T;
	printf("�밴�����������һ��������"); 
	CreateBiTree(T);
	printf("����ǰ��������Ľ��Ϊ��"); 
	xxbl(T);
	printf("\n");
	printf("����ǰ��������Ľ��Ϊ:");
	zxbl(T);
	printf("\n"); 
	exchange(T);
	printf("��������������Ľ��Ϊ:");
	xxbl(T);
	printf("\n");
	printf("��������������Ľ��Ϊ:");
	zxbl(T);
	printf("\n");	
} 
