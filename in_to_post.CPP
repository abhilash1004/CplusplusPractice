#include<iostream>
#include<conio.h>
using namespace std;
const int m=100;
class stck
{
    char s[m];
    int top;
public:
    void push(char );
    char pop();
    stck()
    {
        top=-1;
    }
    isempty()
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }
};
void stck::push(char ch)
{
    if(top==m-1)
    {
        cout<<"overload";
        return;
    }
    s[++top]=ch;
}
char stck::pop()
{
    if(top==-1)
    {
        cout<<"Underflow";
        return '@';
    }
    return s[top--];
}
int prec(char ch)
{
    switch(ch)
    {
        case '^':return 3;
        case '*':
        case '/':return 2;
        case '+':
        case '-':return 1;
        default:return -1;
    }
}
void po_conv(char in[],char res[],stck s)
{
    char e1,e2;
    int k=0;
    for(int i=0;in[i]!='\0';i++)
    {
        e1=in[i];
        switch(e1)
        {
            case '(':
                   s.push(e1);
                   break;
            case ')':
                e2=s.pop();
                while(e2!='(')
                {
                    res[k++]=e2;
                    e2=s.pop();
                }
                break;
            case '/':
            case '*':
            case '-':
            case '+':
            case '^':
                if(!s.isempty())
                {
                    e2=s.pop();
                    while(prec(e1)<=prec(e2))
                    {
                        res[k++]=e2;
                        if(!s.isempty())
                        {e2=s.pop();}
                        else
                            break;
                    }
                    if(prec(e1)>prec(e2))
                    s.push(e2);
                    s.push(e1);
                }
                else
                    s.push(e1);
                break;
            default:
                res[k++]=e1;
        }
    }
    while(!s.isempty())
    {
        res[k++]=s.pop();
    }
    res[k]='\0';
    cout<<"The postfix Expression:\n"<<res;
}
int main()
{
    stck s;
    char in[m],res[m];
    cout<<"Enter expression";
    cin>>in;
    po_conv(in,res,s);
    return 0;
}
