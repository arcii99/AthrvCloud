//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function prototypes */
void printState(int state);
void delay(int seconds);

/* main function */
int main(void) {
    int state = 0;  // initial state is red
    int counter = 0;
    srand(time(0));  // seeding random number generator with current time

    while (1) {  // infinite loop
        if (counter % 10 == 0) {  // every 10 seconds
            if (state == 0) {
                state = 1;  // switch to green
            } else if (state == 1) {
                state = 2;  // switch to yellow
            } else {
                state = 0;  // switch to red
            }
        }

        printState(state);
        delay(1);  // delay for 1 second
        counter++;  // increment the counter
    }

    return 0;
}

/* function definitions */
void printState(int state) {
    if (state == 0) {
        printf("\nRed light is on.\n");  // print red light state
    } else if (state == 1) {
        printf("\nGreen light is on.\n");  // print green light state
    } else {
        printf("\nYellow light is on.\n");  // print yellow light state
    }
}

void delay(int seconds) {
    clock_t start_time = clock();  // get current clock time
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);  // wait for given number of seconds
}