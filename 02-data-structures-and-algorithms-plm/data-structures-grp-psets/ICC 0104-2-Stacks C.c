// Group 1 Block 2 Stacks

#include<stdio.h>
#include<conio.h>

#define SIZE 10

void InsertNode(int);
void DelNode();
void Traverse();

int stack[SIZE], top = -1;

void main()
{
   int value, choice;
   
   while(1){
      printf("Stack Operations.\n");
      printf("1. Insert into stack (Push operation).\n");
      printf("2. Delete from stack (Pop operation).\n");
      printf("3. Traverse stack.\n");
      printf("4. Exit.\n\n");
      printf("Enter your choice.\n");
      scanf("%d",&choice);
      
      
      switch(choice){
	case 1: 
		 printf("Enter value: ");
		 scanf("%d",&value);
		 InsertNode(value);
		 break;
		 
	 case 2: 
	 	 DelNode();
		 break;
		 
	 case 3: 
	     Traverse();
		 break;
		 
	 case 4: 
	 	exit(0);
	 	break;
	    default: printf("\nEnter valid choice!\n\n");
      }
   }
}


void InsertNode(int value){
   if(top == SIZE-1)
      printf("\nStack is Full!");
   else{
      top++;
      stack[top] = value;
      printf("\nThe value has been added to the stack.\n\n");
   }
}

void DelNode(){
   if(top == -1)
      printf("\nStack is Empty!\n");
   else{
      printf("\nDeleted : %d\n\n", stack[top]);
      top--;
   }
}

void Traverse(){
   if(top == -1)
      printf("\nStack is Empty!\n");
   else{
      int i;
      printf("\nThe Stack contain element/s:\n\n");
      for(i=top; i>=0; i--)
	 printf("%d\n",stack[i]);
   }
}
