//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ATTEMPTS 3
#define MAX_PASSWORD_LENGTH 20

bool is_incorrect_password(char *password) {
    int incorrect_passwords = 0;
    FILE *file = fopen("medieval_logs.txt", "r");

    if (!file) {
        printf("Unable to open logs.\n");
        exit(1);
    }

    char line[MAX_PASSWORD_LENGTH];
    while (fgets(line, MAX_PASSWORD_LENGTH, file) != NULL) {
        if (strcmp(line, password) == 0) {
            incorrect_passwords++;

            if (incorrect_passwords >= MAX_ATTEMPTS) {
                printf("Intruder detected!\n");
                fclose(file);
                return true;
            }
        }
    }

    fclose(file);
    return false;
}

void log_attempt(char *password) {
    FILE *file = fopen("medieval_logs.txt", "a");

    if (!file) {
        printf("Unable to open logs.\n");
        exit(1);
    }

    fprintf(file, "%s", password);
    fclose(file);
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    bool intruder_detected = false;
    printf("Enter the secret password to proceed: ");

    while (fgets(password, MAX_PASSWORD_LENGTH, stdin) != NULL) {
        password[strcspn(password, "\n")] = '\0';

        if (is_incorrect_password(password)) {
            intruder_detected = true;
            break;
        } else {
            printf("Access granted.\n");
        }

        log_attempt(password);
        printf("Enter the secret password to proceed: ");
    }

    if (intruder_detected) {
        printf("Access denied.\n");
    }

    return 0;
}