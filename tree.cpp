#include<iostream>
using namespace std;

class node
{
    int info;
    node *lcl,*rcl;
public:
    node* createtree(node *);
    void disp(node *,int);
    void inorder(node *root);
    void preorder(node *);
    void postorder(node *);
    bool parent(node *,int);
    bool ancestor(node *,int);
    int no_of_leaf(node *,int);
    int depth(node *,int,int);
};
class stck
{
    node *s[100];
    int top;
public:
    node *pop();
    void push(node*);
    stck()
    {
        top=-1;
    }
    int isempty()
    {
        if (top==-1)return 1;
        else return 0;
    }
};
node *stck::pop()
{
    return s[top--];
}
void stck::push(node *r)
{
    s[++top]=r;
}
node *node::createtree(node *root)
{
    node *temp=new node;
    cout<<"Enter Number: ";
    cin>>temp->info;
    temp->lcl=temp->rcl=NULL;
    if(root==NULL)
        return temp;
    disp(root,0);
    cout<<"\nEnter Path:\n";
    char str[100];
    cin>>str;
    int i;
    node *prev,*cur=root;;
    for(i=0;str[i]!='\0';i++)
    {
        if(cur==NULL)
            break;
        prev=cur;
        if(str[i]=='l')
        {
            cur=cur->lcl;
        }
        else if(str[i]=='r')
            cur=cur->rcl;
    }
    if(str[i-1]=='l')
    {
        prev->lcl=temp;
        return root;
    }
    prev->rcl=temp;
    return root;
}
void node::disp(node *root,int level)
{
    int i;
    if(root==NULL)
        return;
    disp(root->rcl,level+1);
    for(i=0;i<level;i++)
        cout<<"\t";
    cout<<root->info<<endl;
    disp(root->lcl,level+1);
}
void node::inorder(node *root)
{
    node *r=root;
    stck s;
    while(1)
    {
        for(;r;r=r->lcl)
            s.push(r);
        r=s.pop();
        if(!r)
        {break;}
        cout<< r->info<<" ";
        r=r->rcl;
    }
}
void node::preorder(node *root)
{
    node *r=root;
    stck s;
    while(1)
    {
        for(;r;r=r->lcl)
        {   s.push(r);
            cout<<r->info<<" ";
        }
        r=s.pop();
        //cout<<r->info;
        if(!r)break;
        r=r->rcl;
    }
}
void node::postorder(node *root)
{
    node *r=root;
    stck s;
    while(1)
    {
        for(;r;r=r->lcl)
        {
            if(r->rcl)
                s.push(r->rcl);
            s.push(r);
        }
        r=s.pop();
        if(!r)break;
        if(r->rcl)
        {
            if(s.isempty()==0)
            {node *t=s.pop();
            if(t->info == (r->rcl)->info)
            {
                s.push(r);
                r=t;
            }
            else
            {
                s.push(t);
                cout<<r->info<<" ";
                r=NULL;
            }
            }
            else
                {cout<<r->info;
                 break;}
        }
        else
        {
            cout<<r->info<<" ";
            r=NULL;
        }
    }
}
bool node::parent(node *root,int n)
{
    bool b1,b2;
    if(!root)return false;
    if(root->info==n)return true;
    b1=parent(root->lcl,n);
    b2=parent(root->rcl,n);
    if(b1 || b2){cout<<root->info;}
    return false;
}
bool node::ancestor(node *root,int n)
{
    bool b1,b2;
    if(!root)return false;
    if(root->info==n)return true;
    b1=ancestor(root->lcl,n);
    b2=ancestor(root->rcl,n);
    if(b1 || b2){cout<<root->info<<" ";}
}
int node::no_of_leaf(node *r,int c)
{
    if(!r)return c;
    if(r->rcl==NULL && r->lcl==NULL)
        c++;
    c=no_of_leaf(r->lcl,c);
    c=no_of_leaf(r->rcl,c);
    return c;
}
int node::depth(node *r,int l,int a)
{
    //static int a=1;
    if(!r){return a;}
    int num1=depth(r->lcl,l+1,a);
    int num2=depth(r->rcl,l+1,a);
    int n=(num1>num2?num1:num2)>l?(num1>num2?num1:num2):l;
    if(a<n)
    {
        a=n;
    }
    return a;
}
int main()
{
    node *root=NULL,r;
    int a;
    do
    {
        cout<<"\n Enter 0-exit,1-Insert to tree,2-display,3-inorder traversal,4-preorder traversal,5-post_order traversal,6-find parent,7-ancestors,8-NO of leaf:,9-depth ";
        cin>>a;
        switch(a)
        {
        case 1:
            root=r.createtree(root);
            break;
        case 2:
            cout<<"The tree :\n";
            r.disp(root,0);
            break;
        case 3:
            r.inorder(root);
            break;
        case 4:
            r.preorder(root);
            break;
        case 5:
            r.postorder(root);
            break;
        case 6:
            int num;
            cout<<"Enter number to find its parent : ";
            cin>>num;
            r.parent(root,num);
            break;
        case 7:
            cout<<"Enter number to find its ancestors: ";
            cin>>num;
            r.ancestor(root,num);
            break;
        case 8:
            cout<<"Num Of Leafs: "<<r.no_of_leaf(root,0);
            break;
        case 9:
            cout<<"Depth Of tree: "<<r.depth(root,1,1);
            break;
        }
    }while(a!=0);
    return 0;
}
