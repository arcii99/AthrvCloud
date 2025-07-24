//FormAI DATASET v1.0 Category: System event logger ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"

void logEvent(char* event) {
    FILE* logFile = fopen(LOG_FILE, "a+");
    time_t currentTime;
    char* timeString;

    if (logFile == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }

    time(&currentTime);
    timeString = ctime(&currentTime);
    timeString[strlen(timeString) - 1] = '\0';

    fprintf(logFile, "%s - %s\n", timeString, event);
    fclose(logFile);
}

int main() {
    logEvent("Program started");

    int a = 10;
    int b = 20;
    int sum = a + b;
    printf("Sum of %d and %d is %d\n", a, b, sum);

    char* message = "Hello, World!";
    logEvent(message);

    logEvent("Program ended");
    return 0;
}