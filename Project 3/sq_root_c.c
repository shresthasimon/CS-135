//
// Title: sq_root_c.c
// Purpose: Calculates the square root of a number.
// Author: Simon Shrestha
//

#include <stdio.h>
#include <math.h>

int main(void){

float n, oldG, newG;
int count;

printf("Enter a number: ");
scanf("%f", &n);

oldG = 1;
count = 0;

while(fabs((newG * newG) - n) >= 1e-5) {
      
	printf("%d \t %-10.5f\n",count, oldG); 

   	newG = (oldG + (n / oldG)) / 2.0;
	oldG = newG;
	count++;
        
}

printf("Estimated square root of %.5lf: %.5lf\n",n, newG);
return 0; 
} 





