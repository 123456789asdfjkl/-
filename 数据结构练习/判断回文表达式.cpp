#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
/**
	���ı��ʽ������a+bb+a�����ʽ������@Ϊ������־ 
**/
typedef struct{
	char data[MAXSIZE];
	int top;
}SeqStack; //����ջ 
void judge()
{
	SeqStack s;
	s.top=-1;
	char ch;
	printf("������Ҫ�жϵı��ʽ��\n");
	while(1)
	{
		scanf("%c",&ch);
		if(ch=='@')
		{
			break;
		}
		else
		{
			if(s.top==-1)
			{
				s.data[++s.top]=ch;
			}
			else
			{
				if(ch==s.data[s.top])
				{
					s.top--;
				}
				else
				{
					s.data[++s.top]=ch; 
				}
			}
		}
	}
	if(s.top==-1)
	{
		printf("�ñ��ʽΪ���ı��ʽ\n"); 
	}
	else
	{
		printf("�ñ��ʽ���ǻ��ı��ʽ\n"); 
	}
}
int main()
{
	judge();
}
