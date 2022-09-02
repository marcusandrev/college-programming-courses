// Group 1 Block 2 Queues

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf ("\nEnter Number of Students: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        printf("\tStudent No.: "); 
        scanf("%s",&tmp->no); 
	    scanf("%c", &temp);
	    printf("\tStudent Name: "); 
	    gets(tmp->name); 
	    printf("\tCourse and Year: "); 
	    gets(tmp->crsyr);
	    printf("\tGWA: ");
		scanf("%f",&tmp->gwa);
		printf("\n");
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
    	printf("Queue is not Allocated\n");
    	return;
	}
    printf("\tStudent No.: "); 
    scanf("%s",&tmp->no); 
    scanf("%c", &temp);
	printf("\tStudent Name: "); 
	gets(tmp->name); 
	printf("\tCourse and Year: "); 
	gets(tmp->crsyr);
	printf("\tGWA: ");
	scanf("%f",&tmp->gwa);
	printf("\n");
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
		printf("The Queue is Empty!");
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
		printf("\nThe queue is empty!\n");
	else { 
		flag = front -> data;
		printf("Elements in Queue: ");
		do{
			printf("\nStudent No.: %s\n",travNode->no); 
        	printf("Student name: %s\n",travNode->name); 
        	printf("Course and Year: %s\n",travNode->crsyr); 
        	printf("GWA: %.2f\n\n",travNode->gwa);
			front = travNode->next;
			travNode->next = NULL;
			rear->next = travNode;
			rear = rear->next;
			travNode = front;
		} while (flag != front->data);
		travNode = NULL;
	}
	printf("\n");
}

void travWithRep(struct node *front){
    struct node *travNode, *tFront, *tRear, d;
    travNode = front;
    tFront = NULL; tRear = NULL;
    if (travNode == NULL) {
        printf("\nThe queue is empty!\n");
    }
    else {
        printf("Elements in Queue: ");
        do {
            printf("\nStudent No.: %s\n",travNode->no); 
        	printf("Student name: %s\n",travNode->name); 
        	printf("Course and Year: %s\n",travNode->crsyr); 
        	printf("GWA: %.2f\n\n",travNode->gwa);
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
	printf("\t1-CREATION\n\t2-TRAVERSAL (WITH REPEATING DATA)\n\t3-TRAVERSAL (WITH NO REPEATING DATA)\n\t4-ADDING\n\t5-DELETION\n\t6-EXIT\n");
	printf("Enter choice: ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1: if (front!=NULL){
				printf("Unable to allocate memory.\n");
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
					printf("Unable to allocate memory.\n");
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
				
		default:printf ("Invalid!\n");
				system("pause");
				system ("cls");
				main();
				break;
	}
	return 0;
}
