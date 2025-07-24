//FormAI DATASET v1.0 Category: Smart home light control ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

int main() {
    int time;
    bool lightOn = false;
    printf("Welcome to Smart Home Light Control\n");
    while (true) {
        printf("Enter time: ");
        scanf("%d", &time);
        if (time >= 0 && time <= 24) {
            if (time >= 18 || time < 6) {
                lightOn = true;
                printf("It's dark outside! Turning on lights...\n");
            } else {
                lightOn = false;
                printf("It's bright outside! Turning off lights...\n");
            }
        } else {
            printf("Invalid time! Please enter time between 0 and 24.\n");
        }
        printf("Light status: %s\n", lightOn ? "On" : "Off");
        printf("Do you want to continue? (Y/N)\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'N' || choice == 'n') {
            break;
        }
    }
    return 0;
}