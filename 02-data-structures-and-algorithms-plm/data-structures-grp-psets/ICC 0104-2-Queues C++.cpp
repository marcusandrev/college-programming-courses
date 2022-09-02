#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct node
{
    char no[12];
	char name[24];
	char crsyr[10];
	float gwa;
    struct node *next;
    int data;
};

struct node *front=NULL, *rear=NULL;
void creation()
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    int n,i;
    char temp;
    cout<<("\nEnter Number of Students: ");
    cin>>n;
    for(i=0;i<n;i++)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        cout<<"\tStudent No.: "; 
        cin>>tmp->no; 
	    cout<<"\tStudent Name: "; 
	    cin>>tmp->name; 
	    cout<<"\tCourse and Year: "; 
	    cin>>tmp->crsyr;
	    cout<<"\tGWA: ";
		cin>>tmp->gwa;
		cout<<"\n";
    	tmp->next=NULL;
    
    if(front==NULL){
    	front=tmp;
	}
	else{
		rear->next=tmp;
	}
	rear=tmp;
	}
}

void add()
{
    struct node *tmp;
    char temp;
    tmp=(struct node*)malloc(sizeof(struct node));
    if (tmp==NULL){
    	cout<<"Queue is not Allocated\n";
    	return;
	}
    cout<<"\tStudent No.: "; 
    cin>>tmp->no; 
	cout<<"\tStudent Name: "; 
	cin>>tmp->name; 
	cout<<"\tCourse and Year: "; 
	cin>>tmp->crsyr;
	cout<<"\tGWA: ";
	cin>>tmp->gwa;
	cout<<"\n";
    tmp -> next = NULL;
	if(front==NULL){
    	front=tmp;
    	rear = tmp;
    	front -> next = NULL;
    	rear -> next = NULL;
	}
	else{
		rear->next=tmp;
		rear = tmp;
		rear->next = NULL;
	}
//	rear=tmp;
}

void del(){
	struct node *DelNode;
	DelNode = front;
	if (DelNode == NULL) {
		cout<<"The Queue is Empty!";
	} else {
		front = front -> next;
		DelNode->next = NULL;
		free(DelNode);
		DelNode = NULL;
	}
}

void travNoRep(){
	struct node *travNode;
	int flag;
	travNode = (struct node *) malloc (sizeof(struct node));
	travNode = front;
	if (travNode == NULL)
		cout<<"\nThe queue is empty!\n";
	else { 
		flag = front -> data;
		cout<<"Elements in Queue: ";
		do{
			cout<<"\nStudent No.: "<<travNode->no<<"\n"; 
        	cout<<"Student name: "<<travNode->name<<"\n"; 
        	cout<<"Course and Year: "<<travNode->crsyr<<"\n"; 
        	cout<<"GWA: "<<travNode->gwa<<"\n\n"; //idk pano gawing 2 decimal lang
			front = travNode->next;
			travNode->next = NULL;
			rear->next = travNode;
			rear = rear->next;
			travNode = front;
		} while (flag != front->data);
		travNode = NULL;
	}
	cout<<"\n";
}

void travWithRep(struct node *front){
    struct node *travNode, *tFront, *tRear, d;
    travNode = front;
    tFront = NULL; tRear = NULL;
    if (travNode == NULL) {
        cout<<"\nThe queue is empty!\n";
    }
    else {
        cout<<"Elements in Queue: ";
        do {
            cout<<"\nStudent No.: "<<travNode->no<<"\n"; 
        	cout<<"Student name: "<<travNode->name<<"\n"; 
        	cout<<"Course and Year: "<<travNode->crsyr<<"\n"; 
        	cout<<"GWA: "<<travNode->gwa<<"\n\n";
        	front = travNode->next;
        	if(front==NULL) rear = NULL;
            if (tFront == NULL) tFront = travNode;
            else tRear = travNode;
            tRear = travNode;
            travNode = front;
        }while (front != NULL);
        front = tFront;
        rear = tRear;
    }
    tFront = NULL; tRear = NULL; travNode = NULL;
}

int main()
{
    char no1[12];
	char name1[24];
	char crsyr1[10];
	float gwa1;
	char temp;
	int choice;
	cout<<"\t1-CREATION\n\t2-TRAVERSAL (WITH REPEATION)\n\t3-TRAVERSAL (NO REPEATION)\n\t4-ADDING\n\t5-DELETION\n\t6-EXIT\n";
	cout<<"Enter choice: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1: if (front!=NULL){
				cout<<"Unable to allocate memory.\n";
				}
				else{
				creation();
				}
				system("pause");
				system("cls");
				main();
				break;
				
		case 2: travWithRep(front);
				system("pause");
				system ("cls");
				main();
				break;
		
		case 3: travNoRep();
				system("pause");
				system ("cls");
				main();
				break;
		
		case 4: if (front==NULL)
					cout<<"Unable to allocate memory.\n";
				else
					add();
				system("pause");
				system("cls");
				main();
				break;
				
		case 5: 
				del();	
        		system("pause");
				system("cls");
				main();
				break;
				
		case 6: exit(0);
				
		default:cout<<"Invalid!\n";
				system("pause");
				system ("cls");
				main();
				break;
	}
	return 0;
}