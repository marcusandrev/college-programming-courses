#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;

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
    cout << "\n ***** This program shows the List of your Daily Expenses ***** \n";
    cout << "\n How many expenses do you want to input? : ";
    cin >> n;
	
    head = create (n);
    
    cout << "\n*********LIST OF EXPENSES**********\n";
    display (head);
    
    do{
        	
    	cout << " \n What do you want to do with your list of Daily Expenses? \n";
	    cout << " No.1: Add an amount at the beginning  \n";
		cout << " No.2: Add an amount at the end \n";
	    cout << " No.3: Add an amount before a given amount \n";
		cout << " No.4: Add an amount after a given amount \n";
	    cout << " No.5: Delete an amount at the beginning \n";
	    cout << " No.6: Delete an amount at the end \n";
	    cout << " No.7: Delete a given amount \n";
	    cout << " No.8: Delete an amount before a given amount \n";
		cout << " No.9: Delete an amount after a given amount \n";
	    cout << " No.10: Delete entire list of Daily Expenses \n";
	    cout << " No.11: Create a new list of Daily Expenses \n";
	    
	    
	    cout << " No.12: EXIT \n";


	    cout << "\n\n Enter your option : ";
	    cin >> option;
	    switch(option) {
	    	case 1: head = AddNode (head);
		    	cout << "\n ******** OPERATION: Add an amount at the beginning ******** \n";
		    	cout << "\n**********UPDATED LIST OF EXPENSES**********\n";
		    	display (head);
		    	break;
		    case 2: head = InsertEnd (head);
		    	cout << "\n ******** OPERATION: Add an amount at the end ******** \n";
		    	cout << "\n**********UPDATED LIST OF EXPENSES**********\n";
		    	display (head);
		    	break;
		   	case 3: head = InsertBef (head);
		    	cout << "\n ******** OPERATION: Add an amount before a given amount ******** \n";
		    	cout << "\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		    	break;
		   	case 4: head = InsertAft (head);
		    	cout << "\n ******** OPERATION: Add an amount after a given amount ******** \n";
		    	cout << "\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		    	break;
		   	case 5: head = DelBeg (head);
		    	cout << "\n ******** OPERATION: Delete an amount at the beginning ******** \n";
		   		cout << "\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		    	break;
		   	case 6: head = DelEnd (head);
		    	cout << "\n ******** OPERATION: Delete an amount at the end ******** \n";
		    	cout << "\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		 		break;
		   	case 7: head = DelNod (head);
		  		cout << "\n ******** OPERATION: Delete a given amount ******** \n";
		   		cout << "\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		   		break;
		   	case 8: head = DelBefore (head);
		   		cout << "\n ******** OPERATION: Delete an amount before a given amount ******** \n";
		    	cout << "\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		    	break;    
		    case 9: head = DelAfter (head);
		    	cout << "\n ******** OPERATION: Delete an amount after a given amount ******** \n";
		    	cout << "\n**********UPDATED LIST OF EXPENSES**********\n";
				display (head);
		    	break;
		    case 10: head = DelAll (head);
		    	cout << "\n ******** OPERATION: Delete entire list of Daily Expenses ******** \n";
		    	display (head);
		    	break;
		    case 11:
			    cout << "\n How many expenses do you want to input? : ";
			    cin >> n;
			    head = create (n);
			    cout << "\n ******** OPERATION: Create a new list of Daily Expenses ******** \n";
			    cout << "\n**********UPDATED LIST OF EXPENSES**********\n";
			    display (head);
		    	break;
		    case 12:
		    	cout << "\n Program Terminated";
				exit(0);   	    	    		     
		}
		cout << "\n\n Press any key to make another operation ... \n\n";
		getch();
	}while(option < 13);
	cout << "\n Wrong Operation Number ";
		cout << "\n Program Terminated ";
	getch();

    return 0;
}

struct node *create (int n){
    int i;
    struct node *head = NULL;
    struct node *ptr,*NewNode;

    for (i = 0; i < n ;i++){
		
        NewNode = (struct node*)malloc(sizeof(struct node*));
		
        cout << "Enter the amount for your daily expenses no. " << i+1 <<": PHP : ";
        cin >> NewNode -> data;
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
        cout << "The linked list is empty.";
    }
	else{
		
        ptr = head;
        while (ptr != NULL){
            cout << "\t The amount value = "<< ptr -> data << endl;
            ptr = ptr -> next;
        }
    }
}


struct node *AddNode (struct node *head){
	int data;
	struct node *NewNode;
	
	cout << "\n\n Enter the amount you want to insert at the start of the list: PHP ";
    cin >> data;
	
	NewNode = (struct node*)malloc(sizeof(struct node*));
    
    
    if(NewNode == NULL)
    {
        cout << "Unable to allocate memory.";
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
	
	cout<<"\n \n Enter the amount you want to insert at the end of the list: PHP ";
	cin>>data;

	NewNode = (struct node*)malloc(sizeof(struct node));

	if (NewNode == NULL)
	{
		cout<<"Unable to allocate memory.";
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
	
    cout<<"\n Enter the value that the amount will be inserted before it: PHP ";
    cin>>no1;
    
    NewNode = (struct node*)malloc(sizeof(struct node));
    
    cout<<"\n Enter the amount to be inserted: ";
    cin>>NewNode->data;
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
		
		cout<<"\n Enter the value that the amount will be inserted after it: PHP ";
    	cin>>no1;
    	NewNode = (struct node*)malloc(sizeof(struct node));
    
   		cout<<"\n Enter the amount to be inserted: ";
    	cin>>data;
    	
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
        cout << "The Daily Expenses List is empty.";
    }
    else
    {
        del_start = head;
        head = head->next;
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
	    
    cout<<"\n\n Enter the amount you want to delete: PHP ";
    cin>>del; 
    
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

    cout<<"\n Enter the value before which amount to delete before it: PHP ";
    cin>>DelVal;
	
    if (head == NULL){
        cout<<"\n No amount available to delete!";
    }
	
    else if (head -> next == NULL){
        cout<<"No any previous amount available to delete!";
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
            cout<<"No any previous amount available to delete!";
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
		 	
    	cout<<"\n Enter the value after which amount to delete after it: PHP ";
    	cin>>DelVal;
    	
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
	 cout << temp->data<< "will be deleted \n";
	 head = DelBeg(temp);
	 temp = head;
	}
    }	
		return head;
}

