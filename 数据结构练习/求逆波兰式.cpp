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
void xxbl(BiTree &T)//�ݹ鷨���������������ǰ׺���ʽ������ʽ 
{
	if(T)
	{
		printf("%c",T->data);
		xxbl(T->lc);
		xxbl(T->rc);
	}
}
void zxbl(BiTree &T)//�ݹ鷨�����������������׺���ʽ 
{
		if(T)
	{
		zxbl(T->lc);
		printf("%c",T->data);
		zxbl(T->rc);
	}
}
void hxbl(BiTree &T)//�ݹ鷨����������������׺���ʽ���沨��ʽ 
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
	printf("������ǰ׺׺���ʽ��\n");
	CreateBiTree(T);
	printf("�ñ��ʽ�Ĳ���ʽ:\n");
	xxbl(T);
	printf("\n");
	printf("�ñ��ʽ����׺���ʽ:\n");
	zxbl(T);
	printf("\n");
	printf("�ñ��ʽ���沨��ʽ:\n");
	hxbl(T);
	printf("\n");
	return 0;
}
