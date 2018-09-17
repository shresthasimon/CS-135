//
// Title: scrabble.c
// Purpose: Computes the value of words entered by user.
// Author: Simon Shrestha
//

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define num 7

void generate_letter_set(int letter_set[], int size_letter_set, int num_letters);
int read_word(char word[], int size[]);
_Bool check_word (char word[], int size_word, int letter_set[], int size_letter_set);
int compute_word_value(char word[], int size_word);

int main(void){

int num_letters = num; 
int max_word_size = num;
int size_letter_set;
int letter_set[num_letters];
char word[25];
int size[1];

printf("This program plays a game of scrabble.\n");
printf("Your letters are: ");

generate_letter_set(letter_set, 100, num_letters);
for(int i = 0; i < num; i++){
		printf("%c ", letter_set[i]); 
	}
printf("\n");

read_word(word, size);
int size_word = size[0];
int checkWord = check_word(word, size_word, letter_set, size_letter_set);

if(checkWord == true){
	compute_word_value(word, size_word);
	printf("Thank you for playing.\n");
}	

while(checkWord == false){
	printf("This word is not valid. Use your letters: ");
	for(int i = 0; i < num; i++){
		printf("%c ", letter_set[i]); 
	}
	printf("\n");
	read_word(word, size);
	size_word = size[0];
	checkWord = check_word(word, size_word, letter_set, size_letter_set);
	if(checkWord == true){
		compute_word_value(word, size_word);
		printf("Thank you for playing.\n");
		break; 
	}
	
}

return 0;
}
// Random letter generator function
void generate_letter_set(int letter_set[], int size_letter_set, int num_letters){

const char all_letters[100] = {'E','E','E','E','E','E','E','E','E','E','E','E','A','A','A','A','A','A','A','A','A','I','I','I','I','I','I','I','I','I','O','O','O','O','O','O','O', 'O','N','N','N','N','N','N','R','R','R','R','R','R','T','T','T','T','T','T','L','L','L','L','S','S','S','S','U','U','U','U','D','D','D','D','G', 'G','G','B','B','C','C','M','M','P','P','F','F','H','H','V','V','W','W','Y','Y','K','J','X','Q','Z','_','_'};

int count, letters, one_letter;
int space  = 0;
int array[100] = {0};

srand((unsigned) time(NULL));

count = 0;
while(count < num){
letters = rand() % 100; 
one_letter = all_letters[letters];
letter_set[count] = one_letter;

if(array == 0){
	printf("%c ", all_letters[letters]);
	array[letters]++;
	}else if(array[letters] == 1){
		letters = rand() % size_letter_set; 
		one_letter = all_letters[letters];
		array[letters]++;
		printf("%c ", all_letters[letters]);
}
count++;
}
}
// reading letters from user
int read_word(char word[], int size[]){

int max_size_word = num; 
 size [1];

printf("Enter your word: ");

char c = getchar();
c = toupper(c);
int count = 0;

while(c != '\n'){
word[count] = c;
c = getchar();
c = toupper(c);
count++;
size[0] = count;
}

}
// checks if the letters the user enters matches the ones from the generated letter set.
_Bool check_word (char word[], int size_word, int letter_set[], int size_letter_set){

int Word = 0;
int Letter = 0;
char copy[num];

for(int i = 0; i < num; i++){
	copy[i] = letter_set[i];
}
while(Word < size_word){
	if(copy[Letter] == word[Word]){
		copy[Letter] = 0;
		Word++;
		Letter = 0;
	}
	if(Letter == num){
		break;
	}else{
		Letter++;
	}
}

if(Word == size_word + 1){
	return true;
}else if(Word == size_word){
	return true;
}else{
	return false;
}

}
// calculates the point values for each letter used by user.
int compute_word_value(char word[], int size_word){

int count = 0;
int total = 0;

while(count < size_word){
	switch(word[count]){
		case 95: 
			count++;
			break;
		case 76: case 83: case 85: case 78: case 82: case 84: case 79: case 65: case 73: case 69: 
			total++;
			count++;
			break;
		case 71: case 68:
			total = total + 2;
			count++;
			break;
		case 66: case 67: case 77: case 80: 
			total = total + 3;
			count++;
			break;
		case 70: case 72: case 86: case 87: case 89:
			total = total + 4;
			count++;
			break;
		case 75:
			total = total + 5;
			count++;
			break;
		case 74: case 88: 
			total = total + 8;
			count++;
			break;
		case 81: case 90: 
			total = total + 10;
			count++;
			break; 
	}
}
	printf("The value of your word is: %d\n", total);
}












  













