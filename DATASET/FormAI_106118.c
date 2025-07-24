//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int green_time = 10; // duration of green light
    int yellow_time = 2; // duration of yellow light
    int red_time = 15; // duration of red light
    int total_time = green_time + yellow_time + red_time; // duration of complete cycle
    
    while (1) { // infinite loop
        int current_time = 0; // current time initialised to 0
        printf("Green Light\n");
        while (current_time < green_time) { // while green light is on
            printf("Time Left: %d\n", green_time - current_time);
            current_time++;
            sleep(1); // wait for 1 second
        }
        printf("Yellow Light\n");
        current_time = 0; // reset current time for yellow light
        while (current_time < yellow_time) { // while yellow light is on
            printf("Time Left: %d\n", yellow_time - current_time);
            current_time++;
            sleep(1); // wait for 1 second
        }
        printf("Red Light\n");
        current_time = 0; // reset current time for red light
        while (current_time < red_time) { // while red light is on
            printf("Time Left: %d\n", red_time - current_time);
            current_time++;
            sleep(1); // wait for 1 second
        }
    }
    return 0;
}