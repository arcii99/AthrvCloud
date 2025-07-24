//FormAI DATASET v1.0 Category: System event logger ; Style: modular
#include <stdio.h>
#include <time.h>

// Prototypes
void logEvent(char* event);

int main() {
    char event[100];

    printf("Enter the event: ");
    scanf("%99[^\n]", event);

    logEvent(event);

    return 0;
}

// This function logs the event with current date and time
void logEvent(char* event) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    FILE* filePtr;
    filePtr = fopen("log.txt", "a");

    fprintf(filePtr, "%d-%02d-%02d %02d:%02d:%02d -> %s\n",
        tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
        tm.tm_hour, tm.tm_min, tm.tm_sec, event);

    fclose(filePtr);
}