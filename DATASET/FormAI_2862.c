//FormAI DATASET v1.0 Category: System event logger ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>

void logEvent(char* eventName, char* eventDescription) {
    time_t now;
    time(&now);
    printf("[%s]: %s - %s\n", ctime(&now), eventName, eventDescription);
}

int main() {
    char eventName[50];
    char eventDescription[100];

    printf("Enter the event name: ");
    scanf("%s", eventName);

    printf("Enter the event description: ");
    scanf("%s", eventDescription);

    logEvent(eventName, eventDescription);

    return 0;
}