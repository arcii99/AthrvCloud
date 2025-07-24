//FormAI DATASET v1.0 Category: Smart home light control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //for boolean data type

int main(void) {
    bool lights_on = false; //initialize light state
    int choice; //user choice

    printf("Welcome to Smart Home Light Control System!\n");

    do {
        //menu
        printf("\nSelect an option:\n");
        printf("1. Turn on lights\n");
        printf("2. Turn off lights\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1: //turn on lights
                if (lights_on) { //check if already on
                    printf("\nLights are already on.\n");
                } else {
                    printf("\nTurning on lights...\n");
                    lights_on = true; //update light state
                }
                break;
            case 2: //turn off lights
                if (!lights_on) { //check if already off
                    printf("\nLights are already off.\n");
                } else {
                    printf("\nTurning off lights...\n");
                    lights_on = false; //update light state
                }
                break;
            case 3: //exit program
                printf("\nExiting Smart Home Light Control System...\n");
                break;
            default: //invalid choice
                printf("\nInvalid choice. Please select again.\n");
                break;
        }
    } while (choice != 3); //keep loop running until user chooses to exit

    return 0;
}