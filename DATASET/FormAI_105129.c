//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void display_lights(int red, int yellow, int green);

int main() {
    int red = 1, yellow = 0, green = 0; // initial state
    int count = 0; // used to switch state

    while(1) { // loop indefinitely
        display_lights(red, yellow, green); // display current state
        sleep(1); // time delay of 1 second

        if(count == 0) { // if current state is red
            green = 1; // switch to green state
            red = 0;
            count++; // increment count to switch to next state
        } else if(count == 1) { // if current state is green
            yellow = 1; // switch to yellow state
            green = 0;
            count++; // increment count to switch to next state
        } else if(count == 2) { // if current state is yellow
            red = 1; // switch to red state
            yellow = 0;
            count = 0; // reset count to switch back to first state
        }
    }

    return 0;
}

void display_lights(int red, int yellow, int green) {
    system("clear"); // clear console screen
    printf("\n\n\t\tTRAFFIC LIGHT CONTROLLER\n\n");

    if(red) {
        printf("\t\t\tRED\t ON\n");
    } else {
        printf("\t\t\tRED\t OFF\n");
    }

    if(yellow) {
        printf("\t\t\tYELLOW\t ON\n");
    } else {
        printf("\t\t\tYELLOW\t OFF\n");
    }

    if(green) {
        printf("\t\t\tGREEN\t ON\n");
    } else {
        printf("\t\t\tGREEN\t OFF\n");
    }
}