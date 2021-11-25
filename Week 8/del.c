//Delete a node from BST and reconstruct the tree

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
int info;
struct node *left, *right;
}NODE;
// Create a node
NODE *newNode(int item) {
NODE *temp = (NODE *)malloc(sizeof(NODE));
temp->info = item;
temp->left = temp->right = NULL;
return temp;
}
void inorder(NODE *root) {
if (root != NULL) {
inorder(root->left);
printf("%d -> ", root->info);
inorder(root->right);
}
}
NODE *insert(NODE *node, int key) {
if (node == NULL) return newNode(key);
if (key < node->info)
node->left = insert(node->left, key);
else
node->right = insert(node->right, key);
