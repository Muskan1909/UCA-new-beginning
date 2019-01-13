#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct stack{
    char *arr;
    int top;
}stk;
int isEmpty(stk *s){
    if(s->top==-1)
        return 1;
   else
        return 0;
}
void initialize(stk *s,int x){
    s->arr=(char*)malloc(sizeof(char)*x);
    s->top=-1;
}
void push(stk *s,char d){
    s->top=s->top+1;
    s->arr[s->top]=d;
}
void pop(stk *s){
       s->top--;
}
int main(){
    char *expr="{()[(])}";
    int l=strlen(expr);
    //printf("%d",l);
    if(l%2!=0)
        printf("non valid parenthesis");
    else{
    stk *s=(stk*)malloc(sizeof(stk));
    int i;
    initialize(s,l);
        //push(s,expr[0]);
        for(i=0;i<l;i++){
            /*if(isEmpty(s)){
                push(s,expr[i]);
                //printf("%d",s->arr[s->top]);
            }*/
            if(((s->arr[s->top]=='(')&&(expr[i]==')'))||((s->arr[s->top]=='{')&&(expr[i]=='}'))||((s->arr[s->top]=='[')&&(expr[i]==']'))){
                pop(s);
            }
            else{
                push(s,expr[i]);
            }
        }
    //printf("%d",s->top);
    if(isEmpty(s))
        printf("Valid parenthesis");
    else
        printf("Non valid parenthisis");
