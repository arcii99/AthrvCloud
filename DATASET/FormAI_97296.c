//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 50
#define MAX_BUFFER_LENGTH 100

typedef struct {
    int x;
    int y;
} coordinates;

int main() {
    char command[MAX_COMMAND_LENGTH];
    coordinates position = {0, 0};
    printf("Enter a command: ");

    while (fgets(command, MAX_COMMAND_LENGTH, stdin) != NULL) {
        // Remove new line character from command
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "UP") == 0) {
            position.y += 1;
        } else if (strcmp(command, "DOWN") == 0) {
            position.y -= 1;
        } else if (strcmp(command, "RIGHT") == 0) {
            position.x += 1;
        } else if (strcmp(command, "LEFT") == 0) {
            position.x -= 1;
        } else {
            printf("Invalid command!\n");
        }

        // Print current position
        char buffer[MAX_BUFFER_LENGTH];
        snprintf(buffer, MAX_BUFFER_LENGTH, "Current position: (%d, %d)\n", position.x, position.y);
        printf("%s", buffer);

        printf("Enter a command: ");
    }

    return 0;
}