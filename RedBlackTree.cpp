#include<bits/stdc++.h>
using namespace std;

enum Color {Red,Black};

struct Node
{
	int data;
	Node* left,*right,*parent;
	bool color;

	Node(int data)
	{
		this->data = data;
		left = right = parent = NULL;
		this->color = Red;
	}
};

class RBTree
{
	Node *root;
public:
	void LeftRotate(/*Node *&,*/Node *);
	void RightRotate(/*Node *&,*/Node *);
	void FixViolation(/*Node *&,*/Node *);
	void insert(int );
	RBTree()
	{
		root =NULL;
	}
	void LevelOrder();

};
Node *BSTInsert(Node *root,Node *temp)
{
	if(!root)
		return temp;
	if(temp->data < root->data)
	{
		root->left = BSTInsert(root->left,temp);
		root->left->parent = root;
	}
	else if(temp->data > root->data)
	{
		root->right = BSTInsert(root->right,temp);
		root->right->parent = root;
	}
	return root;
}
void LevelOrderHelper(Node *root)
{
	if(!root)
		return;
	queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		Node * temp = q.front();
		cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
		q.pop();
	}
	cout<<endl;
}
void RBTree::LevelOrder()
{
	LevelOrderHelper(root);
}

void RBTree::insert(int val)
{
	Node *temp = new Node(val);
	root = BSTInsert(root,temp);
	FixViolation(/*root,*/temp);
}

void RBTree::RightRotate(/*Node *&root,*/Node *pt)
{
	Node* temp = pt->left;

	pt->left = temp->right;

	if(pt->left)
		pt->left->parent = pt;

	temp->parent = pt->parent;

	if(!temp->parent)
		root = temp;
	else if(pt == pt->parent->left)
		pt->parent->left = temp;
	else
		pt->parent->right = temp;

	temp->right = pt;
	pt->parent = temp;

}

void RBTree::LeftRotate(/*Node *&root,*/Node *pt)
{
	Node *temp = pt->right;

	pt->right = temp->left;
	if(temp->left)
		temp->left->parent = pt;

	temp->parent = pt->parent;

	if(!temp->parent)
		root = temp;
	else if(pt == pt->parent->left)
		pt->parent->left = temp;
	else
		pt->parent->right = temp;

	temp->left = pt;
	pt->parent = temp;
}

void RBTree::FixViolation(/*Node *&root,*/Node *pt)
{
	Node *parent_pt = NULL;
	Node *GrandParent_pt = NULL;

	while(pt!=root && pt->color!=Black && pt->parent->color==Red)
	{
		parent_pt = pt->parent;
		GrandParent_pt= parent_pt->parent;
		if(parent_pt == GrandParent_pt->left)
		{
			Node *uncle_pt = GrandParent_pt->right;
			if(uncle_pt && uncle_pt->color == Red)
			{
				GrandParent_pt->color = Red;
				parent_pt->color = Black;
				uncle_pt->color = Black;
				pt = GrandParent_pt;
			}

			else
			{
				if(pt == parent_pt->right)
				{
					LeftRotate(/*root,*/parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;

				}

				RightRotate(/*root,*/GrandParent_pt);
				swap(parent_pt->color,GrandParent_pt->color);
				pt = parent_pt;
				//parent_pt = pt->parent;
			}
		}
		else
		{
			Node *uncle_pt = GrandParent_pt->left;
			if(uncle_pt && uncle_pt->color==Red)
			{
				GrandParent_pt->color = Red;
				parent_pt->color = Black;
				uncle_pt->color = Black;
				pt = GrandParent_pt;
			}
			else
			{
				if(pt == parent_pt->left)
				{
					RightRotate(/*root,*/parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

				LeftRotate(/*root,*/GrandParent_pt);
				swap(parent_pt->color , GrandParent_pt->color);
				pt = parent_pt;
			}
		}
	}
	root->color = Black;
}

int main()
{
	RBTree tree;
	int d;
	do
	{
		cin>>d;
		if(d==-1)
			continue;
		tree.insert(d);
		tree.LevelOrder();
	}while(d!=-1);

}