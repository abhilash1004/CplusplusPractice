#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	node* left,*right;
	int data,height;

	node()
	{
		height = 1;
		left = right = NULL;
	}

	node * insert(node * root,int data);
	void  inorder(node * root);
	void preorder(node *root);
	int getHeight(node *root);
	int getBalance(node *root);
	node *rightRotate(node *root);
	node *leftRotate(node *root);
	node *deleteNode(node *root,int data);
	int minvaluenode(node *root);
};
int node::getHeight(node *root)
{
	if(root==NULL)
		return 0;
	return root->height;
}
int node::getBalance(node *root)
{
	if(!root)
		return 0;
	return getHeight(root->left) - getHeight(root->right);
}

node *node::rightRotate(node *root)
{
	node *temp = root->left;
	node *temp2 = temp->right;
	temp->right = root;
	root->left = temp2;
	root->height = 1+max(getHeight(root->left),getHeight(root->right));
	temp->height = 1+max(getHeight(temp->left),getHeight(temp->right));
	return temp;
}

node *node::leftRotate(node *root)
{
	node *temp = root->right;
	node *temp2 = temp->left;
	temp->left = root;
	root->right = temp2;
	root->height = 1+max(getHeight(root->left),getHeight(root->right));
	temp->height = 1+max(getHeight(temp->left),getHeight(temp->right));
	return temp;
}

int node::minvaluenode(node *root)
{
	while(root->left)
		root = root->left;
	return root->data;
}

node* node::insert(node *root,int data)
{
	if(root == NULL)
	{
		node *temp = new node();
		temp->data = data;
		return temp;
	}
	if(data < root->data)
	{
		root->left = insert(root->left,data);
	}
	else if(data > root->data)
	{
		root->right = insert(root->right,data);
	}
	else
	{
		return root;
	}
	root->height = 1+ max(getHeight(root->left),getHeight(root->right));

	int bal = getBalance(root);

	if(bal > 1)
	{
		if(data < root->left->data)
			return rightRotate(root);
		else
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	else if(bal < -1)
	{
		if(data > root->right->data)
			return leftRotate(root);
		else
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}

void node::inorder(node *root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void node::preorder(node *root)
{
	if(!root)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


node *node::deleteNode(node *root,int data)
{
	if(!root)
	{
		return root;
	}
	if(data < root->data)
	{
		root->left = deleteNode(root->left,data);
	}
	else if(data > root->data)
	{
		root->right = deleteNode(root->right,data);
	}
	else
	{
		if(root->right==NULL || root->left==NULL)
		{
			node *temp = root->right? root->right:root->left;
			if(!temp)
			{
				temp = root;
				root = NULL;
				return root;
			}
			else
			{
				root->data = temp->data;
				if(root->left)
					root->left = NULL;
				else
					root->right = NULL;
				//*root = *temp;
			}
			free(temp);
		}
		else
		{
			int tempdata = minvaluenode(root->right); 
			root->data = tempdata;
			root->right = deleteNode(root->right,tempdata);
		}
	}
	root->height = 1+ max(getHeight(root->left),getHeight(root->right));

	int bal = getBalance(root);

	if(bal > 1)
	{
		if(getBalance(root->left) >= 0)
			return rightRotate(root); //Left Left case
		else
		{
			root->left = leftRotate(root->left);
			return rightRotate(root); //left right case
		}
	}
	else if(bal < -1)
	{
		if(getBalance(root->right) <= 0)
			return leftRotate(root);   //Right Right case
		else
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);  //Right Left case
		}
	}

	/*if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
    
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  

    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);    

    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  */
  
	return root;

}

int main()
{
	int d=0;
	node *tree = NULL;
	node t;
	while(d!=-1)
	{
		cin>>d;
		if(d==-1)
			continue;
		tree = t.insert(tree,d);
		t.preorder(tree);
		cout<<endl;
	}
	d = 0;
	while(d!=-1)
	{
		cin>>d;
		if(d==-1)
			continue;
		tree = t.deleteNode(tree,d);
		t.preorder(tree);
		cout<<endl;
	}

	return 0;
}