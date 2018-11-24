#include <iostream>
#include <stdio.h>

using namespace std;
struct node
{
    node *next=NULL;
    int data;
};

struct Line
{
    int number=0;
    node *first=NULL;
};
int create(Line *line);
int free(Line *line);

int main()
{
    Line *line;
    line=new(Line);
    for(int i=0;i<=2;i++)
    {

        create(line);
    }
    node *temp;
    temp=line->first;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    free(line);

}

int create(Line *line)
{   cout<<"请执行";
    line->number=line->number+1;
    cout<<line->number;
    node *temp;
    temp =line->first;

    if(temp==NULL)
    {
        line->first=new(node);
        cout<<"请输入数据"<<endl;
        cin>>line->first->data;

    }
    else
    {   while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new(node);
        cout<<"请输入数据"<<endl;
        cin>>temp->next->data;

    }
    return 0;
}
int free(Line *line)
{

    if(line->number!=0)
    {   node *temp;
        while(line->first!=NULL)
        {
            temp=line->first->next;
            delete(line->first);
            line->first=temp;
        }

    }
    cout<<"free操作完毕！";
}
