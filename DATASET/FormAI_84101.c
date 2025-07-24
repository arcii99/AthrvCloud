//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to wait for some time according to the duration
void delay(int duration) {
    clock_t start_time = clock();
    while (clock() < start_time + duration);
}

// Function to switch the color of the traffic light
void switch_color(char* color) {
    if (*color == 'R') {
        *color = 'Y';
    } else if (*color == 'Y') {
        *color = 'G';
    } else if (*color == 'G') {
        *color = 'R';
    }
}

int main() {
    char color = 'R'; // Starting color of the traffic light is red

    while (1) { // Loop forever
        if (color == 'R') {
            printf("Traffic Light: RED\n");
            delay(5000); // Wait for 5 seconds
        } else if (color == 'Y') {
            printf("Traffic Light: YELLOW\n");
            delay(2000); // Wait for 2 seconds
        } else if (color == 'G') {
            printf("Traffic Light: GREEN\n");
            delay(5000); // Wait for 5 seconds
        }

        switch_color(&color); // Switch the color of traffic light
    }

    return 0;
}