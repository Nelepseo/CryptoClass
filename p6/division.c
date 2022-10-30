////////////////////////////////////////////////////////////////////////////////
// Main File:        sendsig.c
// This File:        sendsig.c
// Other Files:      division.c sendsig.c
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
//////////////////////////// 80 columns wide ///////////////////////////////////
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

char buffer[100]; //buffer for input

/* This funct hands the exit call
 *
 * int sig the signal input for exiting.
 */
void exitHandler(int sig) { 
    exit(0);   
}

/* To counteract the divide by zero error that exits the program 
 * ungracefully
 *
 * int sig the signal for divbyzero
 */
void zeroDivHandler(int sig) {
    exit(0);  
} 


/* 
 * Main function prompts user for 2 ints and puts divides them
 */
int main() {
    
    struct sigaction exit;
    exit.sa_handler = exitHandler;
    
    struct sigaction zeroDiv;
    zeroDiv.sa_handler = zeroDivHandler;
    sigaction(SIGINT, &exit, NULL);
    sigaction(SIGFPE, &zeroDiv, NULL);
    
    //main loop, to continuously prompt user for input
    while(1) {
        printf("Enter first integer: ");
        char* text = fgets(buffer, sizeof buffer, stdin);
        //change text to int
        int first = atoi(text);
        printf("Enter second integer: ");
        text = fgets(buffer, sizeof buffer, stdin);
        //change text to int
        int second = atoi(text);
        
        printf("%d / %d is %d with a remainder of %d\n",first,second, first/second, first % second);
    }
}