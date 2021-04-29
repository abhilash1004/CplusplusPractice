#include<bits/stdc++.h>
using namespace std;
#define n 8
int check_safe(int a[n][n],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
        if(a[row][i])
            return 0;
    for(i=row,j=col;i>=0&&j>=0;i--,j--)
        if(a[i][j])
            return 0;
    for(i=row,j=col;i<n&&j>=0;i++,j--)
        if(a[i][j])
            return 0;
    return 1;
}
int place_queens(int a[n][n],int col=0)
{
    if(col>=n)
        return 1;
    for(int i=0;i<n;i++)
    {
        if(check_safe(a,i,col))
            a[i][col]=1;
        else
            continue;
        if(place_queens(a,col+1))
            return 1;
        a[i][col]=0;
    }
    return 0;
}
int main()
{
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=0;
    if(!place_queens(a))
        cout<<"solution doesnt exist for "<<n<<" queens/n";
    else
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
