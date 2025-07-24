//FormAI DATASET v1.0 Category: Log analysis ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    char log[1000]; // Declare an array to store the log file
    FILE *file; // Declare a file pointer
    file = fopen("log.txt", "r"); // Open the log.txt file in read mode

    if (file == NULL) { // Check if the file could not be opened
        printf("Unable to open log file\n");
        return 0;
    }

    while (fgets(log, 1000, file) != NULL) { // Read each line of the log file
        char date[20], time[20], action[20], user[20]; // Declare variables to store the date, time, action, and user

        sscanf(log, "%s %s %s %s", date, time, action, user); // Use sscanf to extract the information from the log line

        // Analyze the log information
        if (strcmp(action, "login") == 0) { // Check if the action is a login
            printf("%s %s: %s logged in\n", date, time, user);
        } else if (strcmp(action, "logout") == 0) { // Check if the action is a logout
            printf("%s %s: %s logged out\n", date, time, user);
        } else if (strcmp(action, "access") == 0) { // Check if the action is an access attempt
            printf("%s %s: %s attempted to access\n", date, time, user);
        } else {
            printf("%s %s: Unknown action\n", date, time);
        }
    }

    fclose(file); // Close the file

    return 0;
}