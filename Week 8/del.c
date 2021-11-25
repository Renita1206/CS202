//Delete a node from BST and reconstruct the tree

#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
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
return node;
}
NODE *min(NODE *node) {
NODE *current = node;
while (current && current->left != NULL)
current = current->left;
return current;
}
NODE *deleteNode(NODE *root, int key) {
if (root == NULL) return root;
if (key < root->info)
root->left = deleteNode(root->left, key);
else if (key > root->info)
root->right = deleteNode(root->right, key);
else {
if (root->left == NULL) {
NODE *temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
NODE *temp = root->left;
free(root);
return temp;
}
NODE *temp = min(root->right);
root->info = temp->info;
root->right = deleteNode(root->right, temp->info);
}
return root;
}
int main() {
NODE *root = NULL;
root = insert(root, 13);
root = insert(root, 3);
root = insert(root, 4);
root = insert(root, 12);
root = insert(root, 14);
root = insert(root, 10);
root = insert(root, 5);
root = insert(root, 1);
root = insert(root, 8);
root = insert(root, 2);
root = insert(root, 7);
root = insert(root, 9);
root = insert(root, 11);
root = insert(root, 6);
root = insert(root, 18);
printf("Inorder traversal: ");
inorder(root);
printf("\nAfter deleting 10 (subtree level node)\n");
root = deleteNode(root, 10);
printf("Inorder traversal: ");
inorder(root);
printf("\nAfter deleting 13 (root node)\n");
root = deleteNode(root, 13);
printf("Inorder traversal: ");
inorder(root);
printf("\nAfter deleting 2 (leaf node)\n");
root = deleteNode(root, 2);
printf("Inorder traversal: ");
inorder(root);
}