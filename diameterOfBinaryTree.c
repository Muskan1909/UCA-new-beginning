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
int max(int x,int y){
   return x>y?x:y;
}
int height(bt *root){
    if(root == NULL)
       return 0;
    else
       return 1+max(height(root->left),height(root->right));
}
int diameter(bt *root){
     if(root == NULL)
       return 0;
     int lheight = height(root->left);
     int rheight = height(root->right);

     int ldiameter = diameter(root->left);
     int rdiameter = diameter(root->right);

     return max(lheight+rheight+1,max(ldiameter,rdiameter));
}
int main(){
     bt *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     int dia = diameter(root);
     printf("%d",dia);
}
