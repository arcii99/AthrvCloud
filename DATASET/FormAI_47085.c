//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int green = 1;
    int yellow = 2;
    int red = 3;
    int current_light = red;
    
    printf("The traffic light is red.\n");
    
    while (1) {
        sleep(1);

        if (current_light == green) {
            printf("The traffic light is green.\n");
            current_light = yellow;
        } else if (current_light == yellow) {
            printf("The traffic light is yellow.\n");
            current_light = red;
        } else if (current_light == red) {
            printf("The traffic light is red.\n");
            current_light = green;
        }
    }

    return 0;
}