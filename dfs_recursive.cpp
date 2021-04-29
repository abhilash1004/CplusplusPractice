#include<bits/stdc++.h>
using namespace std;
int mat[100][100];
int v[100]={0};
int dfs(int s,int n)
{
    v[s]=1;
    cout<<s+1;
    for(int i=0;i<n;i++)
    {
        if (mat[s][i]==1 && v[i]!=1)
        {
            dfs(i,n);
        }
    }
}
int main()
{
    int n,i,j,s;
    cout<<"Enter n";
    cin>>n;
    cout<<"Enter adj matrix\n";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>mat[i][j];
    cout<<"Enter source:";
    cin>>s;
    s--;
    dfs(s,n);
    return 0;
}
