#include<stdio.h>
#include<conio.h>
#include<windows.h>

typedef struct{
	char studentNumber[12];
	char studentName[24];
	char courseAndYear[10];
	float gwa;
	struct Student *next;
}Record;

Record *student, *newStudent;

int main(){
	int option;
    printf("\n ***** This program shows the List of student records ***** \n");
    printf(" -------------------------------------------------------------------\n");	   	

    //STATEMENTS FOR THE MAIN MENU
     do{
        	
    	printf (" \n What do you want to do with your list? \n\n");
    	printf (" \tNo.1: Create Student Record \n");
	    printf (" \tNo.2: Display Student Record \n");
	    printf (" \tNo.3: Add A Student Record At The End \n");
	    printf (" \tNo.4: Delete A Specified Student Record \n");
	    printf (" \tNo.5: Exit The Program \n");

	// switch statement for the main menu options and connect it to their respective functions
	    printf("\n\n Enter your option : ");
	    scanf("%d", &option);
	    switch(option) {    
	    	case 1: 
				createRecord();
		    	break;
		    case 2:
		    	traverseRecord();
				break;
			case 3:
				addNode();
				break;
			case 4:
				DelNode();
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
	student = NULL;
	newStudent = (Record*)malloc(sizeof(Record));
  	student = newStudent;
	
	printf(" \n How many student records do you want to input? : ");
	scanf("%d", &studs);
	printf("\n-------------------------------------------------------------------\n");

	
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
		newStudent = newStudent->next;
	}
	newStudent->next=NULL;
   	newStudent=NULL;
	printf("\n-------------------------------------------------------------------");
}

void traverseRecord(){
	Record *traverseRec;
	traverseRec = student;
	
	printf("\n-------------------------------------------------------------------\n\n");
	printf(" CURRENT STUDENT RECORD \n\n");
	
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
		traverseRec = traverseRec->next;
		
		printf("\n");
	}
		
	}
	printf("-------------------------------------------------------------------");
	 
}

void addNode(){
	Record *lastRec;
	newStudent = (Record*)malloc(sizeof(Record));
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
		
	printf("\n-------------------------------------------------------------------");
	
	if(newStudent == NULL){
		printf("Unable to allocate memory.");
	}else {
		
		newStudent->next = NULL;
		lastRec = student;
		
		while(lastRec->next != NULL)
		{
			lastRec = lastRec->next;
		}
	
		lastRec->next = newStudent;
		newStudent = NULL;
		lastRec = NULL;	
		}
}

void DelNode(){
	char delVal[12];
	Record *DelNode, *Previous;
	Previous = NULL;
	DelNode = student;
	
	printf("\n-------------------------------------------------------------------\n");
	printf("\n Enter the Student Number for the record you wish to delete: ");
	scanf("%s", &delVal);
	
	if(strcmp(DelNode->studentNumber,delVal) == 0){
		student = student->next;
		free(DelNode);
		DelNode = NULL;
	}else {
		while(DelNode != NULL){
			while(strcmp(DelNode->studentNumber,delVal) == 0){
				if(Previous != NULL){
					Previous->next = DelNode->next;
				}
				
				free(DelNode);
				break;

			}
			Previous = DelNode;
			DelNode = DelNode->next;
			}
		}		
	Previous = NULL;
	printf("\n\t STUDENT NUMBER %s RECORDS WAS DELETED... \n", delVal);
	printf("\n-------------------------------------------------------------------");	
	}
	