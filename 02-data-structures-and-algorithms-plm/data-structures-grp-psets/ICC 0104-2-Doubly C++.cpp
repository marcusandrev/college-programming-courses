#include <iostream>
#include <cstdlib>
#include <conio.h>

struct node{
	int num;
	struct node *prev;
	struct node *next;
};

// STRUCTS HERE
struct node *start = NULL;
struct node *end = NULL;
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

void display (int);

int main(){
	int n, num1, head, option;
	
	std::cout<<"\n ***** This program shows the List of your Daily Expenses ***** \n";
	std::cout<<"------------------------------------------------------------------------------------\n";
	
	std::cout<<"\n How many expenses do you want to input? : ";
	std::cin>>n;
	create(n);
	head=1;
	std::cout<<"\n*********LIST OF EXPENSES**********\n";
	display(head);
	
	//STATEMENTS FOR THE MAIN MENU
	do{
		std::cout<<" \n What do you want to do with your list of Daily Expenses? \n";
    	std::cout<<" No.1: Display the list from TOP to BOTTOM  \n";
    	std::cout<<" No.2: Display the list from BOTTOM to TOP  \n";
	    std::cout<<" No.3: Add an amount at the beginning  \n";
	    std::cout<<" No.4: Add an amount at the end \n";
	    std::cout<<" No.5: Add an amount before a given amount \n";
		std::cout<<" No.6: Add an amount after a given amount \n";
	    std::cout<<" No.7: Delete an amount at the beginning \n";
	    std::cout<<" No.8: Delete an amount at the end \n";
	    std::cout<<" No.9: Delete a given amount \n";
	    std::cout<<" No.10: Delete an amount before a given amount \n";
		std::cout<<" No.11: Delete an amount after a given amount \n";
	    std::cout<<" No.12: Delete entire list of Daily Expenses \n";
	    std::cout<<" No.13: Create a new list of Daily Expenses \n";
	    std::cout<<" No.14: EXIT \n";
	    
	    // Switch statement for the main menu options and connect it to their respective functions
	    std::cout<<"\n\n Enter your option : ";
	    std::cin>>option;
	    
	    switch(option){
	    	case 1:
		    	std::cout<<"\n ******** OPERATION:  Display the list from TOP to BOTTOM ******** \n";
		    	display (head);
		    	break;
		    case 2: DispBotToTop (start);
		    	break;
	    	case 3: InsertBeg (start);
		    	std::cout<<"\n ******** OPERATION: Add an amount at the beginning ******** \n";
		    	std::cout<<"\n**********UPDATED LIST OF EXPENSES**********\n";
		    	display (head);
		    	break;
		    case 4: InsertEnd (start);
		    	std::cout<<"\n ******** OPERATION: Add an amount at the end ******** \n";
		    	std::cout<<"\n**********UPDATED LIST OF EXPENSES**********\n";
		    	display (head);
		    	break;
		   	case 5: InsertNodeBefore (start);
		    	std::cout<<"\n ******** OPERATION: Add an amount before a given amount ******** \n";
		    	std::cout<<"\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		    	break;
		   	case 6: InsertNodeAfter (start);
		    	std::cout<<"\n ******** OPERATION: Add an amount after a given amount ******** \n";
		    	std::cout<<"\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		    	break;
		   	case 7: DelBeg (start);
		    	std::cout<<"\n ******** OPERATION: Delete an amount at the beginning ******** \n";
		   		std::cout<<"\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		    	break;
		   	case 8: DelEnd (start);
		    	std::cout<<"\n ******** OPERATION: Delete an amount at the end ******** \n";
		    	std::cout<<"\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		 		break;
		   	case 9: DelNode (start);
		  		std::cout<<"\n ******** OPERATION: Delete a given amount ******** \n";
		   		std::cout<<"\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		   		break;
		   	case 10: DelNodeBefore (start);
		   		std::cout<<"\n ******** OPERATION: Delete an amount before a given amount ******** \n";
		    	std::cout<<"\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		    	break;    
		    case 11: DelNodeAfter (start);
		    	std::cout<<"\n ******** OPERATION: Delete an amount after a given amount ******** \n";
		    	std::cout<<"\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		    	break;
		    case 12: DelAll (start);
		    	display (head);
		    	break;
		    case 13:
			    std::cout<<"\n How many expenses do you want to input? : ";
			    std::cin>>n;
			    create (n);
			    std::cout<<"\n ******** OPERATION: Create a new list of Daily Expenses ******** \n";
			    std::cout<<"\n**********UPDATED LIST OF EXPENSES**********\n";
			    display (head);
		    	break;
		    case 14:
		    	printf("\n Program Terminated");
				exit(0);
		}
	}while(option < 15);
	std::cout<<"\n Wrong Operation Number ";
	std::cout<<"\n Program Terminated ";
	getch();
	
    return 0;
}

struct node *create (int n){
	int i;
	struct node *NewNode;
	
	NewNode = (struct node*)malloc(sizeof(struct node));
	NewNode->prev = NULL;
	NewNode->next = NULL;
	start = NewNode;
	end = NewNode;
	
	for(i=1; i<=n; i++){
		std::cout<<"Enter the amount for your daily expenses no. "<<i<<": PHP : ";
		std::cin>>NewNode->num;
		
		if(i==n){
			NewNode->next = NULL;
		}
		else{
			NewNode->next = (struct node*)malloc(sizeof(struct node));
			NewNode->next->prev = NewNode;
			NewNode = NewNode->next;
			end = NewNode;
		}
	}
	
	NewNode = NULL;
	return start;
}

void display (int m){
	struct node *tmp;
	int n=0;
	if(start == NULL){
		std::cout<<" No data found in the List yet.";
	}
	else{
		tmp = start;
		if (m==1){
        	std::cout<<"\n Data entered in the list are :\n";
        }
        else{
        	std::cout<<"\n After insertion the new list are :\n";   
        }
        while(tmp != NULL){
            std::cout<<" The amount value " << n+1 << ": " << tmp->num <<" \n";
            n++;
            tmp = tmp->next; 
        }
	}
}

struct node *DispBotToTop (struct node *head){
	struct node *TravNode;
    int n = 1;
    TravNode = end;
    if(TravNode == NULL)
    {
        std::cout<<"Double/Doubly Linked List is Empty!";
    }
    else
    {	
    std::cout<<"\n ******** OPERATION: Display the list from BOTTOM to TOP ******** \n";
        do{    
            std::cout<<" The amount value " << n << " = " << TravNode->num << "\n";
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
	    std::cout<<" Enter the amount you want to insert at the start of the list: PHP ";  
		std::cin>>num;
		if(start == NULL) {
		
	        std::cout<<" No data found in the list!\n";
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
	std::cout<<" Enter the amount you want to insert at the end of the list: PHP ";
	std::cin>>num;
	
	NewNode->prev = NULL;
	NewNode->next=NULL;
	    
	    if(end == NULL)
	    {
	   		 std::cout<<" No data found in the list!\n"; 

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
	 	
	 	std::cout<<"\n Enter the value that the amount will be inserted after it: PHP  ";
	    std::cin>>val; 
	    std::cout<<" \n Enter the amount to be inserted:  ";
	    std::cin>>num; 
	    
	    newnode->num = num;
	    
	    newnode->prev=NULL;
	    newnode->next=NULL;
	    
	    current = start;
	    
	    if(current == NULL)
				std::cout<<"The List is Empty!";
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
			std::cout<<"\n The Value where the amount be inserted before does not exist!";
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
 	
 	std::cout<<"\n Enter the value that the amount will be inserted after it: PHP  ";
    std::cin>>val; 
    std::cout<<" \n Enter the amount to be inserted:  ";
    std::cin>>num;  
    
    newnode->num = num;
    
    newnode->prev=NULL;
    newnode->next=NULL;
    
    current = start;
    
    if(current == NULL)
			std::cout<<"The List is Empty!";
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
		std::cout<<"\n The Value where the amount be inserted before does not exist!";
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
	        std::cout<<" Delete is not possible. \n";
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
	        std::cout<<" Delete is not possible. \n";
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
		std::cout<<"\n Enter the amount you want to delete: PHP ";
		std::cin>>delete_val;
		DelNode = start;
		if(DelNode==NULL)
			std::cout<<"Double/Doubly Linked List is Empty!";
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
			std::cout<<"The value to be deleted does not exist!";
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
	std::cout<<"\n Enter the value before which amount to delete before it: PHP ";
	std::cin>>before_val;
	Current = start;
	
	if(Current==NULL)
		std::cout<<"Double/Doubly Linked List is Empty!";
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
		std::cout<<"The value before which the node has to be deleted does not exist!";
	else
	{
		if(Current->num==start->num)
		{
			std::cout<<"There is No Node before this Node!!!";
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
	std::cout<<"\n Enter the value after which amount to delete after it: PHP ";
	std::cin>>after_val;
	Current = start;
	
	if(Current==NULL)
		std::cout<<"Double/Doubly Linked List is Empty!";
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
		std::cout<<"The value after which the node has to be deleted does not exist!";
	else
	{
		if(Current==end)
		{
			std::cout<<"There is No Node before this Node!!!";
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
			std::cout<<"PHP " << temp->num << " will be deleted \n";
			free (temp);
		}
		end = NULL;
			std::cout<<"\n ******** OPERATION: Delete entire list of Daily Expenses ******** \n";
			std::cout<<"\n The entire list have been deleted.";
		return start;  
}
