#include<bits/stdc++.h>
using namespace std;
int findLargest(int a,int b,int c)
{
    int x=a>b?a:b;
    return x>c?x:c;
}
int findSmallest(int a,int b,int c)
{
    int x=a<b?a:b;
    return x<c?x:c;
}
int answer(int temp)
{
    int d1,d2,d3;
    d1=temp%10;
    temp/=10;
    d2=temp%10;
    temp/=10;
    d3=temp%10;
    temp/=10;
    //cout<<"Digits "<<d1<<d2<<d3;
    int ma=findLargest(d1,d2,d3);
    int mi=findSmallest(d1,d2,d3);
    //cout<<"mi="<<mi<<" ma="<<ma<<" returning "<<((ma*11)+(mi*7))<<" ";
    return ((ma*11)+(mi*7));
}
int main()
{
    int n,ans,pairs=0;
    cin>>n;
    int i;
    int a[n],score[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        //cout<<a[i]<<" ";
    }
    int odd[10]={0};
    int even[10]={0};
    //cout<<endl;
    for(i=0;i<n;i++)
    {
        int temp =a[i];
       // while(temp/1000==0 && temp/100!=0)
        //{
            //temp=temp%1000;
            //cout<<temp<<endl;
            //ans=answer(temp);
            //ans=ans%100;
            //temp=ans;
        //}
            int d1,d2,d3;
            d1=temp%10;
            temp/=10;
            d2=temp%10;
            temp/=10;
            d3=temp%10;
            temp/=10;
    //cout<<"Digits "<<d1<<d2<<d3;
            int ma=findLargest(d1,d2,d3);
            int mi=findSmallest(d1,d2,d3);
            ans=((ma*11)+(mi*7));
            ans=ans%100;
            score[i]=ans;
            ans/=10;
            if(i%2==0)
            {
                even[ans%10]++;
                if(even[ans%10]>1 )//&& even[ans%10]<4)
                {
                    pairs++;
                }
            }
            else
            {
                odd[ans%10]++;
                if(odd[ans%10]>1 )//&& odd[ans%10]<4)
                {
                    pairs++;
                }
            }

       /* for(i=0;i<10;i++)
        {
            cout<<even[i]<<" ";
        }
        cout<<endl;
        for(i=0;i<10;i++)
        {
            cout<<odd[i]<<" ";
        }*/
        //cout<<ans<<" ";
    }
    cout<<pairs;
    cout<<endl;
   /* for(i=0;i<10;i++)
        {
            cout<<even[i]<<" ";
        }
        cout<<endl;
        for(i=0;i<10;i++)
        {
            cout<<odd[i]<<" ";
        }*/
    return 0;
}
