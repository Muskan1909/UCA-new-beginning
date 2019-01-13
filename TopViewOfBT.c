#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct btree{
        int data;
        int hd;
        struct btree *left;
        struct btree *right;
}bt;

typedef struct Node{
        bt *ptr;
        struct Node *next;
}node;

typedef struct queue{
        node* head;
        node* tail;
}que;

bool isEmpty(que *q){
        if(q->head == NULL  && q->tail == NULL)
                return true;
        return false;
}

void push(que *q,bt* root){
        node *nn = (node*)malloc(sizeof(node));
        nn->ptr = root;
        nn->next = NULL;
        if(isEmpty(q)){
                q->head = nn;
                q->tail = nn;
        }
        q->head->next = nn;
        q->head = nn;
}

bt* pop(que *q){
        if(isEmpty(q))
                return NULL;
        bt* temp = q->tail->ptr;
        q->tail = q->tail->next;
        if(q->tail == NULL)
                q->head = NULL;
        return temp;
}

int height(bt* root){
        if(root == NULL)
                return 0;
        int lDepth = height(root->left);
        int rDepth = height(root->right);
        if(lDepth>rDepth)
                return lDepth+1;
        else
                return rDepth+1;
}

void topView(bt* root){
        que *q = (que*)malloc(sizeof(que));
        q->head = q->tail = NULL;
        int h = height(root);
        int *arr = (int*)malloc(sizeof(int)*(2*h));
        int i;
        for(i=0;i<2*h;i++)
                arr[i] = -1;
        if(root == NULL)
                return ;
        push(q,root);
        while(!isEmpty(q)){
                bt* d = pop(q);
                int prev_hd = d->hd;
                if(d->left){
                        push(q,d->left);
                        d->left->hd = prev_hd - 1;
                }
                if(d->right){
                        push(q,d->right);
                        d->right->hd = prev_hd + 1;
                }
                if(arr[prev_hd + h]==-1)
                        arr[prev_hd + h] = d->data;
        }
        int j;
        for(int j = 0;j < 2*h;j++){
                if(arr[j]!=-1)
                        printf("%d ",arr[j]);
        }


}

bt* createTree(bt* root,int d){
        if(root == NULL){
                bt *nn = (bt*)malloc(sizeof(bt));
                nn->data = d;
                nn->left = nn->right = NULL;
                nn->hd = 0;
                return nn;
        }

        else if(d <= root->data)
                root->left = createTree(root->left,d);
        else
                root->right = createTree(root->right,d);
        return root;
}

int main(){
        int data;
        int i;
        bt* root = NULL;
        for(i=0;i<9;i++){
                scanf("%d",&data);
                root = createTree(root,data);
        }
        topView(root);
}
~
