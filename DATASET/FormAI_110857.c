//FormAI DATASET v1.0 Category: Smart home light control ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int light = 0;

    printf("Welcome to Retro Smart Home Light Control\n\n");

    while(1) {
        printf("Enter a command (on, off, status, quit): ");
        char cmd[10];
        scanf("%s", cmd);

        if(strcmp(cmd, "on") == 0) {
            light = 1;
            printf("Light turned on\n");
        } else if(strcmp(cmd, "off") == 0) {
            light = 0;
            printf("Light turned off\n");
        } else if(strcmp(cmd, "status") == 0) {
            if(light) {
                printf("Light is on\n");
            } else {
                printf("Light is off\n");
            }
        } else if(strcmp(cmd, "quit") == 0) {
            printf("Exiting Retro Smart Home Light Control\n");
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}