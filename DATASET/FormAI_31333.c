//FormAI DATASET v1.0 Category: System event logger ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function prototypes
void logEvent(char* message);

// Main function
int main(void) {
    char* events[] = {
        "System rebooted successfully",
        "Error: unable to connect to database",
        "Security breach detected",
        "Application crash",
        "New user registered",
        "Disk full, unable to write to file",
        "Network connectivity restored",
        "Service outage",
        "Firewall updated",
        "Backup completed successfully"
    };

    srand(time(NULL)); // Seed the random number generator with the current time

    while (true) {
        int index = rand() % 10; // Choose a random event from the list
        logEvent(events[index]); // Log the event
        sleep(1); // Wait for 1 second
    }

    return 0;
}

/**
 * Logs an event with a timestamp to the system log
 *
 * @param message The message to log
 */
void logEvent(char* message) {
    time_t now = time(NULL); // Get the current time
    char* timestamp = ctime(&now); // Convert the time to a string
    printf("%s: %s\n", timestamp, message); // Print the timestamp and message to the console
    // TODO: Write the event to the system log
}