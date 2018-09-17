// 
// Title: planets_sort.c
// Purpose: Rearranges the planets alphabetically and in reverse.
// Author: Simon Shrestha
//

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int string_compare(const char *str1, const char *str2);

int main(int argc, char *argv[]){
int i;
int j;
char *temp;

char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

for(i = 0; i < 8; i++){
	for(j = 8; j >= i+1; j--){
		if(string_compare(planets[j], planets[j-1]) == 0){
			temp = malloc(strlen(planets[j]) * sizeof(char));
			strcpy(temp, planets[j]);

			planets[j] = malloc(strlen(planets[j-1]) * sizeof(char));
			strcpy(planets[j], planets[j-1]);

			planets[j - 1] = malloc(strlen(temp) * sizeof(char));
			strcpy(planets[j-1], temp);

			free(temp);	
		}
	}
}

if(strcmp(argv[2], "a") == 0){
	printf("The planets in alphabetical order are: ");
	for(i = 0; i < 8; i++){
		printf("%s, ", planets[i]);
	}
	printf("%s\n", planets[i]);
}
if(strcmp(argv[2], "r") == 0){
	printf("The planets in reverse alphabetical order are: ");
	for(i = 8; i > 0; i--){
		printf("%s, ", planets[i]);
	}
	printf("%s\n", planets[i]);
}

return 0;
}

int string_compare(const char *str1, const char *str2){
	int i = 0;

	while(str1[i] != '\0' && str2[i] != '\0'){
		if(str1[i] == str2[i]){
			i++;
			continue;
		}
		if(str1[i] > str2[i]){
			return 1;
		}
		 if(str1[i] < str2[i]){
			return 0;
		}
	
	}
	return -1;
}

