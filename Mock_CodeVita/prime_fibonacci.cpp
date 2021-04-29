#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
/*void reverseStr(string& str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
string to_string(int a)
{
    int num=a,i=0;
    string str;
    while(num!=0)
    {
        int rem=num/10;
        num=num/10;
        str.push_back((char)(num+48));
    }
    reverseStr(str);
    return str;
}
string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i=n1-1; i>=0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining digits of str2[]
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}
string fib(int a,int b,int n)
{
    if(n==0)
    {
        string stri = to_string(a);
        return stri;
    }
    if(n==1)
    {
        string str2 = to_string(b);
        return str2;
    }
    //if(n==1)
        //return to_string(b);
    else
    {
        return findSum(fib(a,b,n-1),fib(a,b,n-2));
    }

}*/
int fib(int a,int b,int n)
{
    if(n==0)
    {
        //string stri = to_string(a);
        return a;
    }
    if(n==1)
    {
       // string str2 = to_string(b);
        //return str2;
        return b;
    }
    //if(n==1)
        //return to_string(b);
    else
    {
        return fib(a,b,n-1)+fib(a,b,n-2);
    }

}
int maxi(int a,int b)
{
    return a>b?a:b;
}
int mini(int a,int b)
{
    return a<b?a:b;
}
int number(int a,int b)
{
    if(b/10==0)
    {
        return a*10+b;
    }
    else
        return a*100+b;
}
int main()
{
    int n1,n2,c1=0,i,j,c2=0,k,ind=0,m1=150000,m2=0;
    cin>>n1>>n2;
    int p1[n2-n1];
    for(i=n1;i<n2;i++)
    {
        if(i==1 || i==0)
            continue;
        int f=1;
        for(j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                f=0;
                break;
            }
        }
        if(f==1)
            p1[c1++]=i;
    }
    int com[c1*(c1-1)];
   // cout<<c1<<endl;
    for(i=0;i<c1;i++)
    {
        for(j=0;j<c1;j++)
        {
            if(j==i)
                continue;
            com[ind++]=number(p1[i],p1[j]);
        }
    }
   /* cout<<ind<<endl;*/
   /* for(i=0;i<ind;i++)
    {
        cout<<com[i]<<" ";
    }
    cout<<endl;*/
    int p2[100];
    for(i=0;i<ind;i++)
    {
        if(com[i]==1 || com[i]==0)
            continue;
        int f=1;
        for(j=2;j*j<=com[i];j++)
        {
            if(com[i]%j==0)
            {
                f=0;
                break;
            }
        }
        if(f==1)
          {
              p2[c2++]=com[i];
              m1=mini(m1,com[i]);
              m2=maxi(m2,com[i]);
          }
    }
  /*  cout<<"\n\n\n";
    for(i=0;i<c2;i++)
    {
        cout<<p2[i]<<" ";
    }*/
    //cout<<endl<<endl;
    //cout<<"\n"<<m1<<endl<<m2<<endl<<c2<<endl;
    cout<<fib(m1,m2,c2-1)<<endl;
    //int mini=p2[0],maxi
    return 0;
}
