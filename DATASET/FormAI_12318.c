//FormAI DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[20];
    int light = 0;

    printf("Welcome to the Smart Home Light Control program!\n");

    while (1) {

        printf("Current light level is %d.\n", light);

        printf("Enter a command (on, off, up, down, exit): ");
        scanf("%s", input);

        if (strcmp(input, "on") == 0) {
            light = 100;
            printf("Light turned on.\n");
        } else if (strcmp(input, "off") == 0) {
            light = 0;
            printf("Light turned off.\n");
        } else if (strcmp(input, "up") == 0) {
            if (light < 100) {
                light += 10;
                printf("Light level increased.\n");
            } else {
                printf("Light level already at maximum.\n");
            }
        } else if (strcmp(input, "down") == 0) {
            if (light > 0) {
                light -= 10;
                printf("Light level decreased.\n");    
            } else {
                printf("Light level already at minimum.\n");
            }
        } else if (strcmp(input, "exit") == 0) {
            printf("Exiting Smart Home Light Control program...\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}