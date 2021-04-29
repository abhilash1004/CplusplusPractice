#include<bits/stdc++.h>
using namespace std;

int SumOfPrime(int n)
{
    int flag[n+1]={0};
    if(n<2)
        return 0;
    int ans=0;
    for(int i=2;i<n+1;i++)
    {
        if(flag[i]==1)
            continue;
        ans+=i;
        for(int j=i*i;j<=n;j+=i)
        {
            flag[j] = 1;
        }
    }
   /* for(int i=2;i<n+1;i++)
    {
        cout<<i<<" = "<<flag[i]<<"; ";
    }
    cout<<endl;*/
    return ans;

}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<SumOfPrime(n)<<endl;
    }
}
