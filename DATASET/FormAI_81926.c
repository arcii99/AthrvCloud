//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define RED_LIGHT 0
#define GREEN_LIGHT 1
#define YELLOW_LIGHT 2

// Function to change current light
void changeLight(int* currentLight) {
    switch (*currentLight) {
        case RED_LIGHT:
            *currentLight = GREEN_LIGHT;
            break;
        case GREEN_LIGHT:
            *currentLight = YELLOW_LIGHT;
            break;
        case YELLOW_LIGHT:
            *currentLight = RED_LIGHT;
            break;
    }
}

int main() {
    int currentLight = RED_LIGHT;
    printf("Starting Traffic Light Controller\n");

    while (true) {
        switch (currentLight) {
            case RED_LIGHT:
                printf("RED light ON\n");
                sleep(5); // wait for 5 seconds
                break;

            case YELLOW_LIGHT:
                printf("YELLOW light ON\n");
                sleep(2); // wait for 2 seconds
                break;

            case GREEN_LIGHT:
                printf("GREEN light ON\n");
                sleep(8); // wait for 8 seconds
                break;
        }

        changeLight(&currentLight); // change light
    }
    return 0;
}