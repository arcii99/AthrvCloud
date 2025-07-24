//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: funny
//Welcome to the Wacky Traffic Light Controller!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); //Seeds the random number generator for randomness

    printf("Welcome to the Wacky Traffic Light Controller!\n");

    int countDown = 10; //Initial countdown time in seconds
    int state = 0; //Initial state of the traffic light
    int prev_state = -1; //Variable to keep track of the previous state
    char color[6][10] = {"GREEN", "GREEN/YELLOW", "YELLOW", "RED", "RED/YELLOW", "FLICKER"}; //Array of traffic light colors

    printf("Starting countdown...\n");

    while(countDown >= 0) {

        printf("%d\n", countDown); //Prints the countdown
        countDown--;
        sleep(1); //Pauses the loop for 1 second
        
        if(countDown == 7 && state == 0) { //If 3 seconds left and in GREEN state
            printf("\nSwitching to YELLOW...\n\n");
            state++; //Changes state to YELLOW
            prev_state = 0; //Sets prev_state to GREEN
        }

        if(countDown == 4 && state == 1) { //If 6 seconds left and in YELLOW state
            printf("\nSwitching to RED...\n\n");
            state++; //Changes state to RED
            prev_state = 1; //Sets prev_state to YELLOW
        }

        if(countDown == 1 && state == 2) { //If 9 seconds left and in RED state
            printf("\nSwitching to GREEN...\n\n");
            state = 0; //Changes state to GREEN
            prev_state = 2; //Sets prev_state to RED
        }

        if(countDown == 2 && prev_state == 2) { //If 8 seconds left and prev_state was RED
            printf("\nSwitching to RED/YELLOW...\n\n");
            state = 4; //Changes state to RED/YELLOW
            prev_state = 2; //Sets prev_state to RED
        }

        if(countDown == 1 && prev_state == 4) { //If 9 seconds left and prev_state was RED/YELLOW
            printf("\nSwitching to GREEN...\n\n");
            state = 0; //Changes state to GREEN
            prev_state = 4; //Sets prev_state to RED/YELLOW
        }
        
    }

    printf("TIMES UP!\n");

    while(1) { //Loops indefinitely
        int randomNum = rand() % 6; //Generates a random number between 0-5
        printf("The traffic light is now %s!\n", color[randomNum]);

        if(randomNum == 5) { //If randomNum is 5, i.e. FLICKER
            printf("SOMEONE CALL AN ELECTRICIAN!\n"); //Prints funny message if flickering
        }

        sleep(2); //Pauses the loop for 2 seconds
    }

    return 0;
}