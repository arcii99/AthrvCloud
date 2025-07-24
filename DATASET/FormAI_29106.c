//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void logEvent(char* event) {
    FILE* logFile = fopen("logfile.txt", "a");
    if (logFile == NULL) {
        printf("Error opening log file!\n");
        return;
    }
    fprintf(logFile, "%s\n", event);
    fclose(logFile);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter login credentials: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);

        if (strcmp(input, "admin:password\n") == 0) {
            printf("Login successful!\n");
            logEvent("Successful login");
            break;
        } else {
            printf("Login failed. Please try again.\n");
            logEvent("Failed login attempt");
            attempts++;
        }
    }

    if (attempts == 3) {
        printf("Too many failed attempts. System locked.\n");
        logEvent("System locked");
    }

    return 0;
}