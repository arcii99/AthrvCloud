//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LEN 20
#define MAX_ATTEMPTS 3

int main() {
    char password[MAX_PASSWORD_LEN];
    int attempts = 0;
    int is_intruder_detected = 0;

    printf("Enter your password: ");

    while (fgets(password, MAX_PASSWORD_LEN, stdin)) {
        password[strcspn(password, "\n")] = 0;  // Remove trailing newline character

        if (strcmp(password, "password123") == 0) {
            printf("Access granted!\n");
            break;
        } else {
            ++attempts;

            if (attempts == MAX_ATTEMPTS) {
                printf("Intruder detected! Locking system...\n");
                is_intruder_detected = 1;
                break;
            }

            printf("Access denied. Please try again (%d/%d)\n", attempts, MAX_ATTEMPTS);
            printf("Enter your password: ");
        }
    }

    // Notify the authorities if an intruder was detected
    if (is_intruder_detected) {
        // TODO: Implement notification logic
    }

    return 0;
}