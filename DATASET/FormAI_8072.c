//FormAI DATASET v1.0 Category: Robot movement control ; Style: cheerful
#include <stdio.h>

int main() {
    int command;

    printf("Welcome to the HappyBot movement control program!\n");
    printf("Please enter a command (1-6): ");

    scanf("%d", &command);

    switch (command) {
        case 1:
            printf("Moving forward with a smile on my face!\n");
            break;
        case 2:
            printf("Turning left with a cheerful spin!\n");
            break;
        case 3:
            printf("Turning right with a joyful hop!\n");
            break;
        case 4:
            printf("Backing up with a giggle!\n");
            break;
        case 5:
            printf("Stopping with a contented sigh!\n");
            break;
        case 6:
            printf("Spinning in circles with glee!\n");
            break;
        default:
            printf("Invalid command! Please try again.\n");
    }

    return 0;
}