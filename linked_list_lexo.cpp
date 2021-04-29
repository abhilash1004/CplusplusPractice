#include<bits/stdc++.h>
using namespace std;
class llist
{
    int x,y;
    llist *next;
public:
    llist* insert_cord(llist*,int ,int );
    void disp(llist*);
};
llist* llist::insert_cord(llist* start,int x1,int y1)
{
    llist *temp =new llist;
    temp->next=NULL;
    temp->x=x1;
    temp->y=y1;
    if(start==NULL)
        return temp;
    if(start->next==NULL)
    {
        if(start->x > temp->x)
        {
            temp->next=start;
            return temp;
        }
        else if(start->x == temp->x)
        {
            if(start->y > temp->y)
            {
                temp->next=start;
                return temp;
            }
        }
        start->next=temp;
        return start;
    }
    llist* cur=start;
    llist* prev=NULL;
    while(cur!=NULL && cur->x < temp->x )
    {
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
    {
        prev->next=temp;
        return start;
    }

           if(cur->x == temp->x)
           {

               while(cur!=NULL && cur->y < temp->y && cur->x==temp->x)
               {
                   prev=cur;
                   cur=cur->next;
               }
               if(cur==NULL)
               {
                   prev->next=temp;
                   return start;
               }
               if(cur==start)
                 start=temp;
               else
                 prev->next=temp;
               temp->next=cur;
               return start;
           }
           if(cur==start)
             start=temp;
           else
            prev->next=temp;
           temp->next=cur;
           return start;
}
void llist::disp(llist* start)
{
    llist* cur=start;
    for(;cur!=NULL;cur=cur->next)
        cout<<cur->x<<","<<cur->y<<"\t";
    cout<<endl;
}
int main()
{
    llist *start=NULL,r;
    int x,y;
    cout<<"Enter 0,0 to exit:\n";
    do
    {
        cout<<"Enter x & y: ";
        cin>>x>>y;
        if(x==0 && y==0)
            continue;
        start=r.insert_cord(start,x,y);
        r.disp(start);
    }while(!(x==0&&y==0));
    cout<<"Enjoy Himanish :)";
    cout<<"\n:) :) BYE :( :(";
    return 0;
}
