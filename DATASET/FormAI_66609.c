//FormAI DATASET v1.0 Category: System event logger ; Style: mathematical
#include <stdio.h>
#include <time.h>

// function to log system events
void logEvent(char* eventType, char* eventDesc)
{
    time_t now;
    time(&now);
    struct tm* timeinfo = localtime(&now);
    char timeString[9];
    strftime(timeString, sizeof(timeString), "%H:%M:%S", timeinfo);
    printf("[%s] %s - %s\n", timeString, eventType, eventDesc);
}

int main()
{
    // example usage
    logEvent("INFO", "System started");
    logEvent("WARN", "Memory usage high");
    logEvent("ERROR", "Disk full");
    
    return 0;
}