//FormAI DATASET v1.0 Category: System event logger ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void logEvent(char *eventDescription);

int main()
{
    // seed the random number generator
    srand(time(NULL));
    
    // write some example events to the log
    logEvent("Application started");
    logEvent("User logged in");
    
    // simulate some random events
    for (int i = 0; i < 10; i++)
    {
        int eventCode = rand() % 3;
        switch (eventCode)
        {
            case 0:
                logEvent("Data updated");
                break;
            case 1:
                logEvent("Error occurred");
                break;
            case 2:
                logEvent("File transfer complete");
                break;
        }
    }
    
    // write a final message to the log
    logEvent("Application closed");
    
    return 0;
}

void logEvent(char *eventDescription)
{
    // get the current time
    time_t currentTime = time(NULL);
    
    // convert the time to a string
    char *timeString = ctime(&currentTime);
    
    // open the log file
    FILE *logFile = fopen("eventLog.txt", "a");
    
    // write the event details to the log file
    fprintf(logFile, "%s: %s\n", timeString, eventDescription);
    
    // close the log file
    fclose(logFile);
}