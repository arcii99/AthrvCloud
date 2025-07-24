//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL)); //seed random number generator with current time
    int current_state = 0;
    int delay; 

    while(1) { //infinite loop
        switch(current_state) {
            case 0: //red light
                printf("Red Light \n");
                delay = (rand() % 6) + 3; //random delay between 3 and 8 seconds
                sleep(delay); //wait for delay to finish
                current_state = 1; //switch to next state
                break;
            case 1: //red and amber lights
                printf("Red and Amber Lights \n");
                delay = 2; //delay for 2 seconds
                sleep(delay); //wait for delay to finish
                current_state = 2; //switch to next state
                break;
            case 2: //green light
                printf("Green Light \n");
                delay = (rand() % 11) + 5; //random delay between 5 and 15 seconds
                sleep(delay); //wait for delay to finish
                current_state = 3; //switch to next state
                break;
            case 3: //amber light
                printf("Amber Light \n");
                delay = 2; //delay for 2 seconds
                sleep(delay); //wait for delay to finish
                current_state = 0; //switch back to first state
                break;
        }
    }
    return 0;
}