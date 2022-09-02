#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * prev;
    struct node * next;
}*start, *end;


// STRUCTS HERE
struct node *create (int);   
struct node *DispTopToBot (struct node *);
struct node *DispBotToTop (struct node *);
struct node *InsertBeg (struct node *);
struct node *InsertEnd (struct node *);
struct node *InsertNodeBefore (struct node *);
struct node *InsertNodeAfter (struct node *);
struct node *DelBeg (struct node *);
struct node *DelEnd (struct node *);
struct node *DelNode (struct node *);
struct node *DelNodeBefore (struct node *);
struct node *DelNodeAfter (struct node *);
struct node *DelAll (struct node *);

void display(int head); 

int main()
{
    int n,num1,head, option;
    start = NULL;
    end = NULL;
	printf("\n ***** This program shows the List of your Daily Expenses ***** \n");
	printf("------------------------------------------------------------------------------------\n");	   	

    printf(" \n How many expenses do you want to input? : ");
    scanf("%d", &n);
    create(n); 
    head=1;
    printf("\n*********LIST OF EXPENSES**********\n");
    display(head);
    
    //STATEMENTS FOR THE MAIN MENU
     do{
        	
    	printf (" \n What do you want to do with your list of Daily Expenses? \n");
    	printf (" No.1: Display the list from TOP to BOTTOM  \n");
    	printf (" No.2: Display the list from BOTTOM to TOP  \n");
	    printf (" No.3: Add an amount at the beginning  \n");
	    printf (" No.4: Add an amount at the end \n");
	    printf (" No.5: Add an amount before a given amount \n");
		printf (" No.6: Add an amount after a given amount \n");
	    printf (" No.7: Delete an amount at the beginning \n");
	    printf (" No.8: Delete an amount at the end \n");
	    printf (" No.9: Delete a given amount \n");
	    printf (" No.10: Delete an amount before a given amount \n");
		printf (" No.11: Delete an amount after a given amount \n");
	    printf (" No.12: Delete entire list of Daily Expenses \n");
	    printf (" No.13: Create a new list of Daily Expenses \n");
	    printf (" No.14: EXIT \n");

	// Switch statement for the main menu options and connect it to their respective functions
	    printf("\n\n Enter your option : ");
	    scanf("%d", &option);
	    switch(option) {    
	    	case 1:
		    	printf ("\n ******** OPERATION:  Display the list from TOP to BOTTOM ******** \n");
		    	display (head);
		    	break;
		    case 2: head = DispBotToTop (head);
		    	break;
	    	case 3: head = InsertBeg (head);
		    	printf ("\n ******** OPERATION: Add an amount at the beginning ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
		    	display (head);
		    	break;
		    case 4: head = InsertEnd (head);
		    	printf ("\n ******** OPERATION: Add an amount at the end ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
		    	display (head);
		    	break;
		   	case 5: head = InsertNodeBefore (head);
		    	printf ("\n ******** OPERATION: Add an amount before a given amount ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		    	break;
		   	case 6: head = InsertNodeAfter (head);
		    	printf ("\n ******** OPERATION: Add an amount after a given amount ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		    	break;
		   	case 7: head = DelBeg (head);
		    	printf ("\n ******** OPERATION: Delete an amount at the beginning ******** \n");
		   		printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		    	break;
		   	case 8: head = DelEnd (head);
		    	printf ("\n ******** OPERATION: Delete an amount at the end ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		 		break;
		   	case 9: head = DelNode (head);
		  		printf ("\n ******** OPERATION: Delete a given amount ******** \n");
		   		printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		   		break;
		   	case 10: head = DelNodeBefore (head);
		   		printf ("\n ******** OPERATION: Delete an amount before a given amount ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		    	break;    
		    case 11: head = DelNodeAfter (head);
		    	printf ("\n ******** OPERATION: Delete an amount after a given amount ******** \n");
		    	printf("\n**********UPDATED LIST OF EXPENSES**********\n");
				display (head);
		    	break;
		    case 12: head = DelAll (head);
		    	display (head);
		    	break;
		    case 13:
			    printf ("\n How many expenses do you want to input? : ");
			    scanf ("%d",&n);
			    head = create (n);
			    printf ("\n ******** OPERATION: Create a new list of Daily Expenses ******** \n");
			    printf("\n**********UPDATED LIST OF EXPENSES**********\n");
			    display (head);
		    	break;
		    case 14:
		    	printf("\n Program Terminated");
				exit(0); 	    	    		     
		}
		printf("\n\n Press any key to make another operation ... \n\n");
		getch();
	}while(option < 15);
	printf("\n Wrong Operation Number ");
		printf("\n Program Terminated ");
	getch();
	
    return 0;
}


struct node *create(int n)  
{
    int i, num, option;
    struct node *NewNode;
 
    if(n >= 1)
    {
        start = (struct node *)malloc(sizeof(struct node));
 
        if(start != NULL)
        {
            printf("Enter the amount for your daily expenses no. 1: PHP : "); 
            scanf("%d", &num);
 
            start->num = num;
            start->prev = NULL;
            start->next = NULL;
            end = start;
            for(i=2; i<=n; i++)
            {
                NewNode = (struct node *)malloc(sizeof(struct node));
                if(NewNode != NULL)
                {
                    printf("Enter the amount for your daily expenses no. %d: PHP : ", i);
                    scanf("%d", &num);
                    NewNode->num = num;
                    NewNode->prev = end;   
                    NewNode->next = NULL;
 
                    end->next = NewNode; 
                    end = NewNode;            
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}


// FUNCTIONS HERE

struct node *DispBotToTop (struct node *head){
	struct node * tmp, *TravNode;
    int n = 1;
    TravNode = end;
    if(TravNode == NULL)
    {
        printf("Double/Doubly Linked List is Empty!");
    }
    else
    {	
    printf ("\n ******** OPERATION: Display the list from BOTTOM to TOP ******** \n");
        do{    
            printf(" The amount value %d = %d\n", n, TravNode->num);
            n++;
            TravNode = TravNode->prev; 
		}
 
       while(TravNode != NULL);
    }
}


struct node *InsertBeg (struct node *head){
	    struct node * NewNode;
	    NewNode = (struct node *)malloc(sizeof(struct node));
	    
	    int num;
	    printf(" Enter the amount you want to insert at the start of the list: PHP ");  
		scanf("%d", &num);
		if(start == NULL) {
		
	        printf(" No data found in the list!\n");
	    }
	    else
	    {
	        NewNode->num = num;
	        NewNode->next = start;  
	        NewNode->prev = NULL;     
	        start-> prev = NewNode;  
	        start = NewNode; 	               
	    }  
}


struct node *InsertEnd (struct node *head){

	struct node *NewNode;
	 
	NewNode = (struct node *)malloc(sizeof(struct node));
	
	int num; 
	printf(" Enter the amount you want to insert at the end of the list: PHP ");
	scanf("%d", &num);
	
	NewNode->prev = NULL;
	NewNode->next=NULL;
	    
	    if(end == NULL)
	    {
	   		 printf(" No data found in the list!\n"); 

	    }
	    else
	    {
	        NewNode->prev = end;       
	        end->next = NewNode;      
	        end = NewNode;    
	        
	    }	        
			NewNode->num = num;
	        NewNode->next = NULL;  
}

struct node *InsertNodeBefore (struct node *head){
	struct node *newnode, *current;
	    newnode = (struct node *)malloc(sizeof(struct node)); 
	 	int num, val, flag = 0;
	 	
	 	printf("\n Enter the value that the amount will be inserted after it: PHP  ");
	    scanf("%d", &val); 
	    printf(" \n Enter the amount to be inserted:  ");
	    scanf("%d", &num); 
	    
	    newnode->num = num;
	    
	    newnode->prev=NULL;
	    newnode->next=NULL;
	    
	    current = start;
	    
	    if(current == NULL)
				printf("The List is Empty!");
			else
			{
				while(flag==0 && current!=NULL)
				{
					if (current->num == val)
						flag=1;
					else
					current = current-> next;
				}
		if (flag == 0)
			printf("\n The Value where the amount be inserted before does not exist!");
		else
		{ if (current == start)
			{	newnode->next=start;
				start->prev= newnode;
				start = newnode;	
			}
		  else
			{	newnode->next=current;
				newnode->prev=current->prev;
				current->prev->next=newnode;
				current->prev =newnode;
			}
			current=newnode=NULL;
			}
	    }
}

struct node *InsertNodeAfter (struct node *head){

    struct node *newnode, *current;
    newnode = (struct node *)malloc(sizeof(struct node));
 	int num, val, flag = 0;
 	
 	printf("\n Enter the value that the amount will be inserted after it: PHP  ");
    scanf("%d", &val); 
    printf(" \n Enter the amount to be inserted:  ");
    scanf("%d", &num);  
    
    newnode->num = num;
    
    newnode->prev=NULL;
    newnode->next=NULL;
    
    current = start;
    
    if(current == NULL)
			printf("The List is Empty!");
		else
		{
			while(flag==0 && current!=NULL)
			{
				if (current->num == val)
					flag=1;
				else
				current = current-> next;
			}
	if (flag == 0)
		printf("\n The Value where the amount be inserted before does not exist!");
	else
	{ if (current == end)
		{	newnode->prev=end;
			end->next= newnode;
			end = newnode;	
		}
	  else
		{	newnode->next=current->next;
			newnode->prev=current;
			current->next->prev=newnode;
			current->next =newnode;
		}
		current=newnode=NULL;
		}
    }
}

struct node *DelBeg (struct node *head){
	
	struct node * NodeToDel;
	    if(start == NULL)
	    {
	        printf(" Delete is not possible. \n");
	    }
	    else
	    {
	        NodeToDel = start;
	        start = start->next;  
	        start->prev = NULL;      
	        free(NodeToDel);            
	    }
}


struct node *DelEnd (struct node *head){
	struct node * NodeToDel;
	 
	    if(end == NULL)
	    {
	        printf(" Delete is not possible. \n");
	    }
	    else
	    {
	        NodeToDel = end;
	        end = end->prev;    
	        end->next = NULL;    
	        free(NodeToDel);            
	    }
}


struct node *DelNode (struct node *head){
		
		struct node *DelNode;
		int delete_val, flag = 0;
		printf("\n Enter the amount you want to delete: PHP ");
		scanf("%d", &delete_val);
		DelNode = start;
		if(DelNode==NULL)
			printf("Double/Doubly Linked List is Empty!");
		else
		{
			while(flag==0 && DelNode!=NULL)
			{
				if(DelNode->num==delete_val)
					flag = 1;
				else
					DelNode=DelNode->next;
			}
		}
		
		if(flag==0)
			printf("The value to be deleted does not exist!");
		else
		{
			if(DelNode==start)
			{
				start=start->next;
				start->prev=NULL;
				DelNode->next=NULL;
			}
				else if(DelNode==end)
				{
					end=end->prev;
					end->next=NULL;
					DelNode->prev=NULL;
				}
					else
					{
						DelNode->prev->next=DelNode->next;
						DelNode->next->prev=DelNode->prev;
						DelNode->next=NULL;
						DelNode->prev=NULL;
					}
				free(DelNode);
				DelNode=NULL;
		}
		return start;
}


struct node *DelNodeBefore (struct node *head){
	struct node *Current;
	int before_val, flag = 0;
	printf("\n Enter the value before which amount to delete before it: PHP ");
	scanf("%d", &before_val);
	Current = start;
	
	if(Current==NULL)
		printf("Double/Doubly Linked List is Empty!");
	else
	{
		while(flag==0 && Current!=NULL)
		{
			if(Current->num==before_val)
				flag = 1;
			else
				Current = Current->next;
		}
	}
	
	if(flag==0)
		printf("The value before which the node has to be deleted does not exist!");
	else
	{
		if(Current==start->num)
		{
			printf("There is No Node before this Node!!!");
		}
		else if(Current->prev->prev == NULL)
		{
			Current->prev->next = NULL;
			Current->prev=NULL;
			start=Current;
		}
		else
		{
			Current->prev->next = NULL;
			Current->prev=Current->prev->prev;
			Current->prev->next->prev = NULL;
			Current->prev->next = Current;
			
		}
		Current=NULL;
	}
	return start;
   
}



struct node *DelNodeAfter (struct node *head){
	
	struct node *Current;
	int after_val, flag = 0;
	printf("\n Enter the value after which amount to delete after it: PHP ");
	scanf("%d", &after_val);
	Current = start;
	
	if(Current==NULL)
		printf("Double/Doubly Linked List is Empty!");
	else
	{
		while(flag==0 && Current!=NULL)
		{
			if(Current->num==after_val)
				flag = 1;
			else
				Current = Current->next;
		}
	}
	
	if(flag==0)
		printf("The value after which the node has to be deleted does not exist!");
	else
	{
		if(Current==end)
		{
			printf("There is No Node before this Node!!!");
		}
		else if(Current->next->next == NULL)
		{
			Current->next->prev = NULL;
			Current->next=NULL;
			end=Current;
		}
		else
		{
			Current->next->prev = NULL;
			Current->next=Current->next->next;
			Current->next->prev->next = NULL;
			Current->next->prev = Current;
		}
		Current=NULL;
	}
	return start;
}


struct node *DelAll (struct node *head){
	struct node *temp;
		while (start != NULL)
		{
			temp = start;
			start= start->next;
			printf ("PHP %d will be deleted \n", temp->num);
			free (temp);
		}
			printf ("\n ******** OPERATION: Delete entire list of Daily Expenses ******** \n");
			printf("\n The entire list have been deleted.");
		return head;  
}


void display(int m)
{
    struct node * tmp;
    int n = 1;
    if(start == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = start;
        if (m==1)
        {
        printf("\n Data entered in the list are :\n");
        }
        else
        {
         printf("\n After insertion the new list are :\n");   
        }
        while(tmp != NULL)
        {
            printf(" The amount value %d : %d \n", n, tmp->num);
            n++;
            tmp = tmp->next; 
        }
    }
}
