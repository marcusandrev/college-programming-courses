// Marcus Andre Villanueva
// BS Computer Science Irregular
// MP3 - Retrieval of records and declaration of winners

#include<stdio.h>
#include<conio.h>
#include<windows.h>

typedef struct  {
	
	int userData[5];  
	char candidates[50];
	int totalVotes;
	float totalPercentage;
	
}votes;

void gotoxy(int x, int y);    //gotoxy boilerplate

int main()
{	

	FILE *VOTERECORD;
	votes Name[4], TEMPREC;

	int i, j, k;
	int sumOfVotes = 0;
	float champion = 0;
	float second = 0;
	int championIndex = 0;
	int secondIndex = 1;
	float temp = 0;
	float totalPercentageArray[4] = {};
	char FName[15];
	
	gotoxy(3,4); printf("Enter the file name of the records you want to retrieve (e.g. fileName.dat) : ");
  	scanf("%s", FName);
  	gotoxy(3,6);printf("Retrieving records from %s",FName);
	
	VOTERECORD=fopen(FName,"r"); 
	
	k=0;
	fread(&TEMPREC,sizeof(TEMPREC),1,VOTERECORD); 
	while(!feof(VOTERECORD))
		{
			Name[k]=TEMPREC;
			fread(&TEMPREC,sizeof(TEMPREC),1,VOTERECORD); 
			k++;
		}
	fclose(VOTERECORD);
	
	gotoxy(3,7);printf("There are %d records retrieved!",k);
  	gotoxy(3,9);printf("Press Any Key To Display the File...");
  	getch();
  	system("cls");
	
	
	gotoxy(35, 1);printf("TALLY OF VOTE PER PRECINCT");
	gotoxy(4,4); printf("Precincts");
	gotoxy(18,3); printf("Candidate");
	gotoxy(34,3); printf("Candidate");
	gotoxy(50,3); printf("Candidate");
	gotoxy(66,3); printf("Candidate");
	
	// for loop to print the number 1 - 5 vertical in precincts
	for(i=1; i<=5; i++){
		gotoxy(8, i+5); printf("%d", i);
	}
	
	// for loop to get candidate names from the user
	for(i=0; i<=3; i++){
		gotoxy((16*i)+20, 4); printf("%s", Name[i].candidates);
	}
	
	// for loop to get the number of votes for each candidate from the user 
	for (i=0; i<=3; i++){   
		for (j=0; j<=4; j++){
			gotoxy((16*i)+20, 6+j);printf("%d", Name[i].userData[j]);
		}
	}
	
	gotoxy(4, 13);printf("Total:");
	gotoxy(4, 14);printf("Percentage:");
	
	// init of total Votes
	Name[0].totalVotes = 0;
	Name[1].totalVotes = 0;
	Name[2].totalVotes = 0;
	Name[3].totalVotes = 0;

	// printing of total votes of each candidate
	for (i=0; i<=3; i++){   
		for (j=0; j<=4; j++){
			Name[i].totalVotes += Name[i].userData[j];
			gotoxy((16*i)+20,13); printf("%d", Name[i].totalVotes);                                            
		}
	}
	
	// computation of total votes 
	for (i=0; i<=3; i++){   
		sumOfVotes += Name[i].totalVotes;
		gotoxy(83,13); printf("Sum of votes: %d", sumOfVotes); //remove this later
	}
	
	// computation of percentages and printing of tatal percentages of each candidate
	for (i=0; i<=3; i++){ 
		Name[i].totalPercentage = ((float)Name[i].totalVotes/sumOfVotes)*100;
		gotoxy((16*i)+20,14); printf("%.2f %%", Name[i].totalPercentage);
		totalPercentageArray[i] = Name[i].totalPercentage;
	}
		
	// setting the first and second percentages indexes
	champion = totalPercentageArray[0];
	second = totalPercentageArray[1];
		
	// arranging first and second percentages
	if (champion < second){
		temp = champion;
		champion = second;
		second = temp;
		championIndex = 1;
		secondIndex = 0;
	}
	
	// checking if there are percentages greater than the first or second percentages	
	for (i=2; i<=3; i++){
		if (totalPercentageArray[i] > champion){
			secondIndex = championIndex;
			second = champion;
			champion = totalPercentageArray[i];
			championIndex = i;
		} else if (totalPercentageArray[i] > second && totalPercentageArray[i] != champion ){
			second = totalPercentageArray[i];
			secondIndex = i;
		} 
	}
		
	// declaration of winners
		if(Name[championIndex].candidates > 50){
			gotoxy(4,16);printf("RESULT: Candidate %s won! \n", Name[championIndex].candidates);
		} else {
			gotoxy(4,16);printf("RESULT: Candidates %s and %s have the two highest votes respectively. \n", Name[championIndex].candidates, Name[secondIndex].candidates);
		}

	return 0;
}

void gotoxy(int x, int y)   //gotoxy boilerplate                                              
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}