//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void green_light(void);
void yellow_light(void);
void red_light(void);

int main(void) {
    int current_state = 0;
    /* 0 = green, 1 = yellow, 2 = red */
    
    while(1) {
        switch(current_state) {
            case 0:
                green_light();
                current_state = 1;
                break;
            case 1:
                yellow_light();
                current_state = 2;
                break;
            case 2:
                red_light();
                current_state = 0;
                break;
            default:
                printf("Error: Invalid state");
                exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}

void green_light(void) {
    printf("Green light is on\n");
    /* Implement code to turn on green light */
}

void yellow_light(void) {
    printf("Yellow light is on\n");
    /* Implement code to turn on yellow light */
}

void red_light(void) {
    printf("Red light is on\n");
    /* Implement code to turn on red light */
}