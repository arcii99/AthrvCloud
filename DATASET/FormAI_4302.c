//FormAI DATASET v1.0 Category: System event logger ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get current time
char* getCurrentTime() {
    time_t rawtime;
    struct tm* timeinfo;
    char* timeString = (char*) malloc(sizeof(char) * 80);

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timeString, 80, "%c", timeinfo);

    return timeString;
}

// function to log events to file
void logEvent(char* event) {
    FILE* fPtr;
    char* currentTime;

    currentTime = getCurrentTime();

    // append to file
    fPtr = fopen("systemevents.log", "a");
    fprintf(fPtr, "[%s] %s\n", currentTime, event);
    fclose(fPtr);

    free(currentTime);
}

int main() {
    char userInput[100];

    printf("Enter event to log: ");
    fgets(userInput, 100, stdin);

    logEvent(userInput);

    printf("Event logged successfully.\n");

    return 0;
}