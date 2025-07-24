//FormAI DATASET v1.0 Category: Smart home automation ; Style: excited
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool bedroomLight = false;
    bool kitchenLight = false;

    printf("Welcome to your Smart Home!\n");

    while(true) {
        printf("\n");

        printf("Enter '1' to toggle bedroom light\n");
        printf("Enter '2' to toggle kitchen light\n");
        printf("Enter '3' to end the program\n");

        int userInput;
        scanf("%d", &userInput);

        if(userInput == 1) {
            if(bedroomLight) {
                printf("Turning off bedroom light\n");
                bedroomLight = false;
            } else {
                printf("Turning on bedroom light\n");
                bedroomLight = true;
            }
        } else if(userInput == 2) {
            if(kitchenLight) {
                printf("Turning off kitchen light\n");
                kitchenLight = false;
            } else {
                printf("Turning on kitchen light\n");
                kitchenLight = true;
            }
        } else if(userInput == 3) {
            printf("Ending program. Goodbye!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}