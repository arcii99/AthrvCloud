//FormAI DATASET v1.0 Category: System event logger ; Style: standalone
#include <stdio.h>
#include <time.h>

void logEvent(const char *eventType, const char *eventDesc) {

    time_t curTime;
    struct tm *timeInfo;
    char timeString[9];
    
    // Get current time
    time(&curTime);
    timeInfo = localtime(&curTime);
    strftime(timeString, sizeof(timeString), "%H:%M:%S", timeInfo);
    
    // Print log message
    printf("[%s] %s: %s\n", timeString, eventType, eventDesc);
}

int main() {

    // Log some dummy events
    logEvent("INFO", "System started");
    logEvent("WARNING", "CPU usage too high");
    logEvent("ERROR", "File not found");
    
    return 0;
}