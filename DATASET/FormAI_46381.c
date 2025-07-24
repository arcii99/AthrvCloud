//FormAI DATASET v1.0 Category: System event logger ; Style: shocked
#include <stdio.h>
#include <time.h>

void logEvent(char* message) {
    time_t currentTime;
    time(&currentTime);
    char* timeString = ctime(&currentTime);
    FILE* logFile = fopen("eventLog.txt", "a");
    fprintf(logFile, "%s: %s\n", timeString, message);
    fclose(logFile);
}

int main() {
    printf("Starting event logger...\n");
    char input[100];
    while (1) {
        printf("Enter an event to log (or 'exit' to quit): ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character
        if (strcmp(input, "exit") == 0) {
            printf("Exiting event logger...\n");
            break;
        } else {
            logEvent(input);
            printf("Event logged!\n");
        }
    }
    return 0;
}