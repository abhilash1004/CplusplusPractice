#include<bits/stdc++.h>
using namespace std;
int gs(int n)
{
    if(n<=0)
        return 0;
    if(n==1)
        return 1;
    return 1+gs(n-gs(gs(n-1)));
}
printgolombRecursion(int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<gs(i)<<" ";
    }
}
printgolombDynamic(int n)
{
    int dp[n + 1];
    dp[1] = 1;
    cout << dp[1] << " ";
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1 + dp[i - dp[dp[i - 1]]];
        cout << dp[i] << " ";
    }
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    //printgolombRecursion(n);
    cout<<endl;
    printgolombDynamic(n);
    return 0;
}
