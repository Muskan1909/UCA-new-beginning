#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
# define SIZE 5
typedef struct queue{
    int *arr;
    int head;
    int tail;
}que;
void initialize(que *q,int x){
     q->arr=(int*)malloc(sizeof(int)*x);
     q->head=0;
     q->tail=-1;
}
void push(que *q,int d){
    q->arr[q->head]=d;
    q->head++;
    q->tail=0;
}
int pop(que *q){
    int k,i;
    k=q->arr[q->tail--];
    for(i=0;i<SIZE;i++){
        q->arr[i]=q->arr[i+1];
    }
    q->tail++;
    return k;
}
int main(){
    que *q=(que*)malloc(sizeof(que));
    initialize(q,SIZE);
    int d,i,k;
    for(i=0;i<SIZE;i++){
        scanf("%d",&d);
        push(q,d);
    }
    k=pop(q);
    printf("%d is popped\n",k);
    q->head=0;
    for(i=0;i<SIZE-1;i++){
        printf("%d ",q->arr[q->head]);
        q->head++;
    }
}
