//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_ATTEMPTS 3

int main() {
    char password[MAX_SIZE];
    int attempts = 0;

    printf("Welcome to the Intrusion Detection System\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter the password: ");
        fgets(password, MAX_SIZE, stdin);
        password[strlen(password) - 1] = '\0'; // Remove newline character

        if (strcmp(password, "admin") == 0) {
            printf("Access granted.\n");
            break;
        } else {
            printf("Access denied. Try again.\n");
            attempts++;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Intrusion detected!\n");
        // Place code here to alert system administrators or security personnel
    }

    return 0;
}