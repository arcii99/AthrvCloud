//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include<stdio.h>
#include<stdlib.h>

//This is a funny implementation of an Intrusion Detection System in C.

int main() {

    //User input buffer
    char buffer[100];

    //Initiate security
    int secure = 1;

    //Welcome message
    printf("Welcome to the most hilarious Intrusion Detection System ever!\n\n");

    //Main program loop
    while (secure) {

        //Prompt user for input
        printf("Please enter your name: ");

        //Read user input into buffer
        fgets(buffer, sizeof(buffer), stdin);

        //Check for intrusion attempt
        if (buffer[0] == 'H' && buffer[1] == 'a' && buffer[2] == 'c' && buffer[3] == 'k' && buffer[4] == 'e' && buffer[5] == 'r') {

            //Intrusion detected!
            printf("\nINTRUSION ATTEMPT DETECTED! SYSTEM SHUTDOWN INITIATED\n");

            //System shutdown
            exit(0);
        }
        else {

            //Not an intrusion attempt
            printf("Hello %s", buffer);
        }
    }

    return 0;
}