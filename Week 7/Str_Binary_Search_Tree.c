#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {

    char srn[20];
    struct node *left, *right;
};

struct node* newNode(char srn[])
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    strcpy(temp->srn,srn);
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%s\n",root->srn);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, char srn[])
{
    if (node == NULL)

        return newNode(srn);
 

    if (strcmp(srn,node->srn)<0)

        node->left = insert(node->left, srn);

    else if (strcmp(srn,node->srn)>0)

        node->right = insert(node->right, srn);
    return node;
}


void search(struct node* root, char srn[],int *found)
{
if (root != NULL) 
    {
        if(strcmp(root->srn,srn)==0)
        {
                *found = 1;
        }
        inorder(root->left);
        inorder(root->right);
    }
        
}

int main()
{
        int num;
        char name[20];
        int f =0;
    struct node* root = NULL;
    printf("Enter Number of SRNs you want to insert\n");
    scanf("%d",&num);
    printf("Enter SRNs\n");
    scanf("%s",name);
    while(getchar()!='\n');
    root = insert(root, name);
    for(int i =0; i<num-1; i++)
    {
        printf("Enter SRN\n");
        scanf("%s",name);
        while(getchar()!='\n');
        insert(root, name);
    }
    inorder(root);
    printf("Enter SRN to search\n");
    scanf("%s",name);
    search(root,name,&f);
    if(f==1)
    {
        printf("SRN present\n");
    }
    else
    {
        printf("SRN not present\n");
    }
    return 0;
}
