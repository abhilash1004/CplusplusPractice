#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int fib(int n)
{
	int f[n];
	if(n==1)
	return 1;
	f[0]=0;
	f[1]=1;
	for(int i=2;i<n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    return f[n-1]+f[n-2];
}

int main ()
{
	int n;
	cout<<"Enter n:";
	cin>>n;
	cout <<fib(n)<<" ";
	return 0;
}

