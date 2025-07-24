//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Ada Lovelace
// This program detects intrusions in a computer system using a simple algorithm inspired by Ada Lovelace.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    printf("Welcome to the intrusion detection system! Please enter the password: ");
    fgets(input, 100, stdin);

    // Remove the newline character from the input
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    // Check if the password is correct
    if (strcmp(input, "AdaLovelace123") == 0) {
        printf("Password correct. The system is now scanning for intrusions.\n");

        int time_since_last_login = 3; // Placeholder value
        int num_failed_logins = 0;
        int network_traffic = 100; // Placeholder value
        int num_connections = 8; // Placeholder value
        int total_process_memory = 500; // Placeholder value

        // Check for possible intrusions based on the input values
        if (time_since_last_login > 5) {
            printf("Possible intrusion: Time since last login is greater than 5.\n");
        }
        if (num_failed_logins > 3) {
            printf("Possible intrusion: More than 3 failed login attempts.\n");
        }
        if (network_traffic > 1000) {
            printf("Possible intrusion: High network traffic.\n");
        }
        if (num_connections > 10) {
            printf("Possible intrusion: Too many active connections.\n");
        }
        if (total_process_memory > 1000) {
            printf("Possible intrusion: High memory usage.\n");
        }
    } else {
        printf("Password incorrect. Access denied.\n");
    }

    return 0;
}