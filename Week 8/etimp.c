//Expression Trees

#include "et.h"

int isOperator(char ch);
Node *pop(Node **stack,int *);
void push(Node **stack,int *,Node *t);

Node * createExpressionTree(char* a,int len)
{
    Node *tmp;
    Node *stack[100];
    int top=-1;
    int i=0;
    char ch;
    while(a[i]!='\0')
    {
        ch=a[i];
        tmp=(Node*)malloc(sizeof(Node));
        tmp->data=ch;
        tmp->right=tmp->left=NULL;
        if(isOperator(ch))
        {
                tmp->right=pop(stack,&top);
                tmp->left=pop(stack,&top);
                push(stack,&top,tmp);
        }
        else
        {
                push(stack,&top,tmp);
        }
        i++;
    }
    return (pop(stack,&top));
}


void inorder(Node *root)
{
 if(root!=NULL)
 {
         inorder(root->left);
         printf("%c",root->data); 
         inorder(root->right);
 }
}

void preorder(Node *root)
{
 if(root!=NULL)
 {
         printf("%c",root->data); 
         preorder(root->left);
         preorder(root->right);
 }  
}

void postorder(Node *root)
{
  if(root!=NULL)
 {
         postorder(root->left);
         postorder(root->right);
         printf("%c",root->data);
 } 
}

void freeTree(Node *root)
{
  free(root);
}

int isOperator(char ch)
{
        switch(ch)
        {
                case '+':;
                case '-':;
                case '*':;
                case '/':;
                case '$':return 1;
                default:return 0;
         }     
}


Node *pop(Node **stack,int *t)
{
        Node *tmp;
        tmp= stack[*t];
        --(*t);
        return tmp;
}

void push(Node **stack, int *t, Node *tmp)
{
        ++(*t);
        stack[*t]=tmp;
}