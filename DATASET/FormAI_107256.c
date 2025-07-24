//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include <stdio.h>

#define MAX_ATTEMPTS 3
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int attempts = 0;

    printf("Welcome to the secure system!\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("Please enter your username: ");
        scanf("%s", username);
        printf("Please enter your password: ");
        scanf("%s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
            printf("\nAccess granted!\n");
            break;
        }
        else {
            printf("\nAccess denied!\n");
            attempts++;
            if (attempts == MAX_ATTEMPTS) {
                printf("Maximum login attempts reached. Please try again later.\n");
            }
        }
    }

    return 0;
}