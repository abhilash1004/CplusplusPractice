#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int maxi(int a,int b)
{
    return a>b?a:b;
}
int ans=0;
class node
{
public:
    double info;
    node *next;
    node* insert_node(node *,double );
};
node *node::insert_node(node *start,double ele)
{
    node *temp=new node;
    temp->info=ele;
    temp->next;
    if(start==NULL)
    {
        return temp;
    }
    node *cur=start;
    while(cur->next!=NULL)
    {
        if(cur->info=ele)
            {
                ans++;
                return start;
                delete(temp);
            }
        cur=cur->next;
    }
    if(cur->next==NULL)
    {
        if(cur->info=ele)
            {
                ans++;
                return start;
                delete(temp);
            }
        cur->next=temp;
        return start;
    }
    return start;
}
int main()
{
    int n,i,j;
    node *start=NULL,t;
    double x,y,v,m=0;
    cin>>n;
    double time_reaching[n]={0};
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>v;
        m=sqrt(pow(x,2)+pow(y,2))/v;
        start=t.insert_node(start,m);
        //time_reaching[i]=(sqrt(pow(x,2)+pow(y,2)))/v;
        //m=maxi(time_reaching[i],m);
    }
   /* for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
          if(time_reaching[i]==time_reaching[j] && i!=j)
             ans++;
    }*/
    cout<<ans/2;
    cout<<ans<<endl;
    return 0;
    
}
