#include<iostream>
using namespace std;
int main()
{
    int i,j,n,sum=0;
    cout<<"Enter n:";
    cin>>n;
    int a[n],b[n];
    for(i=0;i<n;)
    {
        i++;
        a[i-1]=(i*(i+1))/2;        //You can Use this array
    }
    for(i=1;i<=n;i++)
    {
        sum+=i;
        b[i-1]=sum;             //Or You can use this array
    }
    for(i=0;i<n;i++)
    {
        for(j=1;j<=i+1;j++)
        {
            cout<<j;
            if(j!=i+1)
                cout<<"+";
        }
        cout<<"="<<b[i]<<endl;
    }
    return 0;

}
