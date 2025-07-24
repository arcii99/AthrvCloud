//FormAI DATASET v1.0 Category: System event logger ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void logEvent(char* eventName, char* eventType) {
    FILE* filePtr;

    time_t rawTime;
    struct tm* timeInfo;
    char timeString[80];

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(timeString, 80, "%m/%d/%Y %H:%M:%S", timeInfo);

    filePtr = fopen("eventLog.txt", "a");

    fprintf(filePtr, "%s - %s: %s\n", timeString, eventType, eventName);

    fclose(filePtr);
}

void recursiveEvent(char* eventName, int count) {
    if(count == 0) {
        return;
    }

    logEvent(eventName, "START");
    recursiveEvent(eventName, count - 1);
    logEvent(eventName, "END");
}

int main() {
    recursiveEvent("EXAMPLE_EVENT", 5);

    return 0;
}