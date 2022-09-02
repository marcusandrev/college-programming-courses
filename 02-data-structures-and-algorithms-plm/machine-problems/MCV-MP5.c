#include<stdio.h>
#include<conio.h>
#include<windows.h>

typedef struct Student{
	char studentNumber[12];
	char studentName[24];
	char courseAndYear[10];
	float gwa;
	struct Student* prev;
	struct Student* next;
}Record;

Record *HEAD, *TAIL, *newStudent;

int main(){
	int option;
    printf("\n ***** This program shows the List of student records ***** \n");
    printf(" -------------------------------------------------------------------\n");	 	 	   	

    //STATEMENTS FOR THE MAIN MENU
     do{
        	
    	printf (" \n What do you want to do with your list? \n\n");
    	printf (" \tNo.1: Create Student Record \n");
	    printf (" \tNo.2: Display Student Record \n");
	    printf (" \tNo.3: Add A Student Record After A Given Record \n");
	    printf (" \tNo.4: Delete A Student Record Before A Given Record \n");
	    printf (" \tNo.5: Exit The Program \n");

	// switch statement for the main menu options and connect it to their respective functions
	    printf("\n\n Enter your option : ");
	    scanf("%d", &option);
	    switch(option) {    
	    	case 1: 
				createRecord();
		    	break;
		    case 2:
		    	topToBot();
				break;
			case 3:
				addNode();
				break;
			case 4:
				delNode();
				break;
			case 5:
				printf("\n Program Terminated");
				exit(0);   	    	    		     
		}
		printf("\n\n Press any key to make another operation ... \n\n");
		getch();
	}while(option < 6);
	printf("\n Wrong Operation Number ");
		printf("\n Program Terminated ");
	getch();
	
	return 0;
}



void createRecord(){
	int i, studs;
	Record *prev, *next;
	newStudent = (Record*)malloc(sizeof(Record));
  	HEAD = newStudent;
  	TAIL = newStudent;
  	HEAD->next = NULL;
  	HEAD->prev = NULL;
	
	printf(" \n How many student records do you want to input? : ");
	scanf("%d", &studs);
	printf("\n -------------------------------------------------------------------\n");

	
	for(i = 0; i < studs; i++){
	
		printf("\n STUDENT RECORD no. %d: \n", i+1);
		
		printf("\t Enter the student number of Student no. %d: ", i+1);
		scanf("%s", &newStudent->studentNumber);
		
		printf("\t Enter the name of Student no. %d: ", i+1);
		scanf("%s", &newStudent->studentName);
		
		printf("\t Enter the course and year of Student no. %d: ", i+1);
		scanf("%s", &newStudent->courseAndYear);
		
		printf("\t Enter the GWA of Student no. %d: ", i+1);
		scanf("%f", &newStudent->gwa);
		
		if(i == (studs - 1)){
			break;
		}
		
		newStudent->next = (Record*)malloc(sizeof(Record));
		prev = newStudent;
		next = newStudent->next;
		
		next->prev = prev;
		
		newStudent = newStudent->next;
		TAIL = newStudent;
	}
	
	TAIL->next=NULL;
   	newStudent=NULL;
	printf("\n -------------------------------------------------------------------");

}

void topToBot(){
	Record *traverseRec;
	traverseRec = HEAD;
	
	printf("\n -------------------------------------------------------------------\n\n");
	printf(" CURRENT STUDENT RECORD DISPLAYED FROM TOP TO BOTTOM \n\n");
	
	if(traverseRec == NULL){
		printf("No data found in the List yet!");
	} else {
		while(traverseRec != NULL){
		
		printf("\t Student Number: ");
		printf("%s \n", traverseRec->studentNumber);
		
		printf("\t Student Name: ");
		printf("%s \n", traverseRec->studentName);
		
		printf("\t Course and Year: ");
		printf("%s \n", traverseRec->courseAndYear);
		
		printf("\t GWA: ");
		printf("%.2f \n", traverseRec->gwa);
		printf("\n");
		traverseRec = traverseRec->next;
	}
		
	}
	printf(" -------------------------------------------------------------------");
	 
}


void addNode(){
	Record *Current, *prev, *next;
	char afterRecord[12];
	newStudent = (Record*)malloc(sizeof(Record));
	int Flag = 0;
	Current = HEAD;
	
	printf("\n-------------------------------------------------------------------\n");
	printf("\n INSERT STUDENT RECORD TO BE ADDED AT THE END \n\n");
	
	printf("\t Enter the student number of the student: ");
	scanf("%s", &newStudent->studentNumber);
		
	printf("\t Enter the name of the Student: ");
	scanf("%s", &newStudent->studentName);
		
	printf("\t Enter the course and year of the Student: ");
	scanf("%s", &newStudent->courseAndYear);
		
	printf("\t Enter the GWA of the Student: ");
	scanf("%f", &newStudent->gwa);
		
	printf("\n -------------------------------------------------------------------");
	
	newStudent->prev = NULL;
	newStudent->next = NULL;

	printf("\n\n\tEnter the Student Number you wish to add the new record after : ");
	scanf("%s", &afterRecord);
	
	if(Current == NULL){
		printf("Double Linked List is empty");
	}else {
		while(Flag==0 && Current!=NULL){
			if(strcmp(Current->studentNumber,afterRecord) == 0)
				Flag=1;
			else
				Current=Current->next;
		}
		
		if(Flag==0){
			printf("The Value where the NewNode will be inserted before does not exist");
		}else {
			if(Current ==  TAIL){
				newStudent->prev=TAIL;
				TAIL->next=newStudent;
				TAIL=newStudent;
			}else {
				newStudent->next=Current->next;
				newStudent->prev=Current;
				next = Current->next;
				prev = next->prev;
				prev = newStudent;				
				Current->next=newStudent;
				
			}
			Current=NULL;
			newStudent=NULL; 
		}
		}
		
	printf("\n\t NEW RECORD OF STUDENT WAS ADDED AFTER STUDENT NUMBER %s RECORD... \n", afterRecord);
	printf("\n -------------------------------------------------------------------");		
}

void delNode(){
	Record *Current, *prev, *next;
	char beforeVal[12];
	newStudent = (Record*)malloc(sizeof(Record));
	int Flag = 0;
	Current = HEAD;
	
	printf("\n -------------------------------------------------------------------\n");
	
	newStudent->prev = NULL;
	newStudent->next = NULL;

	printf("\n\n\tEnter the Student Number you wish to delete before the record : ");
	scanf("%s", &beforeVal);
	
	if(Current == NULL){
		printf("Double Linked List is empty");
	}else {
		while(Flag==0 && Current!=NULL){
			if(strcmp(Current->studentNumber,beforeVal) == 0)
				Flag=1;
			else
				Current=Current->next;
		}
		
		if(Flag==0){
			printf("The Value where the NewNode will be inserted before does not exist");
		}else {
			if(Current ==  HEAD->studentNumber){
			printf("There is no record before this record");
			}else if (Current->prev->prev == NULL) {
				Current->prev->next;
				Current->prev = NULL;
				HEAD = Current;
				
			} else {
			Current->prev->next = NULL;
			Current->prev=Current->prev->prev;
			Current->prev->next->prev = NULL;
			Current->prev->next = Current;
				
			}
			Current=NULL; 
		}
		}
		
	printf("\n\t STUDENT NUMBER %s RECORDS WAS DELETED... \n", beforeVal);
	printf("\n -------------------------------------------------------------------");

}