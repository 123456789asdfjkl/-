#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int LNode;

typedef struct Ploy
{
	float coef;
	int exp;
	struct Ploy *next;
}Polynode,*LinkList;
// �������ʽ��������

int LinkList_TailCreate(LinkList &L);				//β�巨����
int LinkList_ExpInscending(LinkList &L, int len);		//ָ������������
int LinkList_ExpInscendingElementPrint(LinkList &L, int len);	//ָ�������������Ԫ��
int LinkList_Reverse(LinkList &L);			//�͵����ú���
int LinkList_Cuculate(LinkList &L);				//���������x��ֵ
int LinkList_Add(LinkList &A, LinkList &B);		//����һԪ����ʽ���
int LinkList_Print(LinkList &L);				//�������
int LinkList_MergeSame(LinkList &L);				//�ϲ�ͬ�����

int LinkList_TailCreate(LinkList &L)//����ÿһ��ϵ����ָ��
{
	LinkList p, s;
	int coef, exp, i, length, len;
	L = (LinkList)malloc(sizeof(int));
	L->next = NULL;
	p = L;
	printf("�������һԪ����ʽ������:");
	scanf("%d", &length);
	for (i = 0; i < length; i++)
	{
		printf("�������%d��ϵ��:", i + 1);
		scanf("%d", &coef);
		printf("�������%d��ָ��:", i + 1);
		scanf("%d", &exp);
		while (coef == 0)
		{
			printf("��Ч��!����������!\n");
			printf("�������%d��ϵ��:", i + 1);
			scanf("%d", &coef);
			printf("�������%d��ָ��:", i + 1);
			scanf("%d", &exp);
		}
		s = (LinkList)malloc(sizeof(int));
		s->coef = coef;
		s->exp = exp;
		s->next = NULL;
		p->next = s;
		p = p->next;
	}
	len = LinkList_MergeSame(L);
	length -= len;
	printf("�½���һԪ����ʽΪ:");
	LinkList_Print(L);
	system("pause");
	return length;
}
 
int LinkList_ExpInscending(LinkList &L, int len)//ָ��exp��������
{
	LinkList p, q, r;
	int i, j, done=1;
	p = L->next;
	if (p == NULL || p->next == NULL)
	{
		printf("��������!\n");
		return 0;
	}
	for (i = 1; i <= len - 1 && done; i++)//ð������
	{
		done = 0;
		r = L;
		p = r->next;
		q = p->next;
		for (j = 0; j < len - i; j++)
		{
			if (p->exp > q->exp)
			{
				p->next = q->next;
				q->next = p;
				r->next = q;
				q = p->next;
				r = r->next;
				done = 1;
			}
			else
			{
				r = p; 
				p = q;
				q = q->next;
			}
		}
	}
	printf("ָ���������к�Ϊ:");
	LinkList_Print(L);
	system("pause");
	return 1;
}
 
int LinkList_ExpInscendingElementPrint(LinkList &L, int len)//ָ���������ϵ����ָ��
{
	LinkList p,q,r;
	int k = 1, i, j, done = 1;
	p = L->next;
	if (p == NULL)
	{
		printf("Empty List!");
		return 0;
	}
	for (i = 1; i <= len - 1 && done; i++)//ð������
	{
		done = 0;
		r = L;
		p = r->next;
		q = p->next;
		for (j = 0; j < len - i; j++)
		{
			if (p->exp > q->exp)
			{
				p->next = q->next;
				q->next = p;
				r->next = q;
				q = p->next;
				r = r->next;
				done = 1;
			}
			else
			{
				r = p;
				p = q;
				q = q->next;
			}
		}
	}
	printf("ָ�������������Ԫ��Ϊ:\n");
	p = L->next;
	while (p)
	{
		printf("��%d��ϵ��Ϊ%d,��%d��ָ��Ϊ%d\n", k, p->coef, k, p->exp);
		p = p->next;
		k++;
	}
	system("pause");
	return 1;
}
 
int LinkList_Reverse(LinkList &L)//�͵����ñ�Ϊָ���������õ�ͷ�巨�� 
{
	LinkList p, q;
	p = L->next;
	L->next = NULL;
	if (p == NULL)
	{
		printf("Empty List!");
		return 0;
	}
	while (p)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
	printf("���ú�Ϊ:");
	LinkList_Print(L);
	system("pause");
	return 1;
}
 
int LinkList_Cuculate(LinkList &L)//��Ч�㷨�������Ա���x��һԪ����ʽ��ֵ
{
	LinkList p, q;
	int sum = 0, result = 0, q_expresult = 1, x;
	printf("�������Ա���x:");
	scanf("%d", &x);
	p = L->next;
	q = L;
	q->exp = 0;
	if (p == NULL)
	{
		printf("Epmty List!");
		return 0;
	}
	while (p)
	{
		result = pow(x, p->exp - q->exp)*q_expresult;//����ǰһ���������x����
		q_expresult = result;
		sum = sum + p->coef*result;
		q = p;
		p = p->next;
	}
	printf("x=%dʱ,����ʽֵy=%d\n", x, sum);
	system("pause");
	return sum;
}
 
int LinkList_Add(LinkList &A, LinkList &B)//������һԪ����ʽ�ĺͶ���ʽ
{
	LinkList pa, pb, r, s;
	int len = 0;
	pa = A->next;
	pb = B->next;
	s = A;
	free(B);
	while (pa != NULL && pb != NULL)
	{
		if (pa->exp < pb->exp)
		{
			r = pa;
			pa = pa->next;
			s->next = r;
			s = r;
		}
		else if (pa->exp > pb->exp)
		{
			r = pb;
			pb = pb->next;
			s->next = r;
			s = r;
		}
		else if (pa->exp == pb->exp)
		{
			pa->coef = pa->coef + pb->coef;
			r = pb->next;
			free(pb);
			pb = r;
			if (pa->coef == 0)
			{
				r = pa->next;
				free(pa);
				pa = r;
			}
			else
			{
				r = pa;
				pa = pa->next;
				s->next = r;
				s = r;
			}
		}
	}
	if (pa == NULL)
		s->next = pb;
	if (pb == NULL)
		s->next = pa;
	printf("��Ӻ�ǰ�µ�һԪ����ʽΪ:");
	LinkList_Print(A);
	r = A->next;
	while (r)
	{
		len++;
		r = r->next;
	}
	system("pause");
	return len;
}
 
int LinkList_Print(LinkList &L)
{
	LinkList p;
	p = L->next;
	if (p == NULL)
	{
		printf("Epmty List!");
		return 0;
	}
	printf("y = ");
	while (p != NULL)
	{
		if (p->exp == 0)
			printf("%.2f", p->coef);
		else
			printf("%.2fx^%d", p->coef, p->exp);
		p = p->next;
		if (p != NULL)
			printf(" + ");
	}
	printf("\n");
	return 1;
}
 
int LinkList_MergeSame(LinkList &L)
{
	LinkList p, q;
	int len = 0;
	p = L->next;
	if (p == NULL || p->next == NULL)
		return 0;
	while (p->next)
	{
		if (p->exp == p->next->exp)
		{
			q = p->next;
			p->coef += q->coef;
			p->next = q->next;
			free(q);
			len++;
		}
		else
			p = p->next;
	}
	return len;
}

int main()
{
	LinkList A,B;
	int n,number;
	int len[20], i=0;
	int j;
	float x;
	for(j=0;j<20;j++)
	{
		len[j]=0; 
	}
	while(1)
	{
		system("cls");
//		�����һ������ 
		printf("------------------------------\n");
		printf("\t 1.����һԪ����ʽ\n");
		printf("\t 2.��һԪ����ʽ����ָ����������\n");
		printf("\t 3.��ָ���������һԪ����ʽϵ����ָ��\n");
		printf("\t 4.����һԪ����ʽ\n");
		printf("\t 5.����x,����һԪ����ʽ��ֵ\n");
		printf("\t 6.������һԪ����ʽ�ĺͶ���ʽ\n");
		printf("\t 7.�˳�\n");
		printf("�����\n");
		scanf("%d",&number);
		switch (number)
		{
			case 1: 
			{ 
				system("cls");
				if (len[i] != 0)
				{
					printf("�Ѵ�������һԪ����ʽ����ѡ����Ҫ�Ĳ���!\n");
					LinkList_Print(A);
					system("pause");
					break;
				}
				printf("���ڽ�����1��һԪ����ʽ\n");
				len[++i]=LinkList_TailCreate(A); 
				break; 
			}
			case 2: 
			{ 
				if (len[i] == 0)
				{
					printf("û�пɲ����ı�!���Ƚ���!\n");
					system("pause");
					break;
				}
				system("cls");
				LinkList_ExpInscending(A,len[i]); 
				break; 
			}
			case 3: 
			{ 
				if (len[i] == 0)
				{
					printf("û�пɲ����ı�!���Ƚ���!\n");
					system("pause");
					break;
				}
				system("cls");
				LinkList_ExpInscendingElementPrint(A,len[i]); 
				break; 
			}
			case 4: 
			{ 
				if (len[i] == 0)
				{
					printf("û�пɲ����ı�!���Ƚ���!\n");
					system("pause");
					break;
				}
				system("cls");
				LinkList_Reverse(A); 
				break; 
			}
			case 5: 
			{ 
				if (len[i] == 0)
				{
					printf("û�пɲ����ı�!���Ƚ���!\n");
					system("pause");
					break;
				}
				system("cls");
				LinkList_Cuculate(A); 
				break;
			}
			case 6: 
			{ 
				system("cls");
				if (len[i] == 0)
				{
					printf("���ڽ�����%d��һԪ����ʽ\n",i+1);
					len[++i] = LinkList_TailCreate(A);
				}
				printf("��%d��һԪ����ʽ",i);
				LinkList_ExpInscending(A, len[i]);
				printf("���ڽ�����%d��һԪ����ʽ\n",i+1);
				len[++i] = LinkList_TailCreate(B);
				printf("��%d��һԪ����ʽ",i);
				LinkList_ExpInscending(B, len[i]); 
				len[++i] = LinkList_Add(A, B);
				break; 
			}
			case 7: { exit(0); break; }
		}
		
	}
	 
}
