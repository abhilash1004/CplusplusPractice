#include<bits/stdc++.h>
using namespace std;

float findCubeRoot(int n)
{
	float ans;
	int start=0,end=n;
	int mid;
	while(start<=end)
	{
		mid = (start + end)/2;
		if(mid * mid * mid == n)
		{
			ans = mid;
			break;
		}
		if(mid * mid * mid < n)
		{
			start = mid+1;
			ans = mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	float incre = 0.1;
	for(int i=0;i<5;i++)
	{
		while(ans * ans * ans <= n)
		{
			ans = ans+incre;
		}
		ans = ans - incre;
		incre /= 10;
	}
	return ans;
}



int main()
{
	int t;
	cout<<"Enter No of Test Cases: ";
	cin>>t;
	while(t--)
	{
		int n;
		cout<<"Enter Number: ";
		cin>>n;
		cout<<findCubeRoot(n)<<endl;
	}
}