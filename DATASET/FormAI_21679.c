//FormAI DATASET v1.0 Category: System event logger ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventType, char* eventDescription)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // get the current date and time
    int year = tm.tm_year + 1900;
    int month = tm.tm_mon + 1;
    int day = tm.tm_mday;
    int hour = tm.tm_hour;
    int minute = tm.tm_min;
    int second = tm.tm_sec;

    // open the log file for appending
    FILE *fp;
    fp = fopen("eventlog.txt", "a");

    // write the event to the log file
    fprintf(fp, "[%d-%02d-%02d %02d:%02d:%02d] %s: %s\n", year, month, day, hour, minute, second, eventType, eventDescription);

    // close the log file
    fclose(fp);
}

int main()
{
    // log some events
    logEvent("SYSTEM", "System starting up...");
    logEvent("ERROR", "Unable to connect to network.");
    logEvent("INFO", "Successfully logged in as admin.");

    return 0;
}