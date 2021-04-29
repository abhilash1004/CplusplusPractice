#include<bits/stdc++.h>
using namespace std;
#define v 4
int issafe(int a[][v],int c[],int p,int i)
{
    int y,z;
    for(y=0;y<p;y++)
    {
        if(a[p][y]==1)
        {
            if(c[y]==i)
                return 0;
        }
    }
    return 1;
}

int place_colours(int a[][v],int c[],int m,int p=0)
{
    if(p>v)
        return 1;
    for(int i=1;i<=m;i++)
    {
        if(issafe(a,c,p,i))
        {
            c[p]=i;
            if(place_colours(a,c,m,p+1))
                return 1;
            c[p]=0;
        }
    }
    return 0;
}

int main()
{
    int m;
    cout<<"Enter m:";
    cin>>m;
    int a[v][v];
    cout<<"Enter adjacency matrix values:\n";
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            cin>>a[i][j];
    int colour[v]={0};
    if(!place_colours(a,colour,m))
        cout<<"Not possible\n";
    else
    {
        cout<<"Colours placed:\n";
        for(int i=0;i<v;i++)
            cout<<colour[i]<<"\t";
    }
    return 0;
}
