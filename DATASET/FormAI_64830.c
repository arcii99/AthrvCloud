//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_ATTEMPTS 3

void alert_detection(char *msg) {
    printf("Intrusion detected: %s\n", msg);
}

int main() {
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter password: ");
        char password[100];
        scanf("%99s", password);

        // Perform password validation here
        if (strcmp(password, "correct_password") == 0) {
            printf("Access granted.\n");
            return 0;
        }

        attempts++;
        if (attempts == MAX_ATTEMPTS) {
            alert_detection("Max attempts reached.");
            return 1;
        }

        printf("Incorrect password. %d attempts left.\n", MAX_ATTEMPTS - attempts);
    }

    return 0;
}