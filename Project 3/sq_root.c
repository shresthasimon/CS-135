//
// Title: sq_root.c
// Purpose: Calculates the square root of a number.
// Author: Simon Shrestha
//

#include <stdio.h>
#include <math.h>

int main(void){

double n, oldG, newG;

printf("Enter a number: ");
scanf("%lf", &n);

oldG = 1;

while(fabs((newG * newG) - n) > 1e-5) {

     printf("%10.5lf\n", oldG);
     newG = (oldG + (n / oldG)) / 2;
     oldG = newG;
         
        
}

printf("Estimated square root of %.5lf: %.5lf\n",n, newG);
return 0; 
} 



