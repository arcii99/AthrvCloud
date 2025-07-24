//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

void turn_on_light(int light) {
    switch(light) {
        case RED:
            printf("RED light is ON\n");
            break;
        case YELLOW:
            printf("YELLOW light is ON\n");
            break;
        case GREEN:
            printf("GREEN light is ON\n");
            break;
        default:
            break;
    }   
}

void turn_off_light(int light) {
    switch(light) {
        case RED:
            printf("RED light is OFF\n");
            break;
        case YELLOW:
            printf("YELLOW light is OFF\n");
            break;
        case GREEN:
            printf("GREEN light is OFF\n");
            break;
        default:
            break;
    }   
}

int main() {
    int current_light = RED;
    int seconds = 6; // time for each light

    while(1) { // infinite loop
        turn_on_light(current_light);
        sleep(seconds);
        turn_off_light(current_light);

        switch(current_light) {
            case RED:
                current_light = GREEN;
                break;
            case YELLOW:
                current_light = RED;
                break;
            case GREEN:
                current_light = YELLOW;
                break;
            default:
                break;
        }
    }
    return 0;
}