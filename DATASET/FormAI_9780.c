//FormAI DATASET v1.0 Category: System event logger ; Style: realistic
#include <stdio.h>
#include <time.h>

/* Function to log system events in a file */
void logEvent(char *message) {
    FILE *fptr;
    time_t curtime;
    char *timestamp;
 
    /* Open file for appending the event logs */
    fptr = fopen("eventlog.txt", "a");
 
    /* Get current time of system */
    curtime = time(NULL);
 
    /* Convert the time to string format */
    timestamp = ctime(&curtime);
 
    /* Write the log message with timestamp to file */
    fprintf(fptr, "%s: %s\n", timestamp, message);
 
    /* Close the file */
    fclose(fptr);
}

int main() {
    char message[100];
 
    /* Get the message from user to log */
    printf("Enter the event message to log: ");
    scanf("%[^\n]s", message);
 
    /* Call the logEvent function to log the message */
    logEvent(message);
 
    printf("Event logged successfully in eventlog.txt file.\n");
    return 0;
}