#include<stdio.h>
#include<stdlib.h>
 
typedef struct list
{
	char s;
	struct list* next;
}list;//������ 
 
typedef struct stack
{
	struct list* bottom;
	struct list* top;
}stack;//ջ 
 
void init(list* l,stack* s) //����ջ 
{
	l->next = NULL;
	l->s = '.';
	s->top = l;
	s->bottom = l;
}
 
void push(stack* stack,char c) //��ջ 
{
	list* lnew = (list* )malloc(sizeof(list));
	lnew->s = c;
	lnew->next = stack->top;
	stack->top = lnew;
}
 
char pop(stack* stack)  //��ջ 
{
	list* p;
	p = stack->top->next;
	char c;
	c = stack->top->s;
	free(stack->top);
	stack->top = p;
	return c;
}
 
int superior(char m,char n)//���ȼ���ʾ��1��ʾ���ȼ��ߣ�0��ʾ�ͣ�2��ʾ���
{
	int k[6][6] = 
	{1,1,0,0,0,1,
	 1,1,0,0,0,1,
	 1,1,1,1,0,1,
	 1,1,1,1,0,1,
	 0,0,0,0,0,2,
	 1,1,1,1,-1,1};
	if(n == '.')
	{
		return 1;
	}
	else
	{
		int a = 0,b = 0;
		if(m == '+') a = 0;
		if(m == '-') a = 1;
		if(m == '*') a = 2;
		if(m == '/') a = 3;
		if(m == '(') a = 4;
		if(m == ')') a = 5;
		if(n == '+') b = 0;
		if(n == '-') b = 1;
		if(n == '*') b = 2;
		if(n == '/') b = 3;
		if(n == '(') b = 4;
		if(n == ')') b = 5;
		return k[a][b];
	}
}
 
int main()
{
	list* head = (list* )malloc(sizeof(list));
	stack* pstack = (stack* )malloc(sizeof(stack));
	init(head,pstack);
	char s;
	char m[1000];//�����ַ�����洢�������
	int i, step = 0;
	
	while(1)
	{
		scanf("%c",&s);
		
		if(s == '\n')
		{
			break;
		}
		if(s >= 65 && s <= 90 || s >= 97 && s <= 122)//������ַ���ֱ�����
		{
			m[step] = s;
			step++;
			continue;
		}
		if(s == '(')//����ǡ���������ջ
		{
			push(pstack,s);
			continue;
		}
		if(s == ')')//����ǡ���������ջ��Ԫ�س�ջ��ֱ����������������ջ���������
		{
			while(pstack && pstack->top->s != '(')
			{
				//printf("%c", pstack->top->s);
				m[step] = pop(pstack);
				step++;
			}
			pop(pstack);
			continue;
		}
		if(superior(s,pstack->top->s) == 1)
		{
			push(pstack,s);
			continue;
		}
		else
		{
			while(superior(s,pstack->top->s) != 1 && pstack->top->s != '(')
			{
				m[step] = pop(pstack);
				step++;
			}
			push(pstack,s);
		}
	}
	
	for(i = 0;i < step;i++)
	{
		printf("%c",m[i]);
	}
	while(pstack->top != pstack->bottom)
	{
		printf("%c",pstack->top->s);
		pstack->top = pstack->top->next;
	}
	
	printf("\n");
	return 0;
}
