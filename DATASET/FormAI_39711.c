//FormAI DATASET v1.0 Category: Smart home automation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int livingRoomLights = 0;
    int kitchenLights = 0;
    int bedroomLights = 0;

    printf("Welcome to your Smart Home Automation System!\n");

    while (1) {
        printf("\nWhat would you like to do?\n1. Turn on/off living room lights\n2. Turn on/off kitchen lights\n3. Turn on/off bedroom lights\n4. Exit\n\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                livingRoomLights = !livingRoomLights;
                printf("Living room lights turned %s\n", livingRoomLights ? "on" : "off");
                break;
            case 2:
                kitchenLights = !kitchenLights;
                printf("Kitchen lights turned %s\n", kitchenLights ? "on" : "off");
                break;
            case 3:
                bedroomLights = !bedroomLights;
                printf("Bedroom lights turned %s\n", bedroomLights ? "on" : "off");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}