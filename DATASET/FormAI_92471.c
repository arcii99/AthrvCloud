//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int red_time = 10; // time in seconds
    int yellow_time = 2; // time in seconds
    int green_time = 8; // time in seconds
    srand(time(NULL)); // seed the random number generator
    
    int state = rand() % 3; // random starting state
    
    while (1) { // infinite loop
        if (state == 0) { // red light
            printf("RED\n");
            for (int i = 0; i < red_time; i++) {
                printf("%d\n", i); // print countdown
                sleep(1); // wait one second
            }
            state = 1; // change to next state
        } else if (state == 1) { // yellow light
            printf("YELLOW\n");
            for (int i = 0; i < yellow_time; i++) {
                printf("%d\n", i); // print countdown
                sleep(1); // wait one second
            }
            state = 2; // change to next state
        } else { // green light
            printf("GREEN\n");
            for (int i = 0; i < green_time; i++) {
                printf("%d\n", i); // print countdown
                sleep(1); // wait one second
            }
            state = 0; // change to next state
        }
    }
    return 0;
}