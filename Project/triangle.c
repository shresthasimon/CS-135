//
//      Title: triangle.c
//      Purpose: Computes the area and the perimeter of a right triangle.
//      Author: Simon Shrestha
//

#include <stdio.h>
#include <math.h>

int main(void)
{
int legA, legC, area, perimeter;

printf("This program computes the area and perimeter of a right triangle.\n");

printf("Enter the value of leg a: ");
scanf("%d", &legA);

printf("Enter the value of leg c: ");
scanf("%d", &legC);

area = ((legA*legC)/2);
printf("The area of the triangle is %d\n", area);

perimeter = legA + legC + sqrt(legA * legA + legC * legC);
printf("The perimeter of the triangle is %d\n", perimeter);

return 0;
}

