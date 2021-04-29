#include<iostream>
using namespace std;
int main()
{
    int i,j,n,c;
    cout<<"Enter n:";
    cin>>n;
    int a[n];
    for(i=1,j=0;j<n;i+=2,j++)
    {
        a[j]=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=i,c=0;c<n;j=(j+1)%n,c++)
        {
            cout<<a[j];
        }
        cout<<endl;
    }
    return 0;
}
