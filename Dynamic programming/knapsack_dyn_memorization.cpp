#include<bits/stdc++.h>
using namespace std;
int w[100],p[100],n;
int maxi(int a,int b)
{
    return a>b?a:b;
}
int func(int i,int c,int f[100][100])
{
    if(f[1][c]!=0)
    {
        return f[1][c];
    }
    if(i==n)
    {
        if(c<w[n])
        {
            f[i][c]=0;
            return f[i][c];
        }
        f[i][c]=p[n];
        return f[i][c];
    }
    if(c<w[i])
    {
        f[i][c]=func(i+1,c,f);
        return f[i][c];
    }
    else
    {
        f[i][c]=maxi(func(i+1,c,f),func(i+1,c-w[i],f)+p[i]);
        return f[i][c];
    }
}
int main()
{
    int cap;
    cout<<"Enter capacity and n:";
    cin>>cap>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"Enter weight and profit of "<<i<<"th container:";
        cin>>w[i]>>p[i];
    }
    int f[100][100]={0};
    cout<<"max profit ="<<func(1,cap,f);
    return 0;
}
