//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTEMPTS 3

int main()
{
    char password[10], attempt[10];
    int attempts = 0;
    printf("Welcome to the Happy Intrusion Detection System!\n");
    printf("Please enter the password to continue: ");
    scanf("%s", password);
    while (attempts < MAX_ATTEMPTS) {
        printf("Enter Password Attempt #%d: ", attempts + 1);
        scanf("%s", attempt);
        if (strcmp(attempt, password) == 0) {
            printf("Welcome to the system, happy user!\n");
            return 0;
        } else {
            printf("Invalid password!\n");
            attempts++;
        }
    }
    printf("Too many incorrect attempts! The system is now locked.\n");
    return 1;
}