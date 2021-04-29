#include<bits/stdc++.h>
using namespace std;
char colour[]={'A','B','C','D'};
int number[4]={0};
#define size1 5
#define size2 5
class box
{
public:
    int u,d,l,r;
    int max_cap;
    int cap;
    char col;
    box()
    {
        u=d=l=r=cap=0;
        col='z';
    }
};
box grid[size1][size2];
void spread(int p,int q,int player)
{
    int sides[][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int dir[4];
    dir[0]=grid[p][q].r;
    dir[1]=grid[p][q].l;
    dir[2]=grid[p][q].d;
    dir[3]=grid[p][q].u;
    int x,y;
    grid[p][q].cap=0;
    grid[p][q].col='z';
    number[player]--;
    for(int i=0;i<4;i++)
    {
        if(dir[i]==0)
            continue;
        x=p+sides[i][0];
        y=q+sides[i][1];
        grid[x][y].cap++;
        if(grid[x][y].col=='z' || grid[x][y].col!=colour[player])
        {
            number[player]++;
            if(grid[x][y].col!='z')
            {
                number[grid[x][y].col-65]--;
            }
        }
        grid[x][y].col=colour[player];
        if(grid[x][y].cap==grid[x][y].max_cap)
        {
            spread(x,y,player);
        }
    }
}
void add(int p,int q,int player)
{
    if(grid[p][q].col=='z')
        number[player]++;
    grid[p][q].cap++;
    grid[p][q].col=colour[player];
    if(grid[p][q].cap==grid[p][q].max_cap)
        spread(p,q,player);
}
void create_grid()
{
    int i,j,x,y;
    int sides[][2]={{0,1},{0,-1},{1,0},{-1,0}};
    for(i=0;i<size1;i++)
    {
        for(j=0;j<size2;j++)
        {
            x=i+0;y=j+1;
            if(x>=0 && x<size1 && y>=0 && y<size2)
                grid[i][j].r=1;

            x=i+0;y=j-1;
            if(x>=0 && x<size1 && y>=0 && y<size2)
                grid[i][j].l=1;

            x=i+1;y=j+0;
            if(x>=0 && x<size1 && y>=0 && y<size2)
                grid[i][j].d=1;

            x=i-1;y=j+0;
            if(x>=0 && x<size1 && y>=0 && y<size2)
                grid[i][j].u=1;

            grid[i][j].max_cap=grid[i][j].u+grid[i][j].d+grid[i][j].l+grid[i][j].r;
        }
    }
}
void disp_board()
{
    int i,j;
    for(i=0;i<size1;i++)
    {
        for(j=0;j<size2;j++)
        {
            cout<<grid[i][j].cap<<" ";
            if(grid[i][j].col!='z')
                cout<<grid[i][j].col;
            cout<<"\t";
        }
        cout<<endl;
    }
}
int game_not_completed(int n,int a[])
{
    int counti=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=1)
            continue;
        if(number[i]>0)
            counti++;
        if(number[i]==0)
        {
            a[i]=0;
            cout<<"\nPlayer Eliminated "<<colour[i]<<"\n\n";
        }
    }
    if(counti>1)
        return 1;
    return 0;
}
int main()
{
    int n,p,q,time=0;
    cout<<"Enter Number of players(Max 4 & Min 2): ";
    cin>>n;
    cout<<"Starting Chain Reaction......\n...\n..\n.\n";
    create_grid();
    int alive[n];
    for(int i=0;i<n;i++)
        alive[i]=1;
    do
    {
       for(int i=0;i<n;i++)
       {
           if(alive[i]!=1)
                continue;
           cout<<"Move Of Player "<<colour[i]<<" "<<endl;
           cout<<"Enter p and q: ";
           cin>>p>>q;
           if(p<0 || p>=size1 || q<0 || q>=size2)
           {
               cout<<"Wrong p and q\n Invalid Move\n Enter Again:\n";
               i--;
               continue;
           }
           if(!(grid[p][q].col=='z' || grid[p][q].col==colour[i]))
           {
               i--;
               cout<<"invalid move\n";
               continue;
           }
           add(p,q,i);
           disp_board();
           if(time>=n-1)
                if(!game_not_completed(n,alive))
                    break;
            time++;
       }
    }while(game_not_completed(n,alive));
    for(int i=0;i<n;i++)
        if(number[i]!=0)
            {cout<<"\n Winner Player "<<colour[i]<<endl;break;}
    cout<<"\nThank You For Playing";
    return 0;
}
