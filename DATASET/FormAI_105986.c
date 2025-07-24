//FormAI DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <time.h>

void logEvent(char* eventMsg) {
    time_t now = time(NULL);
    char* timeStr = ctime(&now);
    timeStr[strlen(timeStr) - 1] = '\0'; //remove newline character from ctime
    
    FILE* logfile = fopen("eventlog.txt", "a");
    fprintf(logfile, "%s | %s\n", timeStr, eventMsg);
    fclose(logfile);
}

int main() {
    printf("Welcome to the System Event Logger!\n");
    printf("Please type a message to log:\n");

    char eventMsg[100];
    fgets(eventMsg, 100, stdin);
    eventMsg[strlen(eventMsg) - 1] = '\0'; //remove newline character from fgets

    logEvent(eventMsg);

    printf("Event logged successfully! Check eventlog.txt for details.\n");

    return 0;
}