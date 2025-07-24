//FormAI DATASET v1.0 Category: System event logger ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random event codes
int generateEventCode() {
    return rand() % 1001;
}

// Function to get current date and time
char* getDateTime() {
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    return c_time_string;
}

// Main function to log events
int main() {
    FILE *fptr;
    fptr = fopen("event_logs.txt", "a");  // Open file in append mode

    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int num_events = 5; // Number of events to log

    for (int i = 0; i < num_events; i++) {
        int event_code = generateEventCode();
        char* datetime = getDateTime();

        // Write event details to file
        fprintf(fptr, "Event Code: %d\n", event_code);
        fprintf(fptr, "Date and Time: %s", datetime);
        fprintf(fptr, "\n");

        // Display event details on console
        printf("Event Code: %d\n", event_code);
        printf("Date and Time: %s", datetime);
        printf("\n");
    }

    fclose(fptr);  // Close file
    return 0;
}