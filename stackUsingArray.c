#include<stdio.h>
#include<stdlib.h>
//#include<bool.h>
#define SIZE 5
typedef struct stack{
    int *arr;
    int top;
}stk;
int isEmpty(stk *mem){
    if(mem->top==-1)
        return 1;
    return 0;
}
int isFull(stk *mem){
    if(mem->top==SIZE)
        return 1;
    return 0;
}
void initialize(stk *mem,int x){
    mem->arr=(int*)malloc(sizeof(int)*x);
    mem->top=-1;
}
void push(stk *mem,int d){
    mem->top=mem->top+1;
    if(isFull(mem))
        printf("Stack is full\n");
    else{
        mem->arr[mem->top]=d;
        //printf("%d ",mem->arr[mem->top]);
    }
}
int pop(stk *mem){
    if(isEmpty(mem))
        printf("Stack is empty\n");
    else{
        //printf("sef");
        return mem->arr[mem->top];
    }
}
int main(){
    stk *s=(stk*)malloc(sizeof(stk));
    int d,k,i,item;
    initialize(s,SIZE);
    for(i=0;i<SIZE;i++){
        scanf("%d",&d);
        push(s,d);
    }
    s->top=SIZE-1;
    for(i=0;i<SIZE;i++){
        printf("%d",s->arr[s->top]);
        s->top=s->top-1;
    }
    //printf("jdsfkdgsh");
    s->top=SIZE-1;
    //printf("%d",s->arr[s->top]);
    for(i=SIZE-1;i>=0;i--){
        k=pop(s);
        printf("%d is popped\n",k);
        s->top=s->top-1;
    }
}
