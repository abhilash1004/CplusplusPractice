#include<bits/stdc++.h>
using namespace std;

/*int main()
{
    int n;
    cin>>n;
    int time[86400*2 + 1]={0};
    int ans=0,maxtime=0;
    //multimap <int,int> m;
    for(int i=0;i<n;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        //m.insert(pair <int, int> (n1, n2));
        for(int i=n1;i<=(n1+n2);i++)
        {
            time[i]++;
            ans = ans>time[i]?ans:time[i];
        }
    }
    cout<<ans;
    //int plat = 0,ans = 0,trains=0;
    return 0;
}*/

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int dept[n];
    for(int i=0;i<n;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        arr[i] = n1;
        dept[i] = n1+n2;
    }
    sort(arr,arr+n);
    sort(dept,dept+n);
    int i=1,plat=1,j=0,maxplat=1;
     while(i<n && j<n)
     {
         if(arr[i]<=dept[j])
         {
             plat++;
             if(plat>maxplat)
             {
                 maxplat = plat;
             }
             i++;
         }
         else
         {
             plat--;
             j++;
         }
     }
     cout<<maxplat;
    return 0;
}
