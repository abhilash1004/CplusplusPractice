#include<bits/stdc++.h>
using namespace std;
int m[100][100]={0},r[100],n,key[100][100];
int c(int i,int j)
{
    if(m[i][j]!=0)
        return m[i][j];
    if(i==j)
        return 0;
    if(i==j-1)
     {
         m[i][j]=r[i]*r[i+1]*r[i+2];
         key[i][j]=i;
         return m[i][j];
     }
     int u=9999;
     key[i][j]=-1;
     int t;
     for(int k=i;k<j;k++)
     {
         t=c(i,k)+c(k+1,j)+r[i]*r[k+1]*r[j+1];
         if(t<u)
         {
             u=t;
             key[i][j]=k;
         }
     }
     m[i][j]=u;
     return m[i][j];
}
int main()
{
    int i;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter dimension array:";
    for(i=1;i<=n+1;i++)
        cin>>r[i];
    cout<<"Least cost="<<c(1,n)<<endl;
    cout<<"key="<<key[1][n]<<endl;
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<key[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}
