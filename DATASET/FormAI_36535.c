//FormAI DATASET v1.0 Category: System event logger ; Style: artistic
#include <stdio.h>
#include <time.h>

void logEvent(char* eventType, char* message) {
    FILE *fp;
    time_t timestamp;
    struct tm *timeInfo;

    time(&timestamp);
    timeInfo = localtime(&timestamp);

    fp = fopen("event.log", "a+");
    fprintf(fp, "[%d-%02d-%02dT%02d:%02d:%02d] %s: %s\n",
        timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday,
        timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec,
        eventType, message);
    fclose(fp);
}

int main() {
    printf("Type 'exit' to quit the logger program.\n");
    char eventType[20], message[100];
    while (1) {
        printf("Enter event type: ");
        scanf("%s", eventType);
        if (strcmp(eventType, "exit") == 0) {
            break;
        }
        printf("Enter message: ");
        scanf("%s", message);
        logEvent(eventType, message);
    }
    return 0;
}