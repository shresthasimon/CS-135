//
// Title: project5.c.c
// Purpose: displays the total number of times each digit appears in the array.
// Author: Simon Shrestha
//

#include <stdio.h>

int main(void){

int row, col, i, j, k; 
int array[100][100];
int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int freq[10];
int count = 0;

printf("\nThis program counts occurrences of digits 0 through 9 in an NxM array\n");

printf("Enter the size of your array: ");
scanf("%d %d", &row, &col);
// input for the 2D array
for(i = 0;i < row;i++){
	printf("Enter row %d: ", i);
	for(j = 0; j < col; j++){
		scanf("%d", &array[i][j]);
	}
}

for(i = 0;i < row;i++){
	for(j = 0; j < col; j++){
		switch(array[i][j]){
			case 0: freq[0]++;
					break;
			case 1: freq[1]++;
					break;
			case 2: freq[2]++;
					break;
			case 3: freq[3]++;
					break;
			case 4: freq[4]++;
					break;
			case 5: freq[5]++;
					break;
			case 6: freq[6]++;
					break;
			case 7: freq[7]++;
					break;
			case 8: freq[8]++;
					break;
			case 9: freq[9]++;
					break;
			default: printf("Unkown number.");
				
		}
			
	}
}

printf("\nTotal count for each digit: \n");
for(i = 0;i < 10;i++){
	if(freq[i] != 1){
	printf("Digit %d occurs %d times\n", num[i], freq[i]);		
	}else{
	printf("Digit %d occurs %d time\n", num[i], freq[i]);
	}
}

return 0;
}
