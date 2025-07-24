//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>
int main() {
    char user_input, direction;    // Taking input from user to move the drone
    int axis_x = 0, axis_y = 0;    // Initial position of drone
    printf("Welcome to the Drone Remote Control Program!\n\n");
    do{
        printf("Use keys 'u' for up, 'd' for down, 'r' for right, 'l' for left\n");
        printf("Enter the direction: ");
        scanf("%c", &user_input);
        fflush(stdin);              // To clear the input buffer
        if(user_input == 'u') {     // Move the drone up
            printf("\nMoving the drone up...\n");
            axis_y++;               // Increase y-axis value by 1
        } else if(user_input == 'd') { // Move the drone down
            printf("\nMoving the drone down...\n");
            axis_y--;               // Decrease y-axis value by 1
        } else if(user_input == 'r') { // Move the drone right
            printf("\nMoving the drone right...\n");
            axis_x++;               // Increase x-axis value by 1
        } else if(user_input == 'l') { // Move the drone left
            printf("\nMoving the drone left...\n");
            axis_x--;               // Decrease x-axis value by 1
        } else {                // Handle invalid input
            printf("\nInvalid Input! Please try again...\n");
        }
        printf("Drone Current Position: (%d, %d)\n", axis_x, axis_y);
        printf("\nDo you want to continue controlling the drone? (y/n): ");
        scanf(" %c", &direction);
    } while(direction != 'n');  // Keep running until user is done with controlling the drone
    printf("\nThanks for using Drone Remote Control Program!");
    return 0;
}