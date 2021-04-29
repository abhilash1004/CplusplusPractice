#include<bits/stdc++.h>
using namespace std;

void ConvertToPalindrome(char *str)
{
    int j=strlen(str)-1;
    int i=0;
    string ans="";
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            ans = ans + str[i];
            i++;
        }
        else
        {
            i++;
            j--;
        }
    }
    //cout<<ans<<endl;
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}


int main()
{
    int n;
    cin>>n;
    char s[n];
    cin>>s;
    ConvertToPalindrome(s);
}
