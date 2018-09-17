// 
// Title: combine_string.c
// Purpose: Combines strings through interspersing two strings.
// Author: Simon Shrestha 
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* intersperse(const char *s1, const char *s2);
char* widen_stars(const char *s1, const char *s2);

int main(int argc, char *argv[]){

	char *s1 = (char*)malloc(30);
	char *s2 = (char*)malloc(30);
	char *s3;
	printf("Please enter a string of maximum 30 characters: ");
	scanf("%s", s1);
	printf("Please enter a string of maximum 30 characters: ");
	scanf("%s", s2);
	if(strcmp(argv[1], "-i") == 0){
		printf("The combined string is: %s\n", intersperse(s1, s2));
	}else if(strcmp(argv[1], "-w") == 0){
		printf("The combined string is: %s\n", widen_stars(s1, s2));
		
	}

return 0;
}

char* intersperse(const char *s1, const char *s2){
	char *s3;
	int i;
	int j;
	s3 = malloc(strlen(s1) + strlen(s2) * sizeof(char));
	char *start = s3;
	
	while(*s1 != '\0' && *s2 != '\0'){
		*s3++ = *s1++;
		*s3++ = *s2++;	
	}
	while(*s1 != '\0'){
		*s3++ = *s1++;	
	}
	while(*s2 != '\0'){
		*s3++ = *s2++;	
	}
	*s3 = '\0';
	s3 = start;
	return s3;
	
}

char* widen_stars(const char *s1, const char *s2){
	char *s3;
	s3 = malloc(strlen(s1) + strlen(s2) * sizeof(char));
	int i = 0;
	int j = 0;

	s3 = malloc(2*(strlen(s1) + strlen(s2)) * sizeof(char));
	char *start = s3;
	
	while(*s1 != '\0'){
		*s3++ = *s1++;
		*s3++ = '*';	
	}
	while(*s2 != '\0'){
		*s3++ = *s2++;
		*s3++ = '*';	
	}
	*--s3 = '\0';
	s3 = start;
	return s3;

}


