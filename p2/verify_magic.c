////////////////////////////////////////////////////////////////////////////////
// Main File:        verify_magic.c
// This File:        verify_magic.c
// Other Files:      generate_magic.c
// Semester:         CS 354 Spring 2017
//
// Author:           Andrew Thompson
// Email:            asthompson5@wisc.edu
// CS Login:         andrewt
//
/////////// IF PAIR PROGRAMMING IS ALLOWED, COMPLETE THIS SECTION //////////////
//
// Pair Partner:     (name of your pair programming partner)
// Email:            (email address of your programming partner)
// CS Login:         (partner's CS login name)
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of 
//                   of any information you find.
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing Square
// size: dimension(number of rows/columns) of the square
// array: 2D array of integers
typedef struct _Square {
	int size;
	int **array;
} Square;

Square * construct_square(char *filename);
int verify_magic(Square * square);

int main(int argc, char *argv[])
{
	if(argc > 2 || argc < 1){
		printf("Must have only one argument.\n");
		exit(1);
	}

	
	// Check input arguments to get filename
	char *filename = argv[1];
	
	// Construct square
	Square *thisSquare = construct_square(filename);

	// Verify if it's a magic square and print true or false
	if(verify_magic(thisSquare) == 1){
		printf("True\n");
	}
	else if(verify_magic(thisSquare) == 0){
		printf("False\n");
	}

	return 0;
}

/* construct_square reads the input file to initialize a square struct
 * from the contents of the file and returns the square.
 * The format of the file is defined in the assignment specifications
 */
Square * construct_square(char *filename)
{

	// Open and read the file
	if(fopen(filename, "r") == NULL){
		printf("Cannot open file for reading\n");
		exit(1);
	}
	FILE *f = fopen(filename, "r");
	// Read the first line to get the square size
	
	int i;
	//fscanf(f, "%d", &i);
	// Initialize a new Square struct of that size
	int **a = (int **)malloc(i * sizeof(int));
	for(int k = 0; k < i; k++){
		*(a+i) = (int *)malloc(i * sizeof(int));
	}
	Square *magic = malloc(sizeof(Square));
	magic->size = i;
	// Read the rest of the file to fill up the square
	int y = 0;
	int z = 0;
	
	//while(fscanf(f, "%d", &a[z][y]) != EOF ){
	//	y++;
		if(y == i){
			z++;
			y = 0;
		}
	//}
	magic->array = a;
	fclose(f);
	free(a);	
	return magic;
}

/* verify_magic verifies if the square is a magic square
 * 
 * returns 1(true) or 0(false)
 */
int verify_magic(Square * square)
{
	
	int x = 0;
	// Check all rows sum to same number
	if((square->array[0][0] + square->array[0][1] + square->array[0][2]) == 
		(square->array[1][0] + square->array[1][1] + square->array[1][2]) ==
		(square->array[2][0] + square->array[2][1] + square->array[2][2])){
		x = 1;
	}else{
		return 0;
	}
	
	// Check all cols sum to same number
		if((square->array[0][0] + square->array[1][0] + square->array[2][0]) == 
		(square->array[0][1] + square->array[1][1] + square->array[2][1]) ==
		(square->array[0][2] + square->array[1][2] + square->array[2][2])){
		x = 1;
	}else{
		return 0;
	}

	// Check main diagonal
	if((square->array[0][0] + square->array[1][1] + square->array[2][2]) == 
		(square->array[1][0] + square->array[1][1] + square->array[1][2])){
		x = 1;
	}else{
		return 0;
	}
	// Check secondary diagonal
	if((square->array[0][2] + square->array[1][1] + square->array[2][0]) == 
		(square->array[1][0] + square->array[1][1] + square->array[1][2])){
		x = 1;
	}else{
		return 0;
	}
	return x;
}

