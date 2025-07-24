//FormAI DATASET v1.0 Category: System event logger ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the System Event Logger!\n");

    time_t currentTime;
    struct tm* timeInfo;
    char timeString[9];

    // Get the current time and convert it to a string
    time(&currentTime);
    timeInfo = localtime(&currentTime);
    strftime(timeString, 9, "%H:%M:%S", timeInfo);

    // Open the log file
    FILE *logFile = fopen("system_event_log.txt", "a");

    // Check if the file opened successfully
    if (logFile == NULL) {
        printf("Error: Unable to open system_event_log.txt!\n");
        return EXIT_FAILURE;
    }

    printf("Enter a system event: ");

    // Read in the user's event input
    char input[50];
    fgets(input, 50, stdin);
    input[strcspn(input, "\r\n")] = 0;   // Remove the newline character if present

    // Write the event to the log file along with the current time
    fprintf(logFile, "[%s] %s\n", timeString, input);

    printf("Event logged successfully!\n");

    // Close the log file
    fclose(logFile);

    return EXIT_SUCCESS;
}