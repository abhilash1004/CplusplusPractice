#include<bits/stdc++.h>
using namespace std;


int FindStar(char **a,int n,int col)
{
    for(int i=0;i<3;i++)
        if(a[i][col]=='#')
        {
            cout<<"#";
            return col+1;
        }
    if(col+2>=n)
        return col+1;
    int in=0,sum=0;
    for(int i=0;i<3;i++)
        for(int j=col;j<col+3;j++)
        {
            in++;
            if(a[i][j]=='*')
                sum+=in;
        }
    //cout<<"Sum= "<<sum<<" ";
     //cout<<"Sum="<<sum<<":";
    switch(sum)
    {
    case 33:
        cout<<"A";
        return col+3;
    case 35:
        cout<<"I";
        return col+3;
    case 38:
        cout<<"U";
        return col+3;
    case 40:
        cout<<"O";
        return col+3;
    case 45:
        cout<<"E";
        return col+3;
    }

    return col+1;
}

void FindConstellation(char **a,int n)
{
    int i=0;
    while(i<=n)
    {
        //cout<<" "<<i<<" ";
        i=FindStar(a,n,i);
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    char **a = new char*[3];
    for(int i=0;i<3;i++)
        a[i]=new char[n];
   /* string values[3];
    for(int i=0;i<3;i++)
        cin>>values[i];*/
    for(int i=0;i<3;i++)
    {

        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    //cout<<a[0][0]<<"="<<('*'==a[0][0])<<endl;
    FindConstellation(a,n);
    return 0;
}
