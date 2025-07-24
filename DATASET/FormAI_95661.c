//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[10];
    char user_input[10];
    char disarm_code[] = "1234";
    char arm_code[] = "5678";
    int drone_armed = 0;

    // Prompt the user to enter a password
    printf("Enter the password to access the drone remote control: ");
    scanf("%s", password);

    // Check if the password is correct
    if (strcmp(password, "mysecretpassword") != 0) {
        printf("Incorrect password. Exiting program.\n");
        exit(0);
    }

    // Password is correct, prompt the user to enter a command
    while (1) {
        printf("Enter a command (arm, disarm, or exit): ");
        scanf("%s", user_input);

        if (strcmp(user_input, "arm") == 0) {
            // Arm the drone
            if (drone_armed == 0) {
                printf("Enter the arm code: ");
                scanf("%s", password);

                if (strcmp(password, arm_code) != 0) {
                    printf("Incorrect arm code. Exiting program.\n");
                    exit(0);
                }

                drone_armed = 1;
                printf("Drone is armed.\n");
            } else {
                printf("Drone is already armed.\n");
            }
        } else if (strcmp(user_input, "disarm") == 0) {
            // Disarm the drone
            if (drone_armed == 1) {
                printf("Enter the disarm code: ");
                scanf("%s", password);

                if (strcmp(password, disarm_code) != 0) {
                    printf("Incorrect disarm code. Drone self-destructing.\n");
                    exit(0);
                }

                drone_armed = 0;
                printf("Drone is disarmed.\n");
            } else {
                printf("Drone is already disarmed.\n");
            }
        } else if (strcmp(user_input, "exit") == 0) {
            // Exit the program
            printf("Exiting program.\n");
            exit(0);
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}