#include<bits/stdc++.h>
using namespace std;
int c=0;
void disp(int a[][100],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
         cout<<a[i][j]<<"\t";
    cout<<endl;
    }
}
void rotating(int a[][100],int m,int n,int k)
{
    int temp[m],i,j;
    k=k%n; c++;
    if(k<n-k)
    {
        c++;
        for(int cou=0;cou<k;cou++)
        {
            c+=3;
            for(i=0;i<m;i++)
             {
                temp[i]=a[i][n-1];
                c++;
             }
            for(j=n-2;j>=0;j--)
            {
                c++;
                for(i=0;i<m;i++)
                 {  c++;
                    a[i][j+1]=a[i][j];}
            }
            for(i=0;i<m;i++)
             {
                 c++;
                 a[i][0]=temp[i];
             }
        }
        return;
    }
    c++;
    for(int cou=0;cou<n-k;cou++)
    {
        c+=3;
        for(i=0;i<m;i++)
            {c++;temp[i]=a[i][0];}
        for(j=1;j<n;j++)
        {
            c++;
            for(i=0;i<m;i++)
                {c++;a[i][j-1]=a[i][j];}
        }
        for(i=0;i<m;i++)
            {a[i][n-1]=temp[i];c++;}
    }
}
int main()
{
    int a[100][100];
    int m,n,i,j,k;
    cout<<"Enter m and n:";
    cin>>m>>n;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    cout<<"Enter no of times it should rotate:";
    cin>>k;
    rotating(a,m,n,k);
    cout<<"answer after rotating:\n";
    disp(a,m,n);
    cout<<"\nTotal No of Steps="<<c<<endl;
    return 0;
}
