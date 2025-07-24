//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct remoteControl {
    int upButton;
    int downButton;
    int rightButton;
    int leftButton;
    int forwardButton;
    int backwardButton;
};

int main() {
    struct remoteControl rc;
    rc.upButton = 0;
    rc.downButton = 0;
    rc.rightButton = 0;
    rc.leftButton = 0;
    rc.forwardButton = 0;
    rc.backwardButton = 0;
    char input[10];

    printf("Welcome to the C Drone Remote Control Program.\n");
    printf("Type 'help' to see available commands.\n");
    printf("Type 'exit' to end the program.\n\n");

    while(1) {
        printf("> ");
        fgets(input, 10, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character

        if(strcmp(input, "help") == 0) {
            printf("Available commands:\n");
            printf("  up\n");
            printf("  down\n");
            printf("  right\n");
            printf("  left\n");
            printf("  forward\n");
            printf("  backward\n");
            printf("  stop\n");
            printf("  exit\n");
            printf("\n");

        } else if(strcmp(input, "up") == 0) {
            rc.upButton = 1;
            printf("Moving drone up.\n");

        } else if(strcmp(input, "down") == 0) {
            rc.downButton = 1;
            printf("Moving drone down.\n");

        } else if(strcmp(input, "right") == 0) {
            rc.rightButton = 1;
            printf("Moving drone right.\n");

        } else if(strcmp(input, "left") == 0) {
            rc.leftButton = 1;
            printf("Moving drone left.\n");

        } else if(strcmp(input, "forward") == 0) {
            rc.forwardButton = 1;
            printf("Moving drone forward.\n");

        } else if(strcmp(input, "backward") == 0) {
            rc.backwardButton = 1;
            printf("Moving drone backward.\n");

        } else if(strcmp(input, "stop") == 0) {
            rc.upButton = 0;
            rc.downButton = 0;
            rc.rightButton = 0;
            rc.leftButton = 0;
            rc.forwardButton = 0;
            rc.backwardButton = 0;
            printf("Stopping drone.\n");

        } else if(strcmp(input, "exit") == 0) {
            printf("Ending program.\n");
            break;

        } else {
            printf("Invalid command. Type 'help' to see available commands.\n");
        }

        if(rc.upButton == 1 || rc.downButton == 1 || rc.rightButton == 1 || rc.leftButton == 1 || rc.forwardButton == 1 || rc.backwardButton == 1) {
            printf("Drone is in motion.\n");
        }
    }

    return 0;
}