//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN 0
#define YELLOW 1
#define RED  2

int main()
{
    srand(time(NULL));
    int lightState = GREEN;
    int num = 0;
    double timeElapsed = 0.0;
    
    printf("Starting Traffic Light Controller...\n\n");
    
    while (1) {
        num = (rand() % 10) + 1;
        printf("[Time Elapsed: %.1f seconds] ", timeElapsed);
        
        if (lightState == GREEN && num == 1) {
            printf("Green Light: Changing to Yellow\n");
            lightState = YELLOW;
        } else if (lightState == YELLOW && num == 7) {
            printf("Yellow Light: Changing to Red\n");
            lightState = RED;
        } else if (lightState == RED && num == 4) {
            printf("Red Light: Changing to Green\n");
            lightState = GREEN;
        }
        
        if (lightState == GREEN) {
            printf("Traffic Signal: Green\n");
        } else if (lightState == YELLOW) {
            printf("Traffic Signal: Yellow\n");
        } else if (lightState == RED) {
            printf("Traffic Signal: Red\n");
        }
        
        printf("\n");
        timeElapsed += 5.0;
        sleep(5);
    }
    
    return 0;
}