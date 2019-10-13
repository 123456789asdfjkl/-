#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#define Elemtype int
typedef struct SList
{
    Elemtype data;
    struct SList *next;
}Node;

void initial(Node **head);
void push_back(Node *head,Elemtype x);
void show(Node *head);
Node* _buynode(Elemtype x);
void function(Node *ha,Node *hb,Node *hc);

int main()
{
    Node *ha,*hb,*hc;
    initial(&ha);
    initial(&hb);
    initial(&hc);

    printf("����������A��-1������\n");
    int x;
    while(1)
    {
        scanf("%d",&x);
        if(x==-1)
            break;
        push_back(ha,x);
    }
    printf("���ǵ�����a>>> \n");
    show(ha);

    printf("����������B��-1������\n");
    while(1)
    {
        scanf("%d",&x);
        if(x==-1)
            break;
        push_back(hb,x);
    }
    printf("���ǵ�����b>>> \n");
    show(hb);

    printf("����������C��-1������\n");
    while(1)
    {
        scanf("%d",&x);
        if(x==-1)
            break;
        push_back(hc,x);
    }
    printf("���ǵ�����c>>> \n");
    show(hc);

    printf("function����ĵ�����a>>>");
    function(ha,hb,hc);
    show(ha);
    return(1);
}

Node* _buynode(Elemtype x)
{//���㷨�Ĺ���������һ���ڵ㣬��������x�����ҷ��ظýڵ��ָ��
    Node *s=(Node*)malloc(sizeof(Node));
    assert(s!=NULL);

    s->data=x;//������ֵx
    s->next=NULL;
    return(s);//���ظýڵ�
}

void initial(Node **head)
{//���㷨�Ĺ����ǳ�ʼ��һ��ͷָ�룬ʹ��ָ��һ��ͷ���
    (*head)=(Node*)malloc(sizeof(Node));
    assert((*head)!=NULL);

    (*head)->data=0;//�ձ�
    (*head)->next=NULL;
}

void push_back(Node *head,Elemtype x)
{//���㷨��ǰ���ǵ������Ѿ���ʼ��
    //���㷨�Ĺ������ڵ������β������һ���µĽڵ㣬�ڵ��������
    //��ֵΪx
    Node *s=_buynode(x);
    Node *p=head;

    while(p->next!=NULL)
        p=p->next;//pָ�������β���ڵ�

    s->next=p->next;
    p->next=s;
    head->data++;//����һ
}

void show(Node *head)
{//���㷨��ǰ���������Ѿ���ʼ�����Ҳ���
    //���㷨�Ĺ�����������ʾ�������е�Ԫ��
    if(head->data==0)
        return;//���Ϸ����ж�

    Node *p=head;

    while(p->next!=NULL)
    {
        printf("%d-->",p->next->data);
        p=p->next;
    }
    printf("Null.\n");
}

void function(Node *ha,Node *hb,Node *hc)
{//���㷨��ǰ��������������Ϊ��
    //���㷨�Ĺ����ǳ�ȥ��a���ڱ�b�ͱ�cͬʱ���ֵ�Ԫ��
    if(ha->data==0 || hb->data==0 || hc->data==0)
        return;//���Ϸ����ж�

    Node *pa,*pb,*pc;
    pa=ha;
    pb=hb->next;
    pc=hc->next;

    while(pa->next && pb && pc)//��pa�ڵ���һ�����գ�pb,pc����
    {
        while(pb!=NULL && pc!=NULL && pb->data!=pc->data)//�ƶ�pb,pcֱ����ͬ
        {
            if(pb->data<pc->data)//���pb��С�����ƶ�pb
                pb=pb->next;
            else
                pc=pc->next;
        }
        if(pb!=NULL && pc!=NULL)//b���c��������ͬ��Ԫ��
        {
            while(pb->next!=NULL&&pb->data==pb->next->data || pc->next!=NULL&&pc->data==pc->next->data)//ʹpa��pb�����ظ�Ԫ���е����һ��Ԫ��
            {
                if(pb->next!=NULL && pb->data==pb->next->data)
                    pb=pb->next;
                if(pc->next!=NULL && pc->data==pc->next->data)
                    pc=pc->next;
            }
            while(pa->next!=NULL && pa->next->data<pb->data)
            {
                pa=pa->next;
            }
            if(pa->next!=NULL && pa->next->data==pb->data)
            {
                while(pa->next!=NULL && pa->next->data==pb->data)//ɾ���ظ���Ԫ��
                {
                    Node *q=pa->next;
                    pa->next=q->next;
                    free(q);
                    ha->data--;//����һ
                }
                pb=pb->next;
                pc=pc->next;//pa pbͬʱ�ƶ�����һ���ڵ�
            }
        }
    }
}

