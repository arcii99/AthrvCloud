//FormAI DATASET v1.0 Category: Smart home light control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int light_status = 0; // Light is initially off
    char command[20];
    printf("Welcome to Smart Home Light Control System.\n");
    printf("Type 'on' to turn on the light, or 'off' to turn off the light.\n");
    while (1) { // Infinite loop until user exits
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "on") == 0) {
            if (light_status == 1) {
                printf("The light is already on.\n");
            } else {
                printf("Turning on the light...\n");
                light_status = 1;
            }
        } else if (strcmp(command, "off") == 0) {
            if (light_status == 0) {
                printf("The light is already off.\n");
            } else {
                printf("Turning off the light...\n");
                light_status = 0;
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break; // Exit the program
        } else {
            printf("Invalid command. Try again.\n");
        }
    }
    return 0;
}