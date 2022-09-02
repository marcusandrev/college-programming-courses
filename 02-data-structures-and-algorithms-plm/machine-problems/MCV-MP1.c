#include<stdio.h>
#include<windows.h>
#include<conio.h>

int userData[4][5] = {};  
char candidates[4] = {'A','B','C','D'};
int i,j,k,l;
int totalA = 0;	
int totalB = 0;	
int totalC = 0;	
int totalD = 0;
int totalE = 0;		
int totalVotesArray[5] = {};
float totalPercentageArray[5] = {};
int sumOfVotes = 0;
float fiftyPercent = 50.00;
float a;

void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void table(){
    gotoxy(20,1);printf("Candidate");
    gotoxy(36,1);printf("Candidate");
    gotoxy(52,1);printf("Candidate");
    gotoxy(68,1);printf("Candidate");

    gotoxy(1,2);printf("Precincts");
    gotoxy(23,2);printf("A");
    gotoxy(39,2);printf("B");
    gotoxy(55,2);printf("C");
    gotoxy(71,2);printf("D");

    gotoxy(4,4);printf("1");
    gotoxy(4,5);printf("2");
    gotoxy(4,6);printf("3");
    gotoxy(4,7);printf("4");
    gotoxy(4,8);printf("5");
    gotoxy(2,10);printf("Total:");
    gotoxy(2,11);printf("Percentage:");
}

int main(){



system("cls");
table();


for (i=0; i<4; ++i){   
	for (j=0; j<5; j++){
		gotoxy(23+i*16, 4+j);scanf("%d", &userData[i][j]);
		
	}
}


//Computes Total Values
for (i=0; i<5; i++){
	totalA += userData[0][i];
}

for (i=0; i<5; i++){
	totalB += userData[1][i];
}

for (i=0; i<5; i++){
	totalC += userData[2][i];
}

for (i=0; i<5; i++){
	totalD += userData[3][i];
}



//put each Total to an array
totalVotesArray[0] = totalA;
totalVotesArray[1] = totalB;
totalVotesArray[2] = totalC;
totalVotesArray[3] = totalD;


//sum of votes formula
sumOfVotes = totalA + totalB + totalC + totalD;
printf("Sum of votes: %d", sumOfVotes);

//prints Total
for (i=0; i<4; i++){
	gotoxy(23+i*16, 10);printf("%d", totalVotesArray[i]);
}


//compute Percentages
for (i=0;i<4;i++){
	float a = totalVotesArray[i];
	float percentage = (a/sumOfVotes)*100;
	totalPercentageArray[i] = percentage;
}

//print Percentages
for (i=0; i<4; i++){
	gotoxy(23+i*16, 11);printf("%.2f %%", totalPercentageArray[i]);
}

int champ = 0;
int second = 0;

//Determining the Champion
for (i=0; i<4; i++){
	if(totalPercentageArray[i]>totalPercentageArray[champ]){
		champ = i;
	}
}

//Determining the Second Highest

for (i=1; i<4; i++){
	if(i == champ){
	continue;
	}
	if(totalPercentageArray[i]>totalPercentageArray[second]){
		second = i;
	}
}


if (totalPercentageArray[champ]>fiftyPercent) {
	gotoxy(2,13);printf("Result: Candidate %c won", candidates[champ]);
} else {
	gotoxy(2,14);printf("Result: Candidate %c and Candidate %c had the two highest votes", candidates[champ], candidates[second]);
}


    getch();
    return 0;
}
