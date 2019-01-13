#include <stdio.h>
#include <stdlib.h>
typedef struct btree {
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
int height(bt *root){
    if(root == NULL)
       return 0;
    else{
       int lDepth  = height(root->left);
       int rDepth = height(root->right);
       if(lDepth > rDepth)
          return (lDepth+1);
       else
          return (rDepth+1);
    }
}
int main(){
    bt *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    int h = height(root);
    printf("height of tree is %d",h);
}
