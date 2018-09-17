//
// Title: series.c
// Purpose: Computes a series
// Author: Simon Shrestha
//

#include <stdio.h>

int main(void) {

int n, i, sum;

printf("Enter an integer number: ");
scanf("%d", &n);

for(i = 0; i <= n; i++){
        if(n % 2 == 0) {
                sum = (-n * (n+1))/ 2;
        }else{
                sum = (n * (n+1))/ 2;
        }
}

printf("The value of the series is: %d\n", sum);

return 0;
}
