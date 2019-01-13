#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct stack{
    int *arr;
    int top;
}stk;
int isEmpty(stk *s){
    if(s->top==-1)
        return 1;
   else
        return 0;
}
void initialize(stk *s,int x){
    s->arr=(int*)malloc(sizeof(int)*x);
    s->top=-1;
}
void push(stk *s,int d){
    s->top=s->top+1;
    s->arr[s->top]=d;
}
void pop(stk *s){
       s->top--;
}
void stock(stk *s,int *price,int size,int span[]){
    span[0]=1;
    push(s,0);
    int i;
    for(i=1;i<size;i++){
        while(!isEmpty(s) && price[s->top]<=price[i])
            pop(s);
        span[i]=(isEmpty(s))?(i+1):(i-(s->top));
        push(s,i);
    }
}
int main(){
     stk *s=(stk*)malloc(sizeof(stk));
     int price[]={10,4,5,90,120,80};
     int size=sizeof(price)/sizeof(int);
     initialize(s,size);
     int span[size];
     stock(s,price,size,span);
     int i;
     for(i=0;i<size;i++)
        printf("%d ",span[i]);
}
