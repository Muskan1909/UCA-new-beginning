#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Qnode{
    int data;
    struct Qnode *next;
}node;

typedef struct queue{
    node *front,*rear;
}que;

que* createQueue(){
    que *q = (que*)malloc(sizeof(que));
    q->front = q->rear = NULL;
    return q;
}

node* newNode(int k){
     node *temp = (node*)malloc(sizeof(node));
     temp->data = k;
     temp->next = NULL;
     return temp;
}

void enqueue(que *q,int d){
     node *nn = newNode(d);
     if(q->rear == NULL){
           q->front = q->rear = nn;
           return ;
     }
     q->rear->next = NULL;
     q->rear = nn;
}

node* dequeue(que *q){
     if(q->front == NULL){
           return NULL;
     }
     node *temp = q->front;
     q->front = q->front->next;

     if(q->front == NULL){
          q->rear = NULL;
     }
     return temp;
}

int main(){
     que* q = createQueue();
     enqueue(q,10);
     enqueue(q,20);
     enqueue(q,30);
     enqueue(q,40);
     enqueue(q,50);
     dequeue(q);
}
