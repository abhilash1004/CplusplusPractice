#include<bits/stdc++.h>
using namespace std;
int w[100],p[100],n;
int maxi(int a,int b)
{
    return a>b?a:b;
}
int func(int i,int c)
{
    if(i==n)
    {
        if(c<w[n])
            return 0;
        return p[n];
    }
    if(c<w[i])
        return func(i+1,c);
    return maxi(func(i+1,c),func(i+1,c-w[i])+p[i]);
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
    cout<<"max profit ="<<func(1,cap);
    return 0;
}
