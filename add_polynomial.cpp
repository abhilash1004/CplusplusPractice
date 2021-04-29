#include<iostream>
using namespace std;
class poly
{
    int exp;
    int coef;
    poly* next;
public:
    poly* read_poly(poly*);
    poly* add_poly(poly*,poly*);
    poly* attach(poly*,int,int);
    void disp_poly(poly*);
};
poly* poly::read_poly(poly* start)
{
    while(1)
    {
        int c,e;
        cout<<"enter coeficient and power and to exit enter -999 as coefficient or power";
        cin>>c>>e;
        if(c==-999)
        {
            return start;
        }
        start=attach(start,c,e);
    }
}
poly* poly::attach(poly* start,int c,int e)
{
    poly* temp=new poly;
    temp->coef=c;
    temp->exp=e;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        return start;
    }
    poly *cur=start;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=temp;
    return start;
}
void poly::disp_poly(poly* start)
{
    poly *cur=start;
    while (cur!=NULL)
    {
        cout<<cur->coef<<"x^"<<cur->exp<<"+";
        cur=cur->next;

    }
    cout<<"0";
}
poly* poly::add_poly(poly* p1,poly* p2)
{
    poly *p3=NULL;
    while(p1!=NULL && p2!=NULL)
    {
        if((p1->exp)==(p2->exp))
        {
            int c=p1->coef+p2->coef;
            p3=attach(p3,c,p1->exp);
            p1=p1->next;
            p2=p2->next;
        }
        else if((p1->exp)>(p2->exp))
        {
            p3=attach(p3,p1->coef,p1->exp);
            p1=p1->next;
        }
        else
        {
            p3=attach(p3,p2->coef,p2->exp);
            p2=p2->next;
        }
    }
    return p3;
}
int main()
{
    poly a;
    poly *p1=NULL,*p2=NULL,*ans;
    cout<<"READING POLYNOMIAL\n";
    p1=a.read_poly(p1);
    cout<<"READING POLYNOMIAL 2";
    p2=a.read_poly(p2);
    ans=a.add_poly(p1,p2);
    cout<<"PLOYNOMIAL AFTER ADDITION\n";
    a.disp_poly(ans);
    return 0;
}
