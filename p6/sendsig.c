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
#include <stdlib.h>
#include <signal.h>
#include <string.h>


/*The main method sending kill signals to programs with the pid
 *
 * int argc the argument count
 *
 * char *argv[] the array of command line arguments 
 */
int main(int argc, char *argv[]){
    
    char in[] = "-i";//check variable
    char us[] = "-u";//check variable
    //if arg count is 0 then give directions
    if(argc == 1){
        printf("Usage: <signal type> <pid>\n");
        exit(0);
    }
    //more than 3 then to many arguments
    if(argc > 3){
        printf("Invalid argument!\n");
        exit(0);
    }
    //cast arg two to an integer
    int x = atoi(argv[2]);
    //if its - then its not a valid int
    if(x == 0){
        printf("Invalid argument!\n");
        exit(0);
    }
    //check to see which command to use
    if(strcmp(argv[1],  us) == 0){
        kill(x, SIGUSR1);
    }
    else if(strcmp(argv[1],  in) == 0){
        kill(x, SIGINT);
    }
    else{
        printf("Must specify -i sigint or -u sigusr1");
        exit(0); 
    }

    return 0;
}