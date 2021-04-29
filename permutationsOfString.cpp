#include<bits/stdc++.h>
using namespace std;

//vector<string> ans;
set<string> ans;
void swap(char *a,char *b)
{
	char c;
	c = *a;
	*a = *b;
	*b = c;
}

void Permutate(string a,int l,int r)
{
	if(l==r)
	{
		//ans.push_back(a);
		ans.insert(a);
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(&a[l],&a[i]);
			Permutate(a,l+1,r);
			swap(&a[l],&a[i]);
		}
	}
}

int main()
{
	string w1;
	//getline(cin,w1);
	cin>>w1;
	int n = w1.size();
	Permutate(w1,0,n-1);
	n = ans.size();
	/*for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}*/
	//cout<<w1;
	for(auto i=ans.begin();i!=ans.end();i++)
	{
		cout<<*i<<" ";
	}

	return 0;
}