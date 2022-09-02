#include<stdio.h>
#include<conio.h>
#include<windows.h>

int main()
{	
	int n, slow = 0, fast = 0, i,j;

	
	printf("What is your integer? ");
	scanf("%d",&n);
	
	
	for(i = 0; i < n; i++){
		slow += n;
	}
	fast = (n*(n+1))/2;

	
	printf("Slow = %d", slow);
	printf("\n");
	printf("Fast = %d", fast);
	printf("\n");
	if (slow == fast) {
		printf("They are equal");
	}else {
		printf("They are not equal");
	}
	
	
	
	
	return 0;
	

}


