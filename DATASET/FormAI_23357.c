//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define MAX_CYCLES 10

void update_lights(int current_light);
void print_lights(int curr_cycle);

int current_light = RED; 
int cycles = 0;       

int main() {
    srand(time(NULL)); 

    printf("\nStarting Traffic Light Controller\n");

    while (cycles < MAX_CYCLES) {
        print_lights(cycles);
        update_lights(current_light);
        sleep(2);
        cycles++;
    }

    printf("\nFinished Traffic Light Controller\n");

    return 0;
}

void print_lights(int curr_cycle) {
    printf("\nCycle %d:\n", curr_cycle);
    printf("Red Light: %s\n", current_light == RED ? "On" : "Off");
    printf("Yellow Light: %s\n", current_light == YELLOW ? "On" : "Off");
    printf("Green Light: %s\n", current_light == GREEN ? "On" : "Off");
}

void update_lights(int current_light) {
    switch (current_light) {
        case RED:
            current_light = GREEN;
            break;
        case YELLOW:
            current_light = RED;
            break;
        case GREEN:
            current_light = YELLOW;
            break;
    }
}