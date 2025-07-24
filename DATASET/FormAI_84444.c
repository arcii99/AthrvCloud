//FormAI DATASET v1.0 Category: Smart home automation ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>

#define LIGHTS 1
#define DOORS 2
#define ALARM 3

int main() {
    bool lightsOn = false;
    bool doorsLocked = true;
    bool alarmOn = true;
    int choice;

    printf("Welcome to the Smart Home Automation System!\n");

    while (true) {
        printf("\nWhat would you like to do?\n");
        printf("1. Turn %s the Lights\n", lightsOn ? "Off" : "On");
        printf("2. %s the Doors\n", doorsLocked ? "Unlock" : "Lock");
        printf("3. %s the Alarm\n", alarmOn ? "Deactivate" : "Activate");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case LIGHTS:
                lightsOn = !lightsOn;
                printf("Lights turned %s!\n", lightsOn ? "On" : "Off");
                break;
            case DOORS:
                doorsLocked = !doorsLocked;
                printf("Doors %s!\n", doorsLocked ? "Locked" : "Unlocked");
                break;
            case ALARM:
                alarmOn = !alarmOn;
                printf("Alarm %s!\n", alarmOn ? "Activated" : "Deactivated");
                break;
            case 4:
                printf("Thank you for using the Smart Home Automation System!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}