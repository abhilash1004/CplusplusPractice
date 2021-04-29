#include<bits/stdc++.h>
using namespace std;
int date[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int mod(int a)
{
    if (a<0)
        return -a;
    else
        return a;
}
int dayrev(int r1,int r2,int mem,int tv,int n)
{
    int sum=0;
    while(tv!=0 && mem!=0)
    {
        sum*=r1;
        tv--;
        mem--;
        n--;
    }
    if(mem==0)
        return sum;
    else
    {
        while(n!=0)
        {
            if(mem==0)
                return sum;
            sum*=r2;
            mem--;
            n--;
        }
        return sum;
    }
}
int main()
{
    int n,rev,r1,r2,mem;
    cin>>n;
    cin>>r1>>r2;
    cin>>rev;
    int tv=0;
    while(tv<=n)
    {
        int tot_rev=0,f=0;
        for(int d=1;d<13;d++)
        {
            for(int i=1;i<=date[d];i++)
            {
                mem=pow(6-d,2)+mod(i-15);
                tot_rev+=dayrev(r1,r2,mem,tv,n);
                if(tot_rev>rev)
                {
                    f=1;
                    cout<<tv<<endl;
                    break;
                }
            }
            if(f==1)
                break;
        }
    }
    return 0;
}
