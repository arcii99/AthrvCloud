//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multivariable
#include <stdio.h>

int main() {
    int red = 1, green = 0, yellow = 0; // variables to store the current state of each traffic light
    int time = 0; // variable to keep track of time

    while (1) { // infinite loop
        time++; // increment the time

        // check which traffic light is currently on and change it accordingly after a certain amount of time
        if (red == 1 && time == 10) {
            time = 0;
            red = 0;
            green = 1;
        } else if (green == 1 && time == 8) {
            time = 0;
            green = 0;
            yellow = 1;
        } else if (yellow == 1 && time == 5) {
            time = 0;
            yellow = 0;
            red = 1;
        }

        printf("Red: %d Green: %d Yellow: %d Time: %d\n", red, green, yellow, time); // print the current state
    }

    return 0;
}