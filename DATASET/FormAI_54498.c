//FormAI DATASET v1.0 Category: System event logger ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the C System Event Logger program!\n");
    
    // get current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestamp[25];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

    // ask user for event information
    char eventType[50];
    printf("What type of event do you want to log? ");
    scanf("%s", eventType);

    char eventDescription[100];
    printf("Please describe the event: ");
    scanf(" %[^\n]", eventDescription);
    
    // open log file
    FILE *fptr = fopen("eventlog.txt", "a");
    if (fptr == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    // write log entry
    fprintf(fptr, "[%s] Type: %s, Description: %s\n", timestamp, eventType, eventDescription);
    printf("Event logged successfully!\n");

    // close file
    fclose(fptr);

    return 0;
}