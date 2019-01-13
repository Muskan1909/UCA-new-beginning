#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};

void reverseListREC(struct node *curr,struct node *prev,struct node **h){
     if(!curr->next){
       *h=curr;
       curr->next=prev;
       return;
     }
    struct node *next=curr->next;
     curr->next=prev;
     reverseListREC(next,curr,h);
}



void reverse(struct node **h){
  if(!h)
    return;
  reverseListREC(*h,NULL,h);
}


void createList(struct node **h,int d){
  struct node *new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->next=*h;
  *h=new;
  }

void printList(struct node *h){
  struct node *temp1=h;
  while(temp1!=NULL){
    printf("\n%d ",temp1->data);
    temp1=temp1->next;
  }

}

int main(){
  int n,d;
  struct node* head=NULL;
  printf("How many nodes are needed\n");
  scanf("%d",&n);
  while(n--){
    scanf("%d",&d);
    createList(&head,d);
  }
  printList(head);
  reverse(&head);
}
