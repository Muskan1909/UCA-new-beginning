#include <stdio.h>
#include <stdlib.h>
typedef struct btree{
    int data;
    struct btree *left;
    struct btree *right;
}bt;

void inorder(bt* root){
    if(root == NULL)
       return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

bt* newNode(int d){
    bt *nn = (bt*)malloc(sizeof(bt));
    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

bt* builtTree(int* post,int* in,int start,int end){
    static int index = 6;
    if(start > end)
      return NULL;
    bt *nn = newNode(post[index--]);
    if(start == end)
      return nn;
    int i;
    for(i=start;i<=end;i++){
       if(post[index]==in[i])
          break;
    }
    nn->left = builtTree(post,in,i+1,end);
    nn->right = builtTree(post,in,start,i-1);
    return nn;
}

int main(){
    int post[] = {4,5,2,6,7,3,1};
    int in[] = {4,2,5,1,6,3,7};
    int start = 0;
    int end = 6;
    bt *nn = builtTree(post,in,start,end);
    inorder(nn);
}
