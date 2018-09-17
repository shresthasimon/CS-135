//
// Name: calc_c.c 
// Purpose: Basic Scientific Calculator
// Author: Simon Shrestha
//

#include <stdio.h>
#include <math.h>


int main(void){

int menu;
int n3 = 1;
float n1, n2, result;
double result2;

for(;;){
printf("\nThis program implements a calculator. Options: \n");

printf("1 - addition\n");
printf("2 - subtraction\n");
printf("3 - multiplication\n");
printf("4 - division\n");
printf("5 - toggle precision\n");
printf("6 - exit program\n");
printf("7 - compute exp(x)\n");
printf("8 - compute log(x)\n");


printf("\nPlease enter your option: ");
scanf("%d",&menu);

switch(menu){
case 1: 
    printf("Enter first term: ");
    scanf("%f", &n1);
    printf("Enter second term: ");
    scanf("%f", &n2);
    
    if(n3 == 1){
    result = n1 + n2;
    printf("The sum is: %f\n", result);
    
    }
    if(n3 == 2){
    result2 = n1 + n2;
    printf("The sum is: %.15f\n", result2);
    
    }
break; 
case 2:
    printf("Enter first term: ");
    scanf("%f",&n1);
    printf("Enter second term: ");
    scanf("%f",&n2);
    
    if(n3 == 1){
    result = n1 - n2;
    printf("The difference is: %f\n", result);
    }
    if(n3 == 2){
    result2 = n1 - n2;
    printf("The difference is: %.15f\n", result2);
    }
	break;
case 3:
    printf("Enter first term: ");
    scanf("%f",&n1);
    printf("Enter second term: ");
    scanf("%f",&n2);
    
    if(n3 == 1){
    result = n1 * n2;
    printf("The product is: %f\n", result);
    
    }
    if(n3 == 2){
    result2 = n1 * n2;
    printf("The product is: %.15f\n", result2);
    
    }
break;
case 4:
    printf("Enter first term: ");
    scanf("%f",&n1);
    printf("Enter second term: ");
    scanf("%f",&n2);
    
    if(n2 == 0){
    printf("Cannot divide by zero!\n");
    break;
    }else{
        if(n3 == 1){
            result = n1 / n2;
            printf("The quotient is: %f\n", result);
                
        }else if(n3 == 2){
            result2 = n1 / n2;
            printf("The quotient is: %.15f\n", result2);
                
        }
    }
break;  
case 5: 
    if(n3 == 2){
    n3 = 1;
    printf("Calculator now works with single percision. \n");
    break;
    }
    if(n3 == 1){
    n3 = 2;
    printf("Calculator now works with double percision. \n");
break;
    }
case 6:
    return 0;
case 7:
    printf("Enter term: ");
    scanf("%f", &n1);
    
    if(n3 == 1){
    result = exp(n1);
    printf("The result of exp(x) is: %f\n", result);
    
    }
    if(n3 == 2){
    result2 = exp(n1);
    printf("The result of exp(x) is: %.15f\n", result2);
   
    }
break;
case 8:
    printf("Enter term: ");
    scanf("%f", &n1);
    
    if(n1 < 0){
    printf("Cannot take the log of a negative number!\n");
    
    }else{
        if(n3 == 1){
    result = log(n1);
    printf("The result of the log(x) is: %f\n", result);
    
    }else if(n3 == 2){
    result2 = log(n1);
    printf("The result of the log(x) is: %.15f\n", result2);
    
    }
    }
break;
default:
printf("\nThis program implements a calculator. Options: \n");
printf("1 - addition\n");
printf("2 - subtraction\n");
printf("3 - multiplication\n");
printf("4 - division\n");
printf("5 - toggle precision\n");
printf("6 - exit program\n");
printf("7 - compute exp(x)\n");
printf("8 - compute log(x)\n");

printf("\nPlease enter a valid option.\n");
break;
 
    
}
}
}
