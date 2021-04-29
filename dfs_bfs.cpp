#include<iostream>
using namespace std;
void dfs(int a[20][20],int n,int source)
{ int visited[10],u,v,i;
 for(i=1;i<=n;i++) visited[i]=0;
 int S[20],top=-1;
 S[++top]=source;
 visited[source]=1;
 while(top>=0)
 { u=S[top--];
 for(v=1;v<=n;v++)
 { if(a[u][v]==1 && visited[v]==0)
 {
 visited[v]=1; S[++top]=v;
 }
 }
 cout<<u<<" ";
 }
}
 void bfs(int a[20][20],int n,int source)
{
int visited[10],u,v,i;
 for(i=1;i<=n;i++) visited[i]=0;
 int Q[20],f=-1,r=-1;
 Q[++r]=source; visited[source]=1;
 while(f<r)
 {
 u=Q[++f];
 for(v=1;v<=n;v++)
 { if(a[u][v]==1 && visited[v]==0)
 {
 visited[v]=1;
 Q[++r]=v;
 }
 }
 cout<<u<<" ";
 }
}

//#include<iostream.h>
void bfs(int a[20][20],int n,int source);
void dfs(int a[20][20],int n,int source);
int main()
{
 int a[20][20],source, n,i,j;
 cout<<"Enter the no of vertices: "; cin>>n;
 cout<<"Enter the adjacency matrix: ";
 for(i=1;i<=n;i++) for(j=1;j<=n;j++) cin>>a[i][j];
 cout<<"Enter the source: ";
 cin>>source;
 cout<<"\n BFS: "; bfs(a,n,source);
 cout<<"\n DFS: "; dfs(a,n,source);
 return 1;
}
