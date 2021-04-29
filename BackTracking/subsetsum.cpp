#include<bits/stdc++.h>
using namespace std;
int total=0;
void find_sub_sets(int a[],int v[],int n,vector<int> nodes,int x,int p,int sum=0)
{
    sum+=a[p];
    v[p]=1;
    nodes.push_back(a[p]);
    if(sum==x)
    {
        for(int i=0;i<nodes.size();i++)
            cout<<nodes[i]<<"\t";
        total+=nodes.size();
        cout<<" || ";
        nodes.pop_back();
       /* for(int i=0;i<nodes.size();i++)
            nodes.pop_back();*/
        return;
    }
    if(sum>x)
    {
        nodes.pop_back();
        v[p]=0;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            find_sub_sets(a,v,n,nodes,x,i,sum);
            v[i]=0;
        }
    }
}
void sub_sets(int a[],int v[],int n,vector<int> nodes,int x)
{
    for(int i=0;i<n;i++)
        find_sub_sets(a,v,n,nodes,x,i);
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    int a[n],v[n]={0};
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int x;
    cout<<"Enter x:";
    cin>>x;
    vector<int> nodes;
    sub_sets(a,v,n,nodes,x);
    cout<<"\nTotal Nodes: "<<total;
    return 0;
}
