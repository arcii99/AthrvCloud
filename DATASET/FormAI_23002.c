//FormAI DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>

int main() {

    int lightStatus = 0;

    printf("Welcome to the Smart Home Light Control System!\n");
    printf("Enter 1 to turn on the lights\n");
    printf("Enter 2 to turn off the lights\n");
    printf("Enter 0 to exit\n");

    while(1) {
        int option;
        printf("\nEnter your option: ");
        scanf("%d", &option);

        if(option == 1) {
            lightStatus = 1; // Turn lights on
            printf("Lights turned on\n");
        } else if(option == 2) {
            lightStatus = 0; // Turn lights off
            printf("Lights turned off\n");
        } else if(option == 0) {
            printf("Exiting Smart Home Light Control System...\n");
            break;
        } else {
            printf("Invalid option, please try again\n");
        }
    }

    return 0;
}