//FormAI DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <string.h>

void main() {
    char password[20], saved_pass[20] = "brave123";
    int attempts = 0;

    printf("Welcome to the brave password management system\n");

    do {
        printf("Please enter your password:\n");
        scanf("%s", password);

        if(strcmp(password, saved_pass) == 0) {
            printf("Access granted!\n");

            // Your password management code goes here

            break;
        } else {
            attempts++;
            printf("Incorrect password. Please try again.\n");
        }
    } while(attempts < 3);

    if(attempts == 3) {
        printf("Maximum login attempts reached. Goodbye!\n");
    }
}