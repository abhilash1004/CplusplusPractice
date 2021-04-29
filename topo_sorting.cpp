#include<iostream>
using namespace std;
class que
{
    int a[100],f,r;
public:
    void enque(int n)
    {
        if(r!=99)
        a[r++]=n;
    }
    int dequ()
    {
        if(f<r)
           return a[f++];
    }
    int isempty()
    {
        if(f<r)
            return 0;
        return 1;
    }
    que()
    {
        r=-1;
        f=-1;
    }
};
int main()
{
    int i,j,n;
    que q;
    cout<<"Enter no of vertices:\n";
    cin>>n;
    int a[n][n],in[n]={0};
    cout<<"Enter adjaacency matrix\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            in[j]=in[j]+a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        if(in[i]==0)
            q.enque(i);
    }
    while(!q.isempty())
    {
        int v=q.dequ();
        cout<<v<<" ";
        for(i=0;i<n;i++)
        {
            if(a[v][i]==1)
            {
                in[i]--;
                if(in[i]==0)
                {
                    q.enque(i);
                }
            }
        }
    }
    return 0;
}
