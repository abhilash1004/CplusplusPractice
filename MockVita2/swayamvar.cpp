#include<bits/stdc++.h>

using namespace std;
int main()
{
    stack<char> brideStack;
    int n,i;
    cin>>n;
    char groom[n],bride[n];
    cin>>bride>>groom;
    //cout<<groom<<"\n"<<bride;
    char temp;
   /* for(i=0;i<n/2;i++)
    {
        temp =groom[i];
        groom[i] = groom[n-i-1];
        groom[n-i-1]=temp;
    }*/

    int ans = n;
    int cr=0,cm=0;
    for(i=0;i<n;i++)
    {
        if(groom[i]=='r')
           {
               cr++;
               //cout<<groom[i]<<endl;
           }
        else
            cm++;
    }
    int found =1;
    //cout<<cr<<" "<<cm<<endl;
    for(i=0;i<n;i++) //rmrm mmmr
    {
        switch(bride[i])
        {
        case 'r':
            if(cr!=0)
            {ans--;cr--;}
            else
                found=0;
            break;
        case 'm':
            if(cm!=0)
            {
                ans--;
                cm--;
            }
            else
                found=0;
            break;
        default:
            found=0;
            break;
        }
        if(found==0)
            break;
    }
    cout<<ans;
    return 0;
}
