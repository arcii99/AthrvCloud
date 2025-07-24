//FormAI DATASET v1.0 Category: System event logger ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max (inclusive)
int getRandomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random float between min and max (inclusive)
float getRandomFloat(float min, float max) {
    float range = max - min;
    float div = RAND_MAX / range;
    return min + (rand() / div);
}

int main() {
    // Setting up the event logger file
    FILE* eventLogFile = fopen("event_log.txt", "w");
    if (eventLogFile == NULL) {
        printf("Error! Could not open event log file.\n");
        return 1;
    }

    // Setting up the random number generator
    srand(time(NULL));

    // Variable declarations
    int numEvents = 100;
    char eventNames[][50] = {"Application Startup", "Database Connection Established",
                             "User Login", "Transaction Processed",
                             "File Upload", "File Download",
                             "Report Generation", "API Request",
                             "Email Sent", "Password Reset",
                             "Data Backup", "Data Restore",
                             "Server Restart", "Network Disconnection",
                             "Power Failure", "Security Breach",
                             "Critical Error", "Application Shutdown"};
    int numEventNames = sizeof(eventNames) / sizeof(eventNames[0]);

    // Generating random events
    for (int i = 0; i < numEvents; i++) {
        // Generating random event name
        int randomIndex = getRandomInt(0, numEventNames - 1);
        char eventName[50];
        strcpy(eventName, eventNames[randomIndex]);

        // Generating random event data
        int eventId = i + 1;
        int eventSeverity = getRandomInt(1, 5);
        float eventValue = getRandomFloat(-10.0f, 10.0f);
        char eventDate[20];
        time_t now = time(NULL);
        strftime(eventDate, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

        // Writing event to file
        fprintf(eventLogFile, "Event ID: %d\n", eventId);
        fprintf(eventLogFile, "Event Name: %s\n", eventName);
        fprintf(eventLogFile, "Event Severity: %d\n", eventSeverity);
        fprintf(eventLogFile, "Event Value: %.2f\n", eventValue);
        fprintf(eventLogFile, "Event Date: %s\n", eventDate);
        fprintf(eventLogFile, "\n");
    }

    // Closing the event logger file
    fclose(eventLogFile);

    printf("Event logger program executed successfully!\n");

    return 0;
}