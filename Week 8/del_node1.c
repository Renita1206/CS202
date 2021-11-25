// Delete a node from BST and reconstruct the tree

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}Node;

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

void inorder(Node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("%d\t",t->data);
        inorder(t->right);
    }
}

Node* deleteNode(Node *t, int n)
{
    Node *tmp=t;
    if(t==NULL)
        return t;
    if(n<t->data)
        t->left=deleteNode(t->left,n);
    else if(n>t->data)
        t->right=deleteNode(t->right,n);
    else
    {
        if(t->left == NULL)
        {
            Node *tmp=t->right;
            free(t);
            return tmp;
        }
        else if(t->right == NULL)
        {
            Node *tmp=t->left;
            free(t);
            return tmp;
        }
        while(tmp && tmp->left!=NULL)
            tmp=tmp->left;
        t->data=tmp->data;
        t->right=deleteNode(t->right,t->data);
    }
    return t;
}

int main()
{
    Node *root;
    int choice, num,k;
    root=NULL;
    while(1)
    {
        printf("\n\n1: Insert\n2: Delete\n3 Inorder Display\n4: Exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the value to insert\n");
				    scanf("%d",&num);
				    root=insert(root,num);
				    break;

			case 2: printf("enter the value to insert\n");
				    scanf("%d",&num);
                    root = deleteNode(root, num);

			case 3: inorder(root);
                    break; 
            
            case 4: exit(0);
		}
    }
    return 0;
}

//Doesn't delete root node properly