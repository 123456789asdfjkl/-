#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct ArcNode{
	int vex;//�û���ָ��Ķ����λ�� 
	struct ArcNode *link;//ָ����һ������ָ�� 
	int *info;//�û������Ϣ��ָ�� 
}ArcNode; 
typedef struct VNode{
	char data;
	ArcNode *firstarc;//ָ���һ����ʱ�����ö���Ļ� 
}VNode; 
typedef struct{
	VNode arc[MAXSIZE];
	int vexnum;//ͼ�Ķ����� 
	int arcnum;//ͼ�ı��� 
	int kind;//ͼ������ 
}Graphs;
int visited[MAXSIZE];
void CreatGraphs(Graphs &G)//��������ͼ������ͼ 
{
	int i;
	int j,k;
	ArcNode *p,*q;
	printf("�������ͼ�����ͣ�1��ʾ����ͼ��0��ʾ����ͼ��\n");
	scanf("%d",&G.kind); 
	printf("�����붥������");
	scanf("%d",&G.vexnum);
	printf("�����������");
	scanf("%d",&G.arcnum);
	printf("�����붥�㣺");
	for(i=0;i<G.vexnum;i++)
	{
		getchar();
		scanf("%c",&G.arc[i].data);
		G.arc[i].firstarc=NULL;	
	}
	printf("��������ߣ�\n");
	if(G.kind==1)
	{
		for(i=1;i<=G.arcnum;i++)
		{
			printf("�������%d���ߣ�",i);
			scanf("%d %d",&j,&k);
			p=(ArcNode*)malloc(sizeof(ArcNode));
			p->vex=k;
			p->link=G.arc[j].firstarc;
			G.arc[j].firstarc=p;		
		}
    }
    else
    {
    	for(i=1;i<=G.arcnum;i++)
		{
			printf("�������%d���ߣ�",i);
			scanf("%d %d",&j,&k);
			p=(ArcNode*)malloc(sizeof(ArcNode));
			p->vex=k;
			p->link=G.arc[j].firstarc;
			G.arc[j].firstarc=p;
			q=(ArcNode*)malloc(sizeof(ArcNode));
			q->vex=j;
			q->link=G.arc[k].firstarc;
			G.arc[k].firstarc=q;
					
		}
	}
}
void DFS(Graphs G,int v)//����������� 
{
	visited[v]=1;
	printf("%c ",G.arc[v].data);
	int w;
	ArcNode *p;
	for(p=G.arc[v].firstarc;p!=NULL;p=p->link)
	{
		w=p->vex;
		if(!visited[w])
		{
			DFS(G,w);
		}
	}
}
void DFS1(Graphs G,int v)//����������� 
{
	visited[v]=1;
	int w;
	ArcNode *p;
	for(p=G.arc[v].firstarc;p!=NULL;p=p->link)
	{
		w=p->vex;
		if(!visited[w])
		{
			DFS1(G,w);
		}
	}
}
void DFSTravers(Graphs G)//����������� 
{
	int v;
	for(v=0;v<G.vexnum;++v)
	{
		visited[v]=0;
	}
	for(v=0;v<G.vexnum;++v)
	{
		if(!visited[v])
		{
			DFS(G,v);
		}
	}
	printf("\n"); 
}
void judgeundirected(Graphs G)//�ж�����ͼ��ͨ�� 
{
	int v;
	for(v=0;v<G.vexnum;++v)
	{
		visited[v]=0;
	}
	DFS1(G,0);
	for(v=0;v<G.vexnum;++v)
	{
		if(!visited[v])
		{
			printf("������ͼ������ͨ��\n");
			return;
		}
	}
	printf("������ͼ����ͨ��\n");
	
}
void judgedirected(Graphs G)//�ж�����ͼ��ͨ�� 
{
	int v;
	int i;
	for(i=0;i<G.vexnum;++i)
	{
		for(v=0;v<G.vexnum;++v)
		{
			visited[v]=0;
		}
		DFS1(G,i);
		for(v=0;v<G.vexnum;++v)
		{
			if(!visited[v])
			{
				printf("������ͼ������ͨ��\n");
				return;
			}
		}
	}
	printf("������ͼ����ͨ��\n");
}
void judge(Graphs G,int i,int j)//�ж����ڵ���Ƿ���·�� 
{
	int v;
	for(v=0;v<G.vexnum;++v)
	{
		visited[v]=0;
	}
	DFS1(G,i);
	if(!visited[j])
	{
		printf("%c��%c֮�䲻����·��\n",G.arc[i].data,G.arc[j].data);
		return;
	}
	printf("%c��%c֮�����·��\n",G.arc[i].data,G.arc[j].data);
}
int main()
{
	Graphs G;
	int i;
	int j;
	CreatGraphs(G);
	DFSTravers(G);
	if(G.kind==0)
	{
		judgedirected(G);
	}
	else
	{
		judgeundirected(G);
	}
	printf("������Ҫ�жϵ������ڵ㣺");
	scanf("%d %d",&i,&j);
	judge(G,i,j); 
}
