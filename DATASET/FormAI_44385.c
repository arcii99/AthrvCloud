//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TIME 60
#define GREEN_TIME 30
#define YELLOW_TIME 5
#define RED_TIME 25

int main() {
    srand(time(NULL));  // initialize random seed
    
    int total_time = 0;  // variable to store total time elapsed
    
    // variables to keep track of time left for each color
    int green_time_left = 0;
    int yellow_time_left = 0;
    int red_time_left = 0;
    
    // variables to keep track of the current color and its state
    int current_color = 0;
    int current_state = 0;  // 0 for inactive, 1 for active
    
    // main loop to simulate traffic lights
    while (total_time <= MAX_TIME) {
        // print current time and color
        printf("Total time elapsed: %d seconds\n", total_time);
        printf("Current color: ");
        switch (current_color) {
            case 0:
                printf("GREEN\n");
                break;
            case 1:
                printf("YELLOW\n");
                break;
            case 2:
                printf("RED\n");
                break;
        }
        
        // update time left for current color
        switch (current_color) {
            case 0:
                if (green_time_left > 0) {
                    green_time_left--;
                } else {
                    current_color++;
                    current_state = 0;
                }
                break;
            case 1:
                if (yellow_time_left > 0) {
                    yellow_time_left--;
                } else {
                    current_color++;
                    current_state = 0;
                }
                break;
            case 2:
                if (red_time_left > 0) {
                    red_time_left--;
                } else {
                    current_color = 0;
                    current_state = 0;
                }
                break;
        }
        
        // check if it is time to switch to next state
        if (current_state == 0 && current_color == 0 && green_time_left == 0) {
            current_state = 1;
            green_time_left = GREEN_TIME;
        } else if (current_state == 0 && current_color == 1 && yellow_time_left == 0) {
            current_state = 1;
            yellow_time_left = YELLOW_TIME;
        } else if (current_state == 0 && current_color == 2 && red_time_left == 0) {
            current_state = 1;
            red_time_left = RED_TIME;
        }
        
        // randomize the next car arrival time
        int next_arrival_time = rand() % 11 + 5;  // between 5 and 15 seconds
        
        // simulate car waiting
        for (int i = 0; i < next_arrival_time; i++) {
            printf(".");
            fflush(stdout);  // flush output buffer to display dots
            sleep(1);  // wait for 1 second
            total_time++;
        }
        
        printf("\n");
    }
    
    printf("Simulation finished!\n");
    
    return 0;  // exit program
}