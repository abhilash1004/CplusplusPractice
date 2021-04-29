#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
//#include<sys/wait.h>
#include<stdlib.h>
int main()
{
 int status;
 pid_t pid,ppid;
 pid_t p=fork();
 if(p==0)
 {
  printf("I am Child process\n");
  pid=getpid();
  ppid=getppid();
  printf("PId = %d and PPId = %d \n",pid,ppid);
 }
 else
 {
  printf("I am Parent process\n");
  pid=getpid();
  ppid=getppid();
  printf("PId = %d and PPId = %d \n",pid,ppid);
 }
 return 0;
}
