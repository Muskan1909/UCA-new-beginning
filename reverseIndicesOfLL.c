  int data;
  struct node *next;
};

void reverseList(struct node **h){
  struct node *prev,*curr,*next;
  curr=*h;
  prev=NULL;
  next=NULL;
  while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  *h=prev;
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
  reverseList(&head);
}

         
