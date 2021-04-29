#include<iostream>
using namespace std;
char path[100];
int len=0;
int mover(int a[100][100],int m,int n)          //checks can we Move right
{
    if(a[m][n+1]==0)
        return 0;
    return 1;
}
int moved(int a[100][100],int m,int n)                //checks can we move down
{
    if(a[m+1][n]==0)
        return 0;
    return 1;
}
int find_path(int a[][100],int m,int n,int p,int q)
{
    if(a[p][q]==3)                                    //base case
    {
        return 1;
    }
    int mr=0,md=0;
    if((p+1)<m)
    {
        md=moved(a,p,q);
    }
    if((q+1)<n)
    {
        mr=mover(a,p,q);
    }
    if(mr==0&&md==0)
    {
        len--;          //removing last element from path since it came to a deadlock
        return 0;
    }
    int ans=0;
    if(md==1)
    {
        path[len++]='D';
        ans=find_path(a,m,n,p+1,q);
    }
    if(ans!=1&&mr==1)
    {
        path[len++]='R';
        ans=find_path(a,m,n,p,q+1);
    }
    if (ans==1) return 1;
    else
    {
        len--;
        return 0;
    }
}
int main()
{
    int m,n,p,q;
    cout<<"Enter m,n:";
    cin>>m>>n;
    int a[100][100];
    cout<<"Enter elements\n";   //enter s=2 and t=3
    for(int i=0;i<m;i++)
    {
        cout<<">";
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==2)
            {
                p=i;q=j;
            }
        }
    }
    int ans;
    ans=find_path(a,m,n,p,q);
    if(ans==1)
    {
        cout<<"Path:\n";
        for(int i=0;i<len;i++)
            cout<<path[i];
    }
    else
    {
        cout<<"Path doesn't exist";
    }
    return 0;

}
