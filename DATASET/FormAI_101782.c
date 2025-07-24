//FormAI DATASET v1.0 Category: System event logger ; Style: authentic
#include <stdio.h>
#include <time.h>

// function to log system events
void logEvent(const char *event) {
    time_t currentTime;
    struct tm *localTime;

    // get current time
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    // format and print log message
    printf("[%04d-%02d-%02d %02d:%02d:%02d] %s\n",
           localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
           localTime->tm_hour, localTime->tm_min, localTime->tm_sec, event);
}

int main() {
    // example usage
    logEvent("System started");
    logEvent("User logged in");
    logEvent("File saved successfully");
    logEvent("Error: unable to connect to database");

    return 0;
}