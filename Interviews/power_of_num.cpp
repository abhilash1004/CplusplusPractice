#include<iostream>
using namespace std;
float pow(float x,int n)
{
    float temp;
    if(n==0)
        return 1;
    temp=pow(x,n/2);
    if(n%2==0)return temp*temp;
    else
    {
        if(n>0)
        {
            return x*temp*temp;
        }
        else
            return (temp*temp)/x;
    }

}
int main()
{
    int n;
    float x;
    cout<<"Enter number and power:";
    cin>>x>>n;
    cout<<"answer="<<pow(x,n);
    return 0;
}
