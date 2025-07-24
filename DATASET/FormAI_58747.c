//FormAI DATASET v1.0 Category: Smart home light control ; Style: rigorous
#include <stdio.h>

int main() {
    // Light status initialization
    int livingRoomLight = 0;
    int kitchenLight = 0;
    int bedroomLight = 0;

    printf("Welcome to Smart Home Light Control!\n");

    while (1) {
        int option;

        printf("\nPlease select an option:\n");
        printf("1. Turn living room light ON/OFF\n");
        printf("2. Turn kitchen light ON/OFF\n");
        printf("3. Turn bedroom light ON/OFF\n");
        printf("4. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                livingRoomLight = !livingRoomLight;
                printf("Living room light is %s\n", livingRoomLight ? "ON" : "OFF");
                break;
            case 2:
                kitchenLight = !kitchenLight;
                printf("Kitchen light is %s\n", kitchenLight ? "ON" : "OFF");
                break;
            case 3:
                bedroomLight = !bedroomLight;
                printf("Bedroom light is %s\n", bedroomLight ? "ON" : "OFF");
                break;
            case 4:
                printf("Exiting Smart Home Light Control...\n");
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
}