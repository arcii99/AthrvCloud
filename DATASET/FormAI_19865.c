//FormAI DATASET v1.0 Category: Smart home automation ; Style: portable
#include <stdio.h>

// Function prototypes
void turnOnLight();
void turnOffLight();
void turnOnFan();
void turnOffFan();
void lockDoor();
void unlockDoor();
void openWindow();
void closeWindow();

int main() {
    int option;
    char yesNo;

    printf("Welcome to Smart Home Automation!\n");
    
    do {
        // Display menu options
        printf("\nPlease select an option:\n");
        printf("1. Turn on the light\n");
        printf("2. Turn off the light\n");
        printf("3. Turn on the fan\n");
        printf("4. Turn off the fan\n");
        printf("5. Lock the door\n");
        printf("6. Unlock the door\n");
        printf("7. Open the window\n");
        printf("8. Close the window\n");

        // Get user choice
        scanf("%d", &option);

        // Execute user choice
        switch(option) {
            case 1:
                turnOnLight();
                break;
            case 2:
                turnOffLight();
                break;
            case 3:
                turnOnFan();
                break;
            case 4:
                turnOffFan();
                break;
            case 5:
                lockDoor();
                break;
            case 6:
                unlockDoor();
                break;
            case 7:
                openWindow();
                break;
            case 8:
                closeWindow();
                break;
            default:
                printf("Invalid option, please try again.\n");
        }

        // Ask user if they want to continue
        printf("\nDo you want to continue? (Y/N) ");
        scanf(" %c", &yesNo);
    } while(yesNo == 'Y' || yesNo == 'y');

    return 0;
}

void turnOnLight() {
    printf("Turning on the light.\n");
}

void turnOffLight() {
    printf("Turning off the light.\n");
}

void turnOnFan() {
    printf("Turning on the fan.\n");
}

void turnOffFan() {
    printf("Turning off the fan.\n");
}

void lockDoor() {
    printf("Locking the door.\n");
}

void unlockDoor() {
    printf("Unlocking the door.\n");
}

void openWindow() {
    printf("Opening the window.\n");
}

void closeWindow() {
    printf("Closing the window.\n");
}