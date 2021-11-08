#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}Node;

int count(Node *t);
void preorder(Node *t);
void inorder(Node *t);
void postorder(Node *t);
Node* insert(Node *root, int x);
void iter_insert(Node **t, int x);

int main()
{
	Node *root;
	int choice,num,k;
	root=NULL;
	while(1)
	{
		printf("\n\n1: Insert\n2: Preorder\n3: Inorder\n4: Postorder\n5: Insert(iteration)\n6: Node Count\n7: Exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the value to insert\n");
				scanf("%d",&num);
				root=insert(root,num);
				break;

			case 2: preorder(root); break;

			case 3: inorder(root); break;

			case 4: postorder(root); break;

			case 5: printf("enter the value to insert:\n");
                    scanf("%d",&num);
                    iter_insert(&root,num);
                    break;

			case 6: k=count(root);
                    printf("no of nodes - %d\n", k);
                    break; 
            
            case 7: exit(0);
		}
	}
    return 0;
}

int count(Node *t)
{
		if(t==NULL)
		    return 0;
		int l = count(t->left);
		int r = count(t->right);
		return (l+r+1);
}

void preorder(Node *t)
{
	if(t!=NULL)
	{
		printf("%d - ",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

void inorder(Node *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d - ",t->data);
		inorder(t->right);
	}
}

void postorder(Node *t)
{
	if(t!=NULL)
	{
		
		postorder(t->left);
		postorder(t->right);
		printf("%d - ",t->data);
	}
}

void iter_insert(Node **t, int x)
{
	Node *temp,*prev,*pres;
    pres=*t;
    prev=NULL;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=x;
    temp->right = temp->left = NULL;
    if(pres==NULL)
    {
        *t=temp;
        return;
    }
    while(pres!=NULL)
    {
        prev=pres;
        if(x>pres->data)
            pres=pres->right;
        else
            pres=pres->left;
    }
    if(prev->data>x)
        prev->left=temp;
    else
        prev->right=temp;
}

Node* insert(Node *root, int x)
{
    Node *tmp;
	tmp=(Node*)malloc(sizeof(Node));
	tmp->data=x;
    tmp->right = tmp->left = NULL;
    if(root==NULL)
    {
        root=tmp;
        return tmp;
    }
    else
    {
        if(x>root->data)
            root->right = insert(root->right,x);
        else
            root->left = insert(root->left,x);
        return root;
    }
}