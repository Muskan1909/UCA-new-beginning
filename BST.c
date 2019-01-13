#include <stdio.h>
#include <stdlib.h>
typedef struct binarySearchTree {
    int data;
    struct binarySearchTree *left;
    struct binarySearchTree *right;
}bst;

bst* newNode(int d) {
    bst* temp;
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bst* insert(bst* root,int item) {
     if(root == NULL){
        bst* nn = (bst*)malloc(sizeof(bst));
        nn->data = item;
        nn->left = NULL;
        nn->right = NULL;
        return nn;
     }
     else if(item < root->data)
        root->left = insert(root->left,item);
     else
        root->right = insert(root->right,item);
     return root;
}

void inorder(bst* root) {
     inorder(root->left);
     printf("%d ",root->data);
     inorder(root->right);
}

int main(){
    int arr[8] = {5,7,2,9,4,8,3,6};
    bst* root = NULL;
    int i;
    for(i=0;i<8;i++)
        root = insert(root,arr[i]);
    inorder(root);
}
