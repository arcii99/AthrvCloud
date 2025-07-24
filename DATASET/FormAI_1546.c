//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool isLightOn;
    bool isACOn;
} HomeState;

int main() {
    HomeState home = {false, false};
    int option;

    printf("Welcome to Smart Home Automation!\n");

    do {
        printf("\n============= MENU =============\n");
        printf("Current state: Light is %s | AC is %s\n", (home.isLightOn ? "ON" : "OFF"), (home.isACOn ? "ON" : "OFF"));
        printf("1. Turn the Light ON/OFF\n");
        printf("2. Turn the AC ON/OFF\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                home.isLightOn = !home.isLightOn;
                printf("%s the light\n", (home.isLightOn ? "Turned ON" : "Turned OFF"));
                break;
            }
            case 2: {
                home.isACOn = !home.isACOn;
                printf("%s the AC\n", (home.isACOn ? "Turned ON" : "Turned OFF"));
                break;
            }
            case 3: {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid input! Please try again.\n");
            }
        }
    } while(true);

    return 0;
}