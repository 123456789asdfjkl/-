#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct{
 	char ch[MAXSIZE];
 	int i;
}SqStack; 
void isbalance()//�ж��Ƿ����ƥ�� 
{
	SqStack S;
	char a;
	char b;
	S.i=-1;
	int flag=1;
	printf("������Ҫ�жϵı��ʽ����#��β��:\n");
	while(true)
	{
		scanf("%c",&a);
		if(a=='{'||a=='['||a=='(')
		{
			S.ch[++S.i]=a;
			continue;
		}
		if(a=='}'||a==')'||a==']')
		{
			b=S.ch[S.i--];
			if(a=='}'&&b=='{')
			{
				continue;	
			}
			if(a==')'&&b=='(')
			{
				continue;
			}
			if(a==']'&&b=='[')
			{
				continue;
			}
			flag=0;
			break;
		}
		if(a=='#')
		{
			break;
		}
	}
	if(flag&&S.i==-1)
	{
		printf("����ƥ��");
	}
	else
	{
		printf("���Ų�ƥ��");
	}
} 
int main()
{
	isbalance(); 
	return 0;	
}
