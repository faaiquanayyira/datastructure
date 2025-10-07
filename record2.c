//cir cular Queue Add Delete Search

#include <stdio.h>
#include<stdlib.h>
#define SIZE 10

int que[SIZE],front=1,rear=1;

void main(){
  
  void enque(int);
  int opt,item,ans;
  int deque();
  void display();
  int search();
  
  while(1){
    printf("\n1-Add\n 2-Delete\n 3-Display\n 4-Search\n 5-Exit\n");
    printf("\n your option:");
    scanf("%d",&opt);
    
    switch(opt){
    
      case 1: printf("\n Item to insert:");
             scanf("%d",&item);
             enque(item);
             break;
             
       case 2:item=deque();
             printf("\n Deleted item=%d",item);
             break;
             
       case 3:display();
             break;
             
       case 4:printf("\n Item to search:");
             scanf("%d",&item);
             ans=search(item);
             if(ans==1)
               printf("\n Found");
             else
               printf("\n Not found");
             break;
        
       case 5:exit(0);
             
    }
  }
}

void enque(int data){

   int r1;
   r1=(rear+1)%SIZE;
   if(r1==front)
      printf("Queue is full");
    else{
       rear=r1;
       que[rear]=data;
    }
    return;
}

int deque(){
  if(front==rear){
    printf("Queue is empty");
    exit(1);
  }
  else{
    front=(front+1)%SIZE;
    return que[front];
  }
}

void display(){
   int f=front,r=rear;
   while(f!=r){
     f=(f+1)%SIZE;
     printf("%d,",que[f]);
   }
   return;
}  

int search(int item){
     int f=front,r=rear;
     while(f!=r){
       f=(f+1)%SIZE;
       if(que[f]==item)
       return 1;
   }
   return 0;
}








