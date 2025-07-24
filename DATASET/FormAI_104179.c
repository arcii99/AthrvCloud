//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: post-apocalyptic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define MAX_BUFFER_SIZE 1024  // Maximum buffer size for reading input
#define MAX_PASSWORD_ATTEMPTS 3  // Maximum number of attempts to enter the correct password
#define MAX_SIZE_OF_LOG 100  // Maximum number of log entries to be stored
#define INTRUSION_THRESHOLD 3 // Maximum number of failed login attempts before triggering an intrusion alert

// Function to compare two strings without taking case into account
int stricmp(char *s1, char *s2) {
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0') {
        if(s1[i] != s2[i] && s1[i] != s2[i] + 32 && s1[i] + 32 != s2[i]) {
            return -1;
        }
        i++;
    }
    if(s1[i] != '\0' || s2[i] != '\0') {
        return -1;
    }
    return 0;
}

int main() {
    char password[20] = "Password123";  // Hard-coded password for the system
    int password_attempts = 0;  // Number of attempts to enter the correct password
    char buffer[MAX_BUFFER_SIZE];  // Buffer for reading input from the user
    char log[MAX_SIZE_OF_LOG][50];  // Array of log entries
    int log_index = 0;  // Current index in the array of log entries
    int intrusion_alert = 0;  // Flag to indicate whether an intrusion alert has been triggered
    srand(time(NULL));  // Initialize the random number generator with the current time

    // Loop until the correct password is entered or the maximum number of attempts is exceeded
    while(password_attempts < MAX_PASSWORD_ATTEMPTS) {
        printf("Enter password: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        // Remove trailing newline character from input
        buffer[strcspn(buffer, "\n")] = '\0';

        // If the password is correct, break out of the loop
        if(stricmp(buffer, password) == 0) {
            printf("Access granted.\n");
            break;
        } else {
            printf("Access denied.\n");
            password_attempts++;
        }
    }

    // If the maximum number of attempts is exceeded, exit the program
    if(password_attempts == MAX_PASSWORD_ATTEMPTS) {
        printf("Maximum number of attempts exceeded. Exiting program.\n");
        exit(0);
    }

    // Loop indefinitely to simulate a real-time intrusion detection system
    while(1) {
        // Generate random IP address and username for the log entry
        sprintf(buffer, "%d.%d.%d.%d", rand() % 256, rand() % 256, rand() % 256, rand() % 256);
        char *ip_address = strdup(buffer);
        sprintf(buffer, "user%d", rand() % 100);
        char *username = strdup(buffer);

        // Prompt the user to enter a command
        printf("Enter a command: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        // Remove trailing newline character from input
        buffer[strcspn(buffer, "\n")] = '\0';

        // Check for intrusion attempts by looking for failed login attempts
        if(stricmp(buffer, "login") == 0) {
            printf("Enter username: ");
            fgets(buffer, MAX_BUFFER_SIZE, stdin);

            // Remove trailing newline character from input
            buffer[strcspn(buffer, "\n")] = '\0';

            printf("Enter password: ");
            fgets(buffer, MAX_BUFFER_SIZE, stdin);

            // Remove trailing newline character from input
            buffer[strcspn(buffer, "\n")] = '\0';

            // If the password is incorrect, log the failed login attempt
            if(stricmp(buffer, "Password123") != 0) {
                printf("Login failed.\n");
                intrusion_alert++;

                // If the intrusion threshold is exceeded, trigger an alert and exit the program
                if(intrusion_alert >= INTRUSION_THRESHOLD) {
                    printf("INTRUSION ALERT: Maximum number of failed login attempts exceeded.\n");
                    printf("Shutting down.\n");

                    // Print the log entries to a file before exiting the program
                    FILE *fp;
                    fp = fopen("intrusion_log.txt", "w");
                    if(fp == NULL) {
                        printf("Error opening file.\n");
                        exit(1);
                    }
                    for(int i = 0; i < log_index; i++) {
                        fprintf(fp, "%s\n", log[i]);
                    }
                    fclose(fp);
                    
                    exit(1);
                }

                // Add the failed login attempt to the log array
                sprintf(log[log_index], "%s,%s,failed login attempt", ip_address, username);
                log_index++;
            } else {
                printf("Login successful.\n");
            }
        } else {
            printf("Command not recognized.\n");
        }

        // Sleep for a random amount of time between 1 and 5 seconds
        usleep((rand() % (5 - 1 + 1) + 1) * 1000000);
    }

    return 0;
}