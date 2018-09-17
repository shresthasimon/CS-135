//
//	Title: tictactoe.c
//	Purpose: Tictactoe game.
//	Author: Simon Shrestha
//	
  
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void clear_table(char a[][3]);
void display_table(char a[][3]);
char check_three_in_a_row(char a[][3]);
bool check_legal_option(char a[][3], int b, int c);
void generate_player2_move(char a[][3], int x, int y);
bool check_table_full(char a[][3]);
void update_table(char a[][3], int x, int y, char letter);
void generate_player1_move(char a[][3], int row, int col);

int main(void){
	char matrix[3][3];
	int row;
	int row2;
	int col2;
	int col;
	int done;

	printf("This program plays the game of tic-tac-toe\n");
	clear_table(matrix);
	printf("The current state of the game is: \n");
	display_table(matrix);

	do{
		generate_player1_move(matrix, row, col);

		printf("\nThe current state of the game is: \n");

		display_table(matrix);

		if(check_three_in_a_row(matrix) == 'O' ){ // checks for three in a row
			done = 'O';		// breaking out of do - while loop if three in a row is an 'O'				
			break;
		}
		if(check_table_full(matrix) == true){ // checks for table full
			break; 
		}

		generate_player2_move(matrix, row2, col2);

		printf("\nThe current state of the game is: \n");
		display_table(matrix);

		if(check_three_in_a_row(matrix) == 'X' ){ // checks for three in a row
			done = 'X';		// breaking out of do - while loop if three in a row is an 'X'	
			break;
		}
		if(check_table_full(matrix) == true){ // checks for table full
			break;
		}
		
	}while(done == 0);
	
	if(done == 'O'){
		printf("\nCongratulations, Player 1 wins!\n");
	}else if(done == 'X'){
		printf("\nCongratulations, Player 2 wins!\n");
	}else{
		printf("\nGame over, no player wins.\n");
	}
	
	
return 0;
}

/* Function: generate_player1_move
	Asks user for there position, checks if it's valid, and updates the table.
	a[][3] = takes in a 3x3 array.
	int row, col are the place values for the user's position.
*/
void generate_player1_move(char a[][3], int row, int col){
	printf("\nPlayer 1 enter your selection [row,col]: ");
	scanf("%d,%d", &row, &col);

	row--; col--; // convert what the user entered to be read by the function

	if(!check_legal_option(a, row, col)){ // checks if the user's input is valid.
		printf("Invalid move, please try again. ");
		generate_player1_move( a, row, col); 
	}else{
		update_table(a, row, col, 'O');
	}
}

/* Function: clear_table
	Clears the table at the start of the game
	a[][3] = takes in a 3x3 array.
*/
void clear_table(char a[][3]){
	int i;
	int j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			a[i][j] = '_';
		}
	}	
}

/* Function: display_table
	Outputs the current status of the game.
	a[][3] = takes in a 3x3 array.
*/
void display_table(char a[][3]){
	int i;
	int j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
}

/* Function: check_three_in_a_row
	Checks whether player one or player two got a three in a row.
	a[][3] = takes in a 3x3 array.
*/
char check_three_in_a_row(char a[][3]){
	int i;
	
	for(i=0; i<3; i++){  /* check rows */
    	if(a[i][0] == a[i][1] && a[i][0] == a[i][2]){
	
			if(a[i][0] == 'X' || a[i][0] == 'O'){
				return a[i][0];
			}
		}
	}
  for(i=0; i<3; i++){  /* check columns */
    	if(a[0][i] == a[1][i] && a[0][i] == a[2][i]){

			if(a[0][i] == 'X' || a[0][i] == 'O'){
				return a[0][i];
			}
		}
	}
  /* check diagonals */
  if(a[0][0] == a[1][1] && a[1][1] == a[2][2]){

		if(a[0][0] == 'X' || a[0][0] == 'O'){
       		return a[0][0];
		}
	}

  if(a[0][2] == a[1][1] && a[1][1] == a[2][0]){

		if(a[0][2] == 'X' || a[0][2] == 'O'){
       		return a[0][2];
		}
	}
	return 0;
}

/* Function: check_legal_option
	Checks whether the option entered is valid.
	a[][3] = takes in a 3x3 array.
	int b, c are the place values on the tictactoe board
	returns true if the place is valid
	returns false if the place is invalid
*/
bool check_legal_option(char a[][3], int b, int c){

	if(((b >= 0) && (b < 3)) && ((c >= 0) && (c < 3))){
		if(a[b][c] == '_'){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
/* Function: generate_player2_move
	Generates the move for the computer
	char a[][3] is the 3x3 array 
	int *x is a pointer to the row value
	int *y is a pointer to the col value
*/
void generate_player2_move(char a[][3], int x, int y){
	
	srand((unsigned) time(NULL));

	do{
		x = rand() % 3;
		y = rand() % 3;
	}while(!check_legal_option(a, x, y));
	update_table(a, x, y, 'X');
	x++; y++; // converts the array values so that it's readable by user. 
	printf("\nPlayer 2 has entered [row,col]: %d,%d\n", x, y);
	
	

}
/* Function: check_table_full
	Checks whether any tile on the table is an underscore
	If it is, return false, else return true
	char a[][3] is the 3x3 array
*/ 
bool check_table_full(char a[][3]){
	int i;
	int j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(a[i][j] == '_'){
				return false;
				
			}
		}
	}
	return true;
}


/* Function: update_table
	Updates the tictactoe table depending on what the computer / user wanted.
	char a[][3] is the 3x3 array
	int x is the row
	int y is the column
	char letter is either an X or O, depending on whether it's player one or two.
*/
void update_table(char a[][3], int x, int y, char letter){
	a[x][y] = letter;
}
