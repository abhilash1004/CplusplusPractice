#include<iostream>
using namespace std;
int FindDearrangements(int n,int f[])
{
    //cout<<endl;
    int ans = 0;
    for(int i=0;i<=n;i++)
    {
        if(i%2==0)
        {
            ans+=(f[n]/f[i]);
        }
        else
        {
            ans-=(f[n]/f[i]);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    if(n==0 )
    {
        cout<<"1";
        return 0;
    }
    if(n==1)
    {
        cout<<"0";
        return  0;
    }
    int f[n+1];
    f[0] = 1;
    f[1] = 1;
    for(int i=2;i<=n;i++)
    {
        f[i] = i*f[i-1];
        //cout<<f[i]<<" ";
    }
    for(int i=0;i<=n;i++)
        cout<<FindDearrangements(i,f)<<" ";
    cout<<endl;
    int i = 10;
    int *b = new int(i);
    cout<<*b<<" "<<b;
    return 0;
}
