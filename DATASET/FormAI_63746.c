//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// function to move drone forward
void move_forward() {
    printf("Moving drone forward\n");
    // code to send signal to drone to move forward
}

// function to move drone backward
void move_backward() {
    printf("Moving drone backward\n");
    // code to send signal to drone to move backward
}

// function to turn drone left
void turn_left() {
    printf("Turning drone left\n");
    // code to send signal to drone to turn left
}

// function to turn drone right
void turn_right() {
    printf("Turning drone right\n");
    // code to send signal to drone to turn right
}

int main() {
    int option;
    // print menu options
    printf("Welcome to drone remote control\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Quit\n");

    do {
        printf("Enter a choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                move_forward();
                break;
            
            case 2:
                move_backward();
                break;
            
            case 3:
                turn_left();
                break;

             case 4:
                turn_right();
                break;

            case 5:
                printf("Exiting program");
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(option != 5);

    return 0;
}