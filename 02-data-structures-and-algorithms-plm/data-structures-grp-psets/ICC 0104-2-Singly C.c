#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};
void display (struct node *);

struct node *create (int);
struct node *AddNode (struct node *);
struct node *InsertEnd (struct node *);
struct node *InsertBef (struct node *);
struct node *InsertAft (struct node *);
struct node *DelBeg (struct node *);
struct node *DelEnd (struct node *);
struct node *DelNod (struct node *);
struct node *DelBefore (struct node *);
struct node *DelAfter (struct node *);
struct node *DelAll (struct node *);


int main(){
    int n, option;
    struct node *head;
    printf("\n ***** This program shows the List of your Daily Expenses ***** \n");
    printf ("\n How many expenses do you want to input? : ");
    scanf ("%d",&n);
	
    head = create (n);
    
    printf("\n*********LIST OF EXPENSES**********\n");
    display (head);
    
    do{
        	
    	printf (" \n What do you want to do with your list of Daily Expenses? \n");
	    printf (" No.1: Add an amount at the beginning  \n");
	    printf (" No.2: Add an amount at the end \n");
	    printf (" No.3: Add an amount before a given amount \n");
		printf (" No.4: Add an amount after a given amount \n");
	    printf (" No.5: Delete an amount at the beginning \n");
	    printf (" No.6: Delete an amount at the end \n");
	    printf (" No.7: Delete a given amount \n");
	    printf (" No.8: Delete an amount before a given amount \n");
		printf (" No.9: Delete an amount after a given amount \n");
	    printf (" No.10: Delete entire list of Daily Expenses \n");
	    printf (" No.11: Create a new list of Daily Expenses \n");
	    printf (" No.12: EXIT \n");


	    printf("\n\n Enter your option : ");
	    scanf("%d", &option);
	    switch(option) {
	    	case 1: head = AddNode (head);
		    	printf ("\n ******** OPERATION: Add an amount at the beginning ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
		    	display (head);
		    	break;
		    case 2: head = InsertEnd (head);
		    	printf ("\n ******** OPERATION: Add an amount at the end ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
		    	display (head);
		    	break;
		   	case 3: head = InsertBef (head);
		    	printf ("\n ******** OPERATION: Add an amount before a given amount ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		    	break;
		   	case 4: head = InsertAft (head);
		    	printf ("\n ******** OPERATION: Add an amount after a given amount ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		    	break;
		   	case 5: head = DelBeg (head);
		    	printf ("\n ******** OPERATION: Delete an amount at the beginning ******** \n");
		   		printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		    	break;
		   	case 6: head = DelEnd (head);
		    	printf ("\n ******** OPERATION: Delete an amount at the end ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		 		break;
		   	case 7: head = DelNod (head);
		  		printf ("\n ******** OPERATION: Delete a given amount ******** \n");
		   		printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		   		break;
		   	case 8: head = DelBefore (head);
		   		printf ("\n ******** OPERATION: Delete an amount before a given amount ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		    	break;    
		    case 9: head = DelAfter (head);
		    	printf ("\n ******** OPERATION: Delete an amount after a given amount ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		    	break;
		    case 10: head = DelAll (head);
		    	printf ("\n ******** OPERATION: Delete entire list of Daily Expenses ******** \n");
		    	display (head);
		    	break;
		    case 11:
			    printf ("\n How many expenses do you want to input? : ");
			    scanf ("%d",&n);
			    head = create (n);
			    printf ("\n ******** OPERATION: Create a new list of Daily Expenses ******** \n");
			    printf("\n**********UPDATED LIST OF EXPENSES**********\n");
			    display (head);
		    	break;
		    case 12:
		    	printf("\n Program Terminated");
				exit(0);   	    	    		     
		}
		printf("\n\n Press any key to make another operation ... \n\n");
		getch();
	}while(option < 13);
	printf("\n Wrong Operation Number ");
		printf("\n Program Terminated ");
	getch();

    return 0;
}

struct node *create (int n){
    int i;
    struct node *head = NULL;
    struct node *ptr,*NewNode;

    for (i = 0; i < n ;i++){
		
        NewNode = (struct node*)malloc(sizeof(struct node*));
		
        printf ("Enter the amount for your daily expenses no. %d: PHP : ", i+1);
        scanf ("%d", &NewNode -> data);
        NewNode -> next = NULL;
		
        if (head == NULL){
            head = NewNode;
        }
		else{
			
            ptr = head;
            while (ptr -> next != NULL){
                ptr = ptr -> next;
            }
            ptr -> next = NewNode;
        }
    }
    return head;
}

void display (struct node *head){
    struct node *ptr;
	
    if (head == NULL){
        printf ("The linked list is empty.");
    }
	else{
		
        ptr = head;
        while (ptr != NULL){
            printf("\t The amount value = %d \n", ptr -> data, ptr);
            ptr = ptr -> next;
        }
    }
}


struct node *AddNode (struct node *head){
	int data;
	struct node *NewNode;
	
	printf("\n\n Enter the amount you want to insert at the start of the list: PHP ");
    scanf("%d", &data);
	
	NewNode = (struct node*)malloc(sizeof(struct node*));
    
    
    if(NewNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        NewNode->data = data; 
        NewNode->next = head; 
        head = NewNode;        
    }
    
    return head;
}

struct node *InsertEnd (struct node *head){
	int data;
	struct node* NewNode, * temp;
	
	printf("\n \n Enter the amount you want to insert at the end of the list: PHP ");
	scanf("%d", &data);

	NewNode = (struct node*)malloc(sizeof(struct node));

	if (NewNode == NULL)
	{
		printf("Unable to allocate memory.");
	}
	else
	{
		NewNode->data = data;
		NewNode->next = NULL;

		temp = head;

		while (temp != NULL && temp->next != NULL)
			temp = temp->next;

		temp->next = NewNode;
	}
	
	return head;
	
}

struct node *InsertBef (struct node *head){
	int no1;
	struct node *NewNode, *head2 = NULL, *temp;;
	
    printf("\n Enter the value that the amount will be inserted before it: PHP ");
    scanf("%d",&no1);
    
    NewNode = (struct node*)malloc(sizeof(struct node));
    
    printf("\n Enter the amount to be inserted: ");
    scanf("%d",&NewNode->data);
    NewNode->next = NULL;
	
    temp = head;
    
    
    struct node *temp1;
    while(temp->data != no1)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next  = NewNode;
    NewNode->next = temp;
    
    return head;
}

struct node *InsertAft (struct node *head){
		int data, no1;
		struct node *NewNode, *head2, *temp;
		
		printf("\n Enter the value that the amount will be inserted after it: PHP ");
    	scanf("%d",&no1);
    	NewNode = (struct node*)malloc(sizeof(struct node));
    
   		printf("\n Enter the amount to be inserted: ");
    	scanf("%d",&data);
    	
    	NewNode -> data = data;
    	temp = head;
    	head2 = temp;
    	while (head2->data != no1)
    	{
    		head2= temp;
    		temp = temp->next;
		}
		head2->next = NewNode;
		NewNode->next = temp;
		
		return head;
	}
	
struct node *DelBeg (struct node *head){
	
	struct node *del_start;

    if(head == NULL)
    {
        printf("The Daily Expenses List is empty.");
    }
    else
    {
        del_start = head;
        head = head->next;
//        printf("\n Daily Expenses deleted = %d\n", del_start->data);
        free(del_start);

          }

	return head;

}

struct node *DelEnd (struct node *head){

	struct node *temp, *previous;

	temp = head;

    while (temp->next != NULL){
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    previous = NULL;
    free(temp); temp = NULL;
	
	return head;
	
}

struct node *DelNod (struct node *head){
	
	int del;
	struct node *temp, *previous;
	    
    printf("\n\n Enter the amount you want to delete: PHP ");
    scanf("%d", &del); 
    
	temp = head;
    if (temp -> data == del)
    {
    	head = DelBeg(head);
    	return head;
	}
	else{
		while (temp->data != del)
		{
			previous = temp;
			temp = temp -> next;
		}
		previous-> next = temp -> next;
		free (temp);
	return head;
	}	
}

struct node *DelBefore (struct node *head){
    int DelVal;
    struct node *address, *PrevAdd, *TempAdd;

    printf ("\n Enter the value before which amount to delete before it: PHP ");
    scanf ("%d", &DelVal);
	
    if (head == NULL){
        printf ("\n No amount available to delete!");
    }
	
    else if (head -> next == NULL){
        printf ("No any previous amount available to delete!");
    }
	
    else{
        address = head;
        TempAdd = head;
        PrevAdd = head;
		
        while (address -> data != DelVal){
            TempAdd = PrevAdd;
            PrevAdd = address;
            address = address -> next;
        }
		
        if (address == head -> next){
            head = address;
            free (PrevAdd);
        }
		
        else if (address == head){
            printf ("No any previous amount available to delete!");
        }
		
        else{
            TempAdd -> next = address;
            free (PrevAdd);
        }
    }
    return head;
}

struct node *DelAfter (struct node *head)
	{
		int DelVal;
		struct node *NewNode, *head2, *temp;
		 	
    	printf ("\n Enter the value after which amount to delete after it: PHP ");
    	scanf ("%d", &DelVal);
    	
    	temp = head;
    	head2 = temp;
    	
    	while (head2->data != DelVal){
    		head2 = temp;
    		temp = temp -> next;
		}
		if (head2 == head){
			head -> next = temp -> next -> next;
			temp = NULL;
		}
		else 
			head2 -> next = temp -> next;
			free (temp);
			
    	return head;
}

struct node *DelAll (struct node *head)
{
	struct node *temp; 
	if (head != NULL)
	{
		temp = head;
		while(temp != NULL)
	{
	 printf ("%d will be deleted \n", temp->data);
	 head = DelBeg(temp);
	 temp = head;
	}
    }	
		return head;
}

