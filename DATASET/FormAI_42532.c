//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("Please enter your command:\n");
    
    char command[50];
    scanf("%s", command);

    if (strcmp(command, "move up") == 0) {
        printf("Drone moving up...\n");
    } else if (strcmp(command, "move down") == 0) {
        printf("Drone moving down...\n");
    } else if (strcmp(command, "turn left") == 0) {
        printf("Drone turning left...\n");
    } else if (strcmp(command, "turn right") == 0) {
        printf("Drone turning right...\n");
    } else if (strcmp(command, "move forward") == 0) {
        printf("Drone moving forward...\n");
    } else if (strcmp(command, "move backward") == 0) {
        printf("Drone moving backward...\n");
    } else if (strcmp(command, "take picture") == 0) {
        printf("Drone taking picture...\n");
    } else {
        printf("Sorry, I cannot understand your command. Please try again.\n");
    }

    return 0;
}