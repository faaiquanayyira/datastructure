#include<stdio.h>
#include<stdlib.h>

struct node{
 
 int data;
 struct node *next;
 
};

void main(){
  
  struct node * SP=(struct node*)0;
  
  int opt,item,ans;
  
  struct node * Push(struct node * , int);
  struct node * Pop(struct node *);
  void display(struct node *);
  int search(struct node *, int);
  
  while(1){
    
    printf("\n 1. Push\n 2.Pop\n 3.Display\n 4.Search\n 5.Exit\n");
    printf("\n Your option:");
    scanf("%d",&opt);
    
    switch(opt){
    
      case 1: printf("\n Item to insert:");
             scanf("%d",&item);
             SP = Push(SP, item);
             break;
             
       case 2:SP=Pop(SP);
             printf("\n Deleted item=%d",item);
             break;
             
       case 3:display(SP);
             break;
             
       case 4:printf("\n Item to search:");
             scanf("%d",&item);
             ans=search(SP,item);
             if(ans==1)
               printf("\n Found");
             else
               printf("\n Not found");
             break;
        
       case 5:exit(0);
             
    }
  }
}

struct node * Push(struct node * list,int data){

  struct node * t;
  t=(struct node * )malloc(sizeof(struct node));
  t->data=data;
  t->next=list;
  list=t;
  return list;
  
}

struct node * Pop(struct node *list){

   struct node *t=list;
   if(list!=(struct node*)0){
      list=list->next;
      free(t);
   }
   else
      printf("list is empty\n");
      
      return list;

}

void display(struct node* list) {
    while (list != (struct node*)0) {
        printf("%d ", list->data);
        list = list->next;
    }
    return;
}

int search(struct node* list, int item) {
    while (list != (struct node*)0 && item != list->data)
        list = list->next;

    if (list == (struct node*)0)
        return 0;
    else
        return 1;
}
