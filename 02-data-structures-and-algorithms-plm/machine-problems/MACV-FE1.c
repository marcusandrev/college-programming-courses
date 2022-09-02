#include<stdio.h>
#include<conio.h>
#include<windows.h>

typedef struct{
	int productNo;
	char productName[15];
	float unitPrice;
	int quantity;
	float totalPrice;
	struct List *next;
}Shopping;

Shopping *list, *newList;
int numOfRecords = 1;

void gotoxy(short x, short y);

int main(){
	    int option;

    printf("\n ***** This program shows the List of your summary of products ***** \n");
    printf("-------------------------------------------------------------------\n");	   	

    
    //STATEMENTS FOR THE MAIN MENU
     do{
        	
    	printf (" \n What do you want to do with your list? \n");
    	printf (" No.1: Create List of your summary of products \n");
	    printf (" No.2: Display List of your summary of products \n");

	// switch statement for the main menu options and connect it to their respective functions
	    printf("\n\n Enter your option : ");
	    scanf("%d", &option);
	    switch(option) {    
	    	case 1:
//				system("cls"); 
				createRecord();
//				system("cls");
		    	break;
		    case 2:
		    	system("cls");
		    	traverseRecord();
//		    	system("cls");
				break;	    	    		     
		}
		printf("\n\n Press any key to make another operation ... \n\n");
		getch();
	}while(option < 3);
	printf("\n Wrong Operation Number ");
		printf("\n Program Terminated ");
	getch();
	system("cls");
	


	return 0;
}



void createRecord(){
	
	int i, recordLength;
	
	list = NULL;
	newList = (Shopping*)malloc(sizeof(Shopping));
  	list = newList;
	
	printf(" How many products do you want to input? : ");
	scanf("%d", &recordLength);
	printf("\n-------------------------------------------------------------------\n\n");

	numOfRecords = recordLength;
	
	for(i = 0; i < recordLength; i++){
	
		
		printf("\t Enter the Product Number: ");
		scanf("%d", &newList->productNo);
		
		printf("\t Enter the Product Name: ");
		scanf("%s", &newList->productName);
		
		printf("\t Enter the Unit Price: ");
		scanf("%f", &newList->unitPrice);
		
		printf("\t Enter the Qty: ");
		scanf("%d", &newList->quantity);
		
		newList->totalPrice = (newList->unitPrice * newList->quantity)*1.12;
		
		printf("\n\n");
		
		if(i == (recordLength - 1)){
			break;
		}
		
		newList->next = (Shopping*)malloc(sizeof(Shopping));
		newList = newList->next;
	}
	
	newList->next=NULL;
   	newList=NULL;
   	


}

void traverseRecord(){
	
	
	int i = 0;  // remove to ata
	Shopping *traverseRec;
	
	traverseRec = list;

	gotoxy(35, 1);printf("LIST OF YOUR SUMMARY OF PRODUCTS");
	gotoxy(9,3); printf("Product No.");
	gotoxy(23,3); printf("Product Name");
	gotoxy(39,3); printf("Unit Price");
	gotoxy(56,3); printf("Qty");
	gotoxy(69,3); printf("Total Price");
	
	
	if(traverseRec == NULL){
		printf("No data found in the List yet!");
	} else {
		while(traverseRec != NULL){
			
        printf("\n");
        printf("\n");
	
		printf("\t %d \t", traverseRec->productNo);
		
	
		printf("\t %s \t", traverseRec->productName);
		

		printf("\t %.2f \t", traverseRec->unitPrice);
		

		printf("\t %d \t", traverseRec->quantity);
		
		
		printf("\t %.2f \t", traverseRec->totalPrice);
		
		printf("\n");

		

		traverseRec = traverseRec->next;
	}
		
	}
	 
}

void gotoxy(short x, short y){
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}






