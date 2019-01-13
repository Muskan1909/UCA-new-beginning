#include <stdio.h>
#include <stdlib.h>
typedef struct btree{
   int data;
   struct btree *left;
   struct btree *right;
}bt;
bt* newNode(int d){
   bt *b = (bt*)malloc(sizeof(bt));
   b->data = d;
   b->left = NULL;
   b->right = NULL;
   return b;
}
void preorder(bt *root){
   if(root == NULL)
     return;
   printf("%d ",root->data);
   preorder(root->left);
   preorder(root->right);
}
void inorder(bt *root){
   if(root == NULL)
     return;
   inorder(root->left);
   printf("%d ",root->data);
   inorder(root->right);
}
void postorder(bt *root){
    if(root == NULL)
      return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int main(){
   bt *root = newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   printf("preorder is ");
   preorder(root);
   printf("\ninorder is ");
   inorder(root);
   printf("\npostorder is ");
   postorder(root);
}
