//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int main(void) {
    // Cyberpunk style color scheme
    int yellow_time = 2; // The yellow light stays on for 2 seconds
    int green_time = 10; // The green light stays on for 10 seconds
    int red_time = 5; // The red light stays on for 5 seconds
    
    int current_light = RED;
    int time_remaining = red_time;

    // Seed the random number generator
    srand(time(NULL));

    // Infinite loop to simulate a traffic light controller
    while (1) {
        // Decrement the time remaining in the current state
        time_remaining--;

        // If the time reaches 0, switch to the next light
        if (time_remaining == 0) {
            switch (current_light) {
                case RED:
                    current_light = GREEN;
                    time_remaining = green_time;
                    printf("\033[1;31mRED\033[0m -> \033[1;32mGREEN\033[0m\n");
                    break;

                case YELLOW:
                    if (rand()%2) {
                        current_light = RED;
                        time_remaining = red_time;
                        printf("\033[1;33mYELLOW\033[0m -> \033[1;31mRED\033[0m\n");
                    }
                    else {
                        current_light = GREEN;
                        time_remaining = green_time;
                        printf("\033[1;33mYELLOW\033[0m -> \033[1;32mGREEN\033[0m\n");
                    }
                    break;

                case GREEN:
                    current_light = YELLOW;
                    time_remaining = yellow_time;
                    printf("\033[1;32mGREEN\033[0m -> \033[1;33mYELLOW\033[0m\n");
                    break;
            }
        }

        // Sleep for 1 second to simulate the passage of time
        sleep(1);
    }

    return 0;
}