#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int a[n];
    cout<<"Enter input";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m=a[0];
    for(i=0;i<n-1;i++)
    {
        int sum=0;
        for(j=i+1;j<n;j++)
        {
            sum=sum+a[j];
            m=sum>m?sum:m;
        }
    }
    cout<<"Answer: "<<m;
}
