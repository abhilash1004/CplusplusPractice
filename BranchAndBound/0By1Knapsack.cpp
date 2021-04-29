#include<bits/stdc++.h>
using namespace std;

int Knapsack(float *w,float *p,int n,float c)
{

}
int main()
{
    float c;int n; //Capacity and No of Containers
    cin>>n>>c;
    float *w = new float[n];
    float *p = new float[n];
    for(int i=0;i<n;i++)
        cin>>w[i];
    for(int i=0;i<n;i++)
        cin>>p[i];
    cout<<Knapsack(w,p,n,c);
    return 0;
}
