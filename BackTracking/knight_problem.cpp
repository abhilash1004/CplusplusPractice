
/*////////////*********
 *Dont run the code ********************************************/
#include<bits/stdc++.h>
using namespace std;
#define n 8
int make_step(int a[n][n],int r,int c,int step)
{
    if(step>=n*n)
        return 1;
    int i,j,k;;
    int moving[][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    for(k=0;k<n;k++)
    {
        i=r+moving[k][0];
        j=c+moving[k][1];
        if(i<0||i>=n||j<0||j>=n)
            continue;
        if(a[i][j]==-1)
        {
            a[i][j]=step;
            cout<<step<< " ";
            if(make_step(a,i,j,step++))
                return 1;
            //step--;
            a[i][j]=-1;
        }
       // cout<<i<<" "<<j<<endl;
    }
    return 0;
}
void place_moves()
{
    int step=1,i,j,a[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=-1;
    cout<<"Enter starting move i&j values: ";
    cin>>i>>j;
    a[i][j]=0;
    if(!make_step(a,i,j,step))
      {
          cout<<"Not possible\n";
          return;
      }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
}
int main()
{
    place_moves();
    return 0;
}
