//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: peaceful
// This is a program for an Intrusion Detection System in C language.
// It detects the occurrence of an intrusion (unauthorized access to a computer system) in real time.
// It works by constantly monitoring the system log files and looking for any suspicious activity.
// If any suspicious activity is found, an alert is generated and the user is notified.

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define LOG_FILE "/var/log/messages" // The system log file to monitor

// Function to check the system log file for suspicious activity
void checkLogFile() {
    FILE* fp = fopen(LOG_FILE, "r"); // Open the log file in read mode

    if (fp == NULL) {
        perror("Error opening log file");
        return;
    }

    char line[256];
    time_t now = time(NULL);

    // Read each line in the log file one by one
    while (fgets(line, sizeof(line), fp)) {
        char* timestamp = strtok(line, " "); // Get the timestamp from the line
        char* message = strtok(NULL, ""); // Get the rest of the line (the log message)

        // Check if the log message contains any suspicious keywords
        if (strstr(message, "hack") || strstr(message, "crack") || strstr(message, "unauthorized access")) {
            // If suspicious activity is detected, generate an alert and notify the user
            printf("ALERT: Suspicious activity detected at %s\n", ctime(&now));
            printf("Log message: %s\n", message);
        }
    }

    fclose(fp); // Close the log file
}

int main() {
    while (1) { // Loop indefinitely
        checkLogFile(); // Check the log file for suspicious activity

        usleep(1000000); // Wait for 1 second before checking again
    }

    return 0;
}