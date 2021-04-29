#include<bits/stdc++.h>
using namespace std;
#define inf 9999;
int mat[100][100];
void disp(int n,int a[][100])
{
    for(int i=0;i<n;i++)
    {   cout<<">";
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void floydwarshall(int n)
{
    int i,j,k;
    int dist[100][100];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           dist[i][j]=mat[i][j];
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    disp(n,dist);
}
int main()
{
    int n,i,j;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter adj matrix\n";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]==0 && i!=j)
                mat[i][j]=inf;
        }
    floydwarshall(n);
    return 0;
}
