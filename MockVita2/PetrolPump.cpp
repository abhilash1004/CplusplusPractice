#include <stdio.h>
int main(void) {
    int n=0, x, i, j, s = 0;
    int a[51];
    while((scanf("%d",&x))!=-1)
    {
        a[n++]=x;
        s += x;
    }
    int d[n+1][s+1];
    for(i=0 ; i<=n ; i++)
        d[i][0] = 1;
    for(i=1 ; i<=s ; i++)
        d[0][i] = 0;

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=s ; j++)
        {
            d[i][j] = d[i-1][j];
            if(a[i-1] <= j)
                d[i][j] = d[i][j] | d[i-1][j - a[i-1]];
        }
    int an = s;
    for(i=s/2+1 ; i<s ; ++i)
        if(d[n][i])
        {
            an = i;
            break;
        }
        
   /* for(i=0;i<=n;i++)
    {
        for(j=0;j<=s;j++)
        {
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }*/
    printf("%d",an);
 return 0;
}
