//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main() {
    int delay[3] = {10, 3, 15}; // delay for red, yellow, and green lights
    int current_light = RED;
    time_t start_time = time(NULL), end_time;
    srand(time(NULL)); // initialize random seed
    
    // simulation loop
    while(1) {
        printf("Current light: ");
        switch(current_light) {
            case RED: printf("RED\n"); break;
            case YELLOW: printf("YELLOW\n"); break;
            case GREEN: printf("GREEN\n"); break;
        }
        
        printf("Cars waiting: %d\n", rand() % 20);
        
        // calculate how long the light has been on
        end_time = time(NULL);
        int time_elapsed = (int) (end_time - start_time);
        
        if(current_light == GREEN && time_elapsed >= delay[GREEN]) {
            current_light = YELLOW; // turn light yellow
            start_time = time(NULL); // reset start time
        }
        else if(current_light == YELLOW && time_elapsed >= delay[YELLOW]) {
            current_light = RED; // turn light red
            start_time = time(NULL); // reset start time
        }
        else if(current_light == RED && time_elapsed >= delay[RED]) {
            current_light = GREEN; // turn light green
            start_time = time(NULL); // reset start time
        }
        
        printf("\n");
        // sleep for one second
        for(int i = 0; i < 1e6; i++);
    }
    
    return 0;
}