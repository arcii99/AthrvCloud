//FormAI DATASET v1.0 Category: System event logger ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to log the system events
void logEvent(char* eventType, char* eventMessage)
{
    // Get the current time
    time_t ltime;
    ltime=time(NULL);
    printf("%s: %s - %s\n", ctime(&ltime), eventType, eventMessage);
    
    // Open the log file in append mode
    FILE *logFile;
    logFile = fopen("event.log", "a");
    if(logFile != NULL)
    {
        // Write the event details to the log file
        fprintf(logFile, "%s: %s - %s\n", ctime(&ltime), eventType, eventMessage);
        fclose(logFile);
    }
}

int main(void)
{
    // Log some sample events
    logEvent("INFO", "Program started.");
    logEvent("ERROR", "Cannot open file.");
    logEvent("WARNING", "Low disk space.");
    logEvent("DEBUG", "Value of x is 5.");
    logEvent("INFO", "Program ended.");
    
    return 0;
}