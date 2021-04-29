/*Question:
Stock buy and sell 
Medium Accuracy: 30.43% Submissions: 100k+ Points: 4
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock 
so that in between those days your profit is maximum.

Input: 
First line contains number of test cases T. First line of each test case contains an integer value N denoting the number of 
days, followed by an array of stock prices of N days. 

Output:
For each testcase, output all the days with profit in a single line. And if there is no profit then print "No Profit".

Constraints:
1 <= T <= 100
2 <= N <= 103
0 <= Ai <= 104

Example
Input:
3
7
100 180 260 310 40 535 695
4
100 50 30 20
10
23 13 25 29 33 19 34 45 65 67

Output:
(0 3) (4 6)
No Profit
(1 4) (5 9)

Explanation:
Testcase 1: We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit.

Note: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
For each input, output should be in a single line.
*/
#include<bits/stdc++.h>
using namespace std;

int startV(int start,int n,int a[])
{
	for(int i=start+1;i<n;i++)
		{
			if(a[i]<a[start])
			{
				start = i;
				continue;
			}
			return start;
		}
	return -1;
}
int endV(int start,int n,int a[])
{
	for(int i=start+1;i<n;i++)
	{
		if(a[i]<a[start])
		{
			//cout<<"Hi\n";
			return i-1;
		}
		if(i==n-1)
			return i;
		start = i;
	}
	return -1;
}
int main()            
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,c=0;
		cin>>n;
		int a[n]={0};
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int start=startV(0,n,a);
		int end = endV(start,n,a);
		//cout<<start<<" "<<end<<" || ";
		while(start!=-1 && end!=-1 && start!=end)
		{
			cout<<"("<<start<<" "<<end<<") ";
			start = startV(end+1,n,a);
			end = endV(start,n,a);
			c++;
		   //cout<<start<<" "<<end<<" || ";
		}
		if(c==0)
		{
		    cout<<"No Profit";
		}
		cout<<endl;

	}


	return 0;
}