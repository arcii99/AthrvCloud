//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: lively
#include <stdio.h>

#define MAX_ATTEMPTS 3 // Maximum attempts to log in.
#define MAX_PASSWORD_LENGTH 15 // Maximum password length.
#define USERNAME "admin" // The username of the account to log in.

int main()
{
    int attempts = 0; // Counter for the number of login attempts.
    char password[MAX_PASSWORD_LENGTH]; // Array to store the user's password attempt.

    printf("Welcome to the Intrusion Detection System!\n");
    printf("Please enter your username: ");
    char username[10];
    scanf("%s", username);
    if(strcmp(USERNAME, username) == 0){ // Check if the usernames match.
        printf("\n");
        while(attempts < MAX_ATTEMPTS){ // Start a loop to allow multiple attempts.
            printf("Please enter your password (%d attempts remaining): ", MAX_ATTEMPTS-attempts);
            scanf("%s", password);
            if(strcmp("password123", password) == 0){ // Check if the password is correct.
                printf("\nAccess granted. Welcome, %s.\n", username);
                break; // Exit the loop if the correct password is entered.
            }
            attempts++; // Increment the number of login attempts.
        }
        if(attempts >= MAX_ATTEMPTS){ // Check if the maximum number of attempts have been reached.
            printf("\nToo many login attempts. Your account has been locked.\n");
        }
    }
    else{
        printf("\nAccess denied. Invalid username.\n");
    }

    return 0;
}