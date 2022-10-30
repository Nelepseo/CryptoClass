////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        intdate.c
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
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> /*memset*/


int user_count = 0; //user signal check 
int counter = 0 ;// to check for exit
int alarm_time = 3; //amount of time for alarm
pid_t pid; //pid


/* (A succinct description of this function here.)
 *
 * The alarm to print the PID and the date.
 */
void sigalrm_handler() {
    time_t daylight;
	  time(&daylight);
    
	  if((pid = getpid()) < 0) {
        perror("unable to get pid");
        exit(0);
	  } 
     
    printf("PID: %d | Current Time: %s", pid, ctime(&daylight));
    alarm(alarm_time);
}


/* (A succinct description of this function here.)
 *
 * The handler for the sigint interrupt
 */
void sigint_handler() {
    counter++;
    if(counter == 1) {
        printf("\nSIGINT caught!\n");
       	printf("SIGUSR1 was recieved %d times. Exiting now.\n", user_count);
	      exit(0);
    }
    
}


/* (A succinct description of this function here.)
 *
 * The handler for the sigint interrupt
 */
void siguser_handler() {
    user_count++;
    printf("SIGUSR1 caught!\n");
}

/* (A succinct description of this function here.)
 *
 * (parameter name) (Describe the first parameter here)
 * (parameter name) (Do the same for each additional parameter)
 * (description of the return value)
 */
int main() {

    //sigaction handler
    struct sigaction sah;
    memset(&sah,0,sizeof(sah));

    struct sigaction sahI;
    memset(&sahI,0,sizeof(sahI));

    struct sigaction sahU;
    memset(&sahU,0,sizeof(sahU));
    
    sah.sa_handler = sigalrm_handler;
    sahI.sa_handler = sigint_handler;
    sahU.sa_handler = siguser_handler;
    
    sigaction (SIGALRM, &sah, NULL);
    sigaction (SIGINT, &sahI, NULL);
    sigaction (SIGUSR1, &sahU, NULL);

    printf("Date will be printed every 3 seconds.\n");
    printf("Enter ^C to end the program:\n");
    alarm(alarm_time);
	
    //it exits out of while loop. Explanation in p6questions. 
    while(1){
    }
    
    return 0; 
}
