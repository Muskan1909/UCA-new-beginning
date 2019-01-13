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

void printArray(int path[],int n){
    int i;
    for(i=0;i<n;i++){
       printf("%d->",path[i]);
    }
    printf("\n");
}

void printPathRec(bt *root,int path[],int pathLen){
   if(root == NULL)
     return ;
   path[pathLen] = root->data;
   pathLen++;

   if(root->left == NULL && root->right == NULL)
     printArray(path,pathLen);
   else{
     printPathRec(root->left,path,pathLen);
     printPathRec(root->right,path,pathLen);
   }
}

void printPaths(bt *root){
   int path[1000];
   int pathLen = 0;
   printPathRec(root,path,pathLen);
}

int main(){
     bt *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     printPaths(root);
}
