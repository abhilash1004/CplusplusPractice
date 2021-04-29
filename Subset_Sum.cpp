#include<bits/stdc++.h>
using namespace std;

/*int findSubSum(int a[],int n,int pos,int flag[],int *ans)
{
    int s=0;

}*/

int findSum(int arr[],int n)
{
    int incl = arr[0];
  int excl = 0;
  int excl_new;
  int i;

  for (i = 1; i < n; i++)
  {
     /* current max excluding i */
     excl_new = (incl > excl)? incl: excl;

     /* current max including i */
     incl = excl + arr[i];
     excl = excl_new;
  }

   /* return max of incl and excl */
   return ((incl > excl)? incl : excl);
}



int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<findSum(a,n);
    return 0;

}
