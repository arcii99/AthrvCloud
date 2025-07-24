//FormAI DATASET v1.0 Category: System event logger ; Style: recursive
#include <stdio.h>
#include <time.h>

void logEvent(char *eventName, char *timeStamp, char *sourceFile, char *functionName, int lineNumber);

void main()
{
    // Simulate events
    logEvent("Program Start", "10:00:00", "main.c", "main", 15);
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    logEvent("Sum Calculation", "10:00:01", "main.c", "main", 22);
    printf("The sum of 1 to 10 is: %d\n", sum);
    logEvent("Sum Calculation Complete", "10:00:02", "main.c", "main", 24);
}

//Recursive logging function
void logEvent(char *eventName, char *timeStamp, char *sourceFile, char *functionName, int lineNumber)
{
    FILE *fPtr;

    //Open file to append
    fPtr = fopen("system_log.txt", "a");

    //Get current time and date
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char dateTime[30];
    strftime(dateTime, sizeof(dateTime), "%Y-%m-%d %H:%M:%S", t);

    //Write log message to file
    fprintf(fPtr, "[%s] %s: %s(%d) in %s at line %d\n", dateTime, eventName, functionName, getpid(), sourceFile, lineNumber);

    //Close file
    fclose(fPtr);

    //Recursively call logEvent to log the fact that an event has been logged
    if (strcmp(eventName, "Event Logged") != 0) {
        logEvent("Event Logged", dateTime, sourceFile, functionName, lineNumber);
    }
}