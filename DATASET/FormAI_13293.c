//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// function to set initial state to red
void red() {
    printf("\n\n\t\t\tRED\n");
    sleep(5); // wait for 5 seconds
}

// function to switch state from red to green
void redToGreen() {
    printf("\n\n\t\t\tYELLOW\n");
    sleep(2); // wait for 2 seconds
    printf("\n\n\t\t\tGREEN\n");
    sleep(5);
}

// function to switch state from green to yellow and then to red again
void greenToRed() {
    printf("\n\n\t\t\tYELLOW\n");
    sleep(2);
    printf("\n\n\t\t\tRED\n");
    sleep(5);
}

// main function that controls the traffic light
int main() {
    while (1) { // infinite loop
        red(); // start with red light
        redToGreen(); // change to green light
        greenToRed(); // change to red light again
    }
    return 0;
}