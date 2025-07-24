//FormAI DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    int bedroom_light = 0;
    int living_room_light = 0;
    int bathroom_light = 0;
    int kitchen_light = 0;
    int door_status = 0;

    printf("Welcome to Smart Home Automation App!\n");

    while(1) {
        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Control bedroom light\n");
        printf("2. Control living room light\n");
        printf("3. Control bathroom light\n");
        printf("4. Control kitchen light\n");
        printf("5. Check door status\n");
        printf("6. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(bedroom_light == 0) {
                    printf("Turning on bedroom light.\n");
                    bedroom_light = 1;
                } else {
                    printf("Turning off bedroom light.\n");
                    bedroom_light = 0;
                }
                break;
            case 2:
                if(living_room_light == 0) {
                    printf("Turning on living room light.\n");
                    living_room_light = 1;
                } else {
                    printf("Turning off living room light.\n");
                    living_room_light = 0;
                }
                break;
            case 3:
                if(bathroom_light == 0) {
                    printf("Turning on bathroom light.\n");
                    bathroom_light = 1;
                } else {
                    printf("Turning off bathroom light.\n");
                    bathroom_light = 0;
                }
                break;
            case 4:
                if(kitchen_light == 0) {
                    printf("Turning on kitchen light.\n");
                    kitchen_light = 1;
                } else {
                    printf("Turning off kitchen light.\n");
                    kitchen_light = 0;
                }
                break;
            case 5:
                if(door_status == 0) {
                    printf("Door is closed.\n");
                } else {
                    printf("Door is open.\n");
                }
                break;
            case 6:
                printf("Exiting the Smart Home Automation App.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}