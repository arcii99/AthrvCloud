//FormAI DATASET v1.0 Category: Smart home light control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    bool isLightOn = false;

    while (true) {
        printf("Welcome to the Smart Home Light Control app!\n");
        printf("What would you like to do?\n");
        printf("1. Turn the light on?\n");
        printf("2. Turn the light off?\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (!isLightOn) {
                printf("Turning the light on...\n");
                isLightOn = true;
            } else {
                printf("The light is already on!\n");
            }
        } else if (choice == 2) {
            if (isLightOn) {
                printf("Turning the light off...\n");
                isLightOn = false;
            } else {
                printf("The light is already off!\n");
            }
        } else if (choice == 3) {
            printf("Goodbye! Thanks for using Smart Home Light Control app.\n");
            exit(0);
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}