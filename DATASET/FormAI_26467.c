//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

#define DURATION_RED_LIGHT 10
#define DURATION_YELLOW_LIGHT 3
#define DURATION_GREEN_LIGHT 12

#define MAX_ITERATIONS 5

int main() {
    int current_light = RED_LIGHT;
    int countdown = DURATION_RED_LIGHT;
    int iteration = 1;
    
    srand(time(NULL));
    
    while(iteration <= MAX_ITERATIONS) {
        printf("Iteration: %d\n", iteration);
        while(countdown > 0) {
            if(current_light == RED_LIGHT) {
                printf("Red light with %ds left\n", countdown);
            } else if(current_light == YELLOW_LIGHT) {
                printf("Yellow light with %ds left\n", countdown);
            } else {
                printf("Green light with %ds left\n", countdown);
            }
            usleep(1000000); // Wait 1 second
            countdown--;
        }
        
        if(current_light == RED_LIGHT) {
            current_light = GREEN_LIGHT;
            countdown = DURATION_GREEN_LIGHT;
        } else if(current_light == YELLOW_LIGHT) {
            current_light = RED_LIGHT;
            countdown = DURATION_RED_LIGHT;
            iteration++;
        } else {
            current_light = YELLOW_LIGHT;
            countdown = DURATION_YELLOW_LIGHT;
        }
    }
    printf("Traffic control program completed!\n");
    return 0;
}