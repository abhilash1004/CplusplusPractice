#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char str[100];
    cout<<"Enter Number:";
    cin>>str;
    int n=strlen(str);
    int ans=0,i;
    for(i=0;i<n;i++)
    {
        int dig=str[i]-'0';
        ans=ans*10+dig;
    }
    cout<<"Answer in int:"<<ans;
    return 0;
}
