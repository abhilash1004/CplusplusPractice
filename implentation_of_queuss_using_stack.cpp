#include<iostream>
#include<conio.h>
using namespace std;
const int m=100;
class stck
{
    int s[m],t;
public:
    stck()
    {
        t=-1;
    }
    void push(int n)
    {
        if(t==m-1)
        {
            cout<<"Overflow";
            return;
        }
        else
            s[++t]=n;
    }
    int pop()
    {
        if(t==-1)
        {
            cout<<"Overflow";
            return -9999;
        }
        return s[t--];
    }
    int top(){return t;}
};
class que
{
    stck s1,s2;
public:
    void addq(int n);
    int delq();
    void dispq();
};
void que::addq(int n)
{
    while(s1.top()!=-1)
    {
        s2.push(s1.pop());
    }
    s1.push(n);
    while(s2.top()!=-1)
    {
        s1.push(s2.pop());
    }
}
int que::delq()
{
    if(s1.top()==-1)
    {
        cout<<"Empty queue";
        return -9999;
    }
    return s1.pop();
}
int main()
{
    que q;
    int a;
    do
    {
        cout<<"Enter 1-add 2-pop 3-exit\n";
        cin>>a;
        switch(a)
        {
        case 1:
            cout<<"Enter number";
            int num;
            cin>>num;
            q.addq(num);
            break;
        case 2:
            cout<<q.delq();
        }
    }while(a!=3);
    return 0;
}
