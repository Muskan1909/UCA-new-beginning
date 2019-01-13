#include <stdio.h>
#include <stdlib.h>
typedef struct btree{
   int data;
   struct btree *left;
   struct btree *right;
}bt;
bt* newNode(int d){
   bt *root = (bt*)malloc(sizeof(bt));
   root->data = d;
   root->left = NULL;
   root->right = NULL;
   return root;
}

void inorder(bt *root){
    if(root == NULL)
        return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void mirror(bt *root){
   if(root == NULL)
      return ;
   bt *temp;
   mirror(root->left);
   mirror(root->right);
   temp = root->left;
   root->left = root->right;
   root->right = temp;
}

int main(){
     bt *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     inorder(root);
     mirror(root);
     inorder(root);
}
