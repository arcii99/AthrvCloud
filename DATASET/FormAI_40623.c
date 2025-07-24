//FormAI DATASET v1.0 Category: System event logger ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* event) {
    FILE *filePtr;
    char fileName[50];
    time_t t = time(NULL);
    struct tm* current_time = localtime(&t);

    sprintf(fileName, "%d-%d-%d.log", current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday);

    filePtr = fopen(fileName, "a+");

    if(!filePtr) {
        printf("Error opening file!");
        exit(1);
    }

    fprintf(filePtr, "[%d:%d:%d] %s\n", current_time->tm_hour, current_time->tm_min, current_time->tm_sec, event);

    fclose(filePtr);
}

int main() {
    char event[100];
    printf("Enter an event: ");
    fgets(event, sizeof(event), stdin);

    // Remove the newline character from the end of the string
    event[strcspn(event, "\n")] = 0;

    logEvent(event);
    printf("Event logged successfully.\n");

    return 0;
}