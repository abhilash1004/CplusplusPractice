#include<bits/stdc++.h>
using namespace std;
#define n 9
void print_solution(int a[][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        cout<<">";
        for(j=0;j<n;j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
}
int find_empty_box(int a[][n],int &r,int &c)
{
    for(r=0;r<n;r++)
        for(c=0;c<n;c++)
            if(!a[r][c])
                return 1;
    return 0;
}
int can_fit_row(int a[][n],int r,int v)
{
    for(int i=0;i<n;i++)
        if(a[r][i]==v)
            return 0;
    return 1;
}
int can_fit_col(int a[][n],int c,int v)
{
    for(int i=0;i<n;i++)
        if(a[i][c]==v)
            return 0;
    return 1;
}
int can_fit_box(int a[][n],int r,int c,int v)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i+r][j+c]==v)
                return 0;
        }
    }
    return 1;
}
int solve_sudoko(int a[][n])
{
    int r,c;
    if(!find_empty_box(a,r,c))
        return 1;
    for(int i=1;i<=n;i++)
    {
        if(can_fit_row(a,r,i)&&can_fit_col(a,c,i)&&can_fit_box(a,r-r%3,c-c%3,i))
        {
            a[r][c]=i;
            if(solve_sudoko(a))
                return 1;
            a[r][c]=0;
        }
    }
    return 0;
}

int main()
{
    int a[n][n];
    cout<<"Enter Sudoko puzzle values:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    if(!solve_sudoko(a))
        cout<<"Solution doesnt exist\n";
    else
        print_solution(a);
    return 0;
}
