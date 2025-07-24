//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: standalone
#include <stdio.h>
#include <string.h>

//Function to display the drone's status
void display_status(int battery, int height, int distance) {
    printf("Drone Status:\n");
    printf("Battery Level: %d%%\n", battery);
    printf("Height From Ground: %dm\n", height);
    printf("Distance Traveled: %dm\n", distance);
}

//Function to control the drone's movement
void move_drone(char direction, int *x, int *y) {
    switch (direction) {
        case 'F':
            *y += 1;
            break;
        case 'B':
            *y -= 1;
            break;
        case 'L':
            *x -= 1;
            break;
        case 'R':
            *x += 1;
            break;
        default:
            printf("Invalid Command!\n");
    }
}

int main() {
    int battery = 100, height = 0, distance = 0;
    int x = 0, y = 0;
    char command[50];
    
    printf("Welcome to the C Drone Remote Control!\n");
    printf("Enter 'HELP' for a list of commands.\n");
    
    while (battery > 0) {
        printf("\nEnter Command: ");
        fgets(command, 50, stdin);
        
        if (strcmp(command, "HELP\n") == 0) {
            printf("\nCommands:\n");
            printf("F - Move Forward\n");
            printf("B - Move Backward\n");
            printf("L - Move Left\n");
            printf("R - Move Right\n");
            printf("U - Increase Height\n");
            printf("D - Decrease Height\n");
            printf("STATUS - Display Drone Status\n");
            printf("HELP - Display List of Commands\n");
            printf("EXIT - Exit the Program\n");
        }
        else if (strcmp(command, "STATUS\n") == 0) {
            display_status(battery, height, distance);
        }
        else if (strcmp(command, "U\n") == 0) {
            height += 5;
            distance += 1;
            battery -= 1;
            printf("Drone Going Up...\n");
        }
        else if (strcmp(command, "D\n") == 0) {
            if (height > 5) {
                height -= 5;
                distance += 1;
                battery -= 1;
                printf("Drone Going Down...\n");
            }
            else {
                printf("Cannot Decrease Height Any Further!\n");
            }
        }
        else if (strcmp(command, "EXIT\n") == 0) {
            break;
        }
        else {
            move_drone(command[0], &x, &y);
            distance += 1;
            battery -= 1;
            printf("Drone Moving %c...\n", command[0]);
        }
    }
    
    printf("\nDrone Battery Low! Returning to Base...\n");
    printf("Drone Distance Traveled: %dm\n", distance);
    printf("Drone Final Position: (%d,%d,%d)\n", x, y, height);
    display_status(battery, height, distance);
    printf("Thank You for Using C Drone Remote Control!\n");
    
    return 0;
}