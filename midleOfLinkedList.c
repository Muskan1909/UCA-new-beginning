#include<stdio.h>
struct Node{
  int data;
  struct Node *next;
}Node;
void FindMiddle(Node **h){
  struct Node *fast,*slow;
  fast=h;
  slow=h;
  while(fast->next->next!=NULL){
    if(fast==slow){
        printf("Middle element is %d",slow->data);
    }
    fast=fast->next->next;
    slow=slow->next;
  }
}
int main(){
  struct Node *head=NULL;
  struct Node *n=(Node*)malloc(sizeof(Node*));
  while(n!=NULL){
    *n=createNewNode();
  }
  FindMiddle(&head);
}
