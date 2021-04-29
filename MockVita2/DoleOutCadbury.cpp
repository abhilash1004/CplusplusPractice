#include<bits/stdc++.h>
using namespace std;
int HowManyStudents(int x,int y)
{
    int c=0;
    while(x!=0 && y!=0)
    {
        //int p,q;
        if(x>y)
        {
            c++;
            //p=x*y;q=y*y;
            x=x-y;
            //y=(p-q)/y;

        }
        else
        {
            c++;
            y=y-x;
            //x--;
        }
        //cout<<x<<" "<<y<<endl;
    }
    return c;
}
int main()
{
    int p,q,r,s;
    cin>>p>>q>>r>>s;
    int i,j,students=0;
    for(i=p;i<=q;i++)
    {
        for(j=r;j<=s;j++)
        {
            students+=HowManyStudents(i,j);
        }
    }
    cout<<students;
    return 0;
}
