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
void hxbl(BiTree &T)//�ݹ鷨������������� 
{
		if(T)
	{
		hxbl(T->lc);
		hxbl(T->rc);
		printf("%c",T->data);
	}
}
int main()
{
	BiTree T;
	printf("�밴�����������һ��������\n");
	CreateBiTree(T);
	printf("����������:\n");
	xxbl(T);
	printf("\n");
	printf("����������:\n");
	zxbl(T);
	printf("\n");
	printf("����������:\n");
	hxbl(T);
	printf("\n");
	return 0;
}
