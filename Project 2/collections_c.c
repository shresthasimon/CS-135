//
// Name: Collections.c
// Purpose: outputs which collections BOB can buy with his budget.
// Author: Simon Shrestha
//

#include <stdio.h>

int main(void){

int v1, p1, v2, p2, v3, p3, b, c1, c2, c3;

printf("Enter volumes and price per volume for collection1 1: ");
scanf("%d %d", &v1, &p1);

printf("Enter volumes and price per volume for collection1 2: ");
scanf("%d %d", &v2, &p2);

printf("Enter volumes and price per volume for collection1 3: ");
scanf("%d %d", &v3, &p3);

printf("Enter Bob's budget: ");
scanf("%d", &b);

c1 = v1 * p1;
c2 = v2 * p2;
c3 = v3 * p3;
 
if(b > 0){
printf("(1) Bob has some money to buy collections.\n");
}else{
printf("(1) Bob does not have the money to buy anything.\n");
}

if(c1 < b && c2 < b && c3 < b){
printf("(2) Bob has enough money to buy all three collections.\n");
}else{
printf("(2) Bob does not have enough money to buy all three collections.\n");
}

if((c1 > b && c2 > b) || (c2 > b && c3 > b) || (c1 > b && c3 > b)){
printf("(3) At least two collections are more expensive than Bob's budget.\n");
}else{
printf("(3) At least two collections are cheaper than or equal to Bob's budget.\n");
}  

if((c1 == c2) || (c2 == c3) || (c1 == c3)){
printf("(4) At least two collections cost the same amount of money.\n");
}else{
printf("(4) No two collections have the same price.\n");
}

if((c1 > b && c2 > b) || (c2 > b && c3 > b) || (c1 > b && c3 > b) ){
printf("(5) Only one collection is cheaper than or equal to Bob's budget.\n");
}else{
printf("(5) More than one collection is cheaper than or equal to Bob's budget or they are all more expensive.\n");
}

if(c1 < b && c2 < b && c3 < b){
printf("(6) Bob has enough money to buy any one of the three collections.\n");
}else{
printf("(6) Bob does not have enough money to buy any one of the three collections.\n");
} 

if(c1 > b && c2 > b && c3 > b){
printf("(7) Bob does not have enough money to buy any collection.\n");
}else{
printf("(7) Bob can buy at least one collection.\n");
}
return 0;
}
