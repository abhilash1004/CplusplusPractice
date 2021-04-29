#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,i,j,ans;
    cin>>T;
    int num[T];
    for(i=0;i<T;i++)
    {
        cin>>num[i];
    }
    for(i=0;i<T;i++)
    {
        j=0;
        while(1)
        {
            ans=num[i]/pow(2,j);
            if(ans==0)
            {
                cout<<j<<endl;
                break;
            }
            j++;
        }
    }

    return 0;
}

