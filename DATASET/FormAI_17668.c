//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Set initial state of traffic lights
    int green_time = 10;
    int yellow_time = 3;
    int red_time = 15;
    int current_state = 1; // 1 = green, 2 = yellow, 3 = red
    
    // Loop infinitely
    while(1) {
        if(current_state == 1) { // GREEN state
            printf("Green light is on for %d seconds.\n", green_time);
            sleep(green_time); // Sleep for the duration of green light
            
            // Randomly determine whether to change to yellow or red
            int next_state = rand() % 2 + 2;
            if(next_state == 2) { // YELLOW state
                printf("Yellow light is on for %d seconds.\n", yellow_time);
                sleep(yellow_time); // Sleep for the duration of yellow light
            } else { // RED state
                printf("Red light is on for %d seconds.\n", red_time);
                sleep(red_time); // Sleep for the duration of red light
            }
            current_state = next_state;
            
        } else if(current_state == 2) { // YELLOW state
            printf("Yellow light is on for %d seconds.\n", yellow_time);
            sleep(yellow_time); // Sleep for the duration of yellow light
            
            // Change to RED state
            printf("Red light is on for %d seconds.\n", red_time);
            sleep(red_time); // Sleep for the duration of red light
            current_state = 3;
            
        } else { // RED state
            printf("Red light is on for %d seconds.\n", red_time);
            sleep(red_time); // Sleep for the duration of red light
            
            // Change to GREEN state
            printf("Green light is on for %d seconds.\n", green_time);
            sleep(green_time); // Sleep for the duration of green light
            
            // Randomly determine whether to change to yellow or not
            int next_state = rand() % 2 + 1;
            if(next_state == 2) { // YELLOW state
                printf("Yellow light is on for %d seconds.\n", yellow_time);
                sleep(yellow_time); // Sleep for the duration of yellow light
            }
            current_state = next_state;
        }
    }
    
    return 0;
}