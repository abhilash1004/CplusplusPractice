#include<stdio.h>
struct table
{
    int num; // process Number
    int at;  // Arrival Time
    int bt;  // Burst Time
    int priority; //Priority of Process
    int wt;  //waiting time
    int tt;   //turnaround time
};

void swap(struct table *a,struct table *b)
{
    struct table c=*a;
    *a=*b;
    *b=c;
}
void print_solution(struct table t[],int n)
{
    int i=0,wt=0,tt=0;
    printf("Process\t\tWaiting_time\t\tTurn_around_Time\n");
    while(i<n)
    {
        for(int j=0;j<n;j++)
        {
            if(t[j].num==i)
            {
                printf("P%d\t\t%d\t\t\t%d\n",t[j].num,t[j].wt,t[j].tt);
                wt+=t[j].wt;
                tt+=t[j].tt;
                break;
            }
        }
        i++;
    }
    printf("Average waiting time = %f\nAverage Turn Around Time = %f\n",wt/(n*1.0),tt/(n*1.0));
}
void arrival_time_sort(struct table h[],int n ,struct table t[])
{
    for(int i=0;i<n;i++)
    {
        t[i]=h[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(t[j].at > t[j+1].at)
                swap(&t[j],&t[j+1]);
        }
    }
}
int process_input(struct table t[],int n)
{
    printf("Enter 1 if priority is given and 0 if no priority: ");
    int key;
    scanf("%d",&key);
    if(key!=0 && key !=1)
    {
        printf("wrong key entered \n enter again");
         key=process_input(t,n);
         return key;
    }
    for(int i=0;i<n;i++)
    {
        printf("\n\nEnter Details of Process %d:\n",i);
        printf("Enter Arrival Time");
        scanf("%d",&t[i].at);
        printf("Enter Burst Time");
        scanf("%d",&t[i].bt);
        if(key)
        {
            printf("Enter priority");
            scanf("%d",&t[i].priority);
        }
        else
        {
            t[i].priority=0;
        }
        //t[i].at++;
        t[i].num=i;
    }
    return key;
}
void fcfs(struct table h[],int n)
{
    int time=0;
    struct table t[n];
    arrival_time_sort(h,n,t);
   // int p_at[n]={0}; //  p_at= process arrival time
    int index=0;
    t[0].wt=0;
    while(1)
    {
        if(time>=t[index].at)
        {
            t[index].bt--;
            if(t[index].bt==0)
            {
                t[index].tt=time-t[index].at+1;
                index++;
                if(index==n)
                    break;
                else
                {
                    t[index].wt=time-t[index].at+1;
                }
            }
        }
        time++;
    }
    printf("FCFS Solution:\n");
    print_solution(t,n);
}

int main()
{
    int n;
    printf("Enter no of  process: ");
    scanf("%d",&n);
    struct table T[n];
    int p=process_input(T,n);
    fcfs(T,n);
    return 0;
}
