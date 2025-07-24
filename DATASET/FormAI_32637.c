//FormAI DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <time.h>
#include <string.h>

// Function to get current time
char* getTime() {
    time_t t = time(NULL);
    char* currTime = ctime(&t);
    currTime[strlen(currTime) - 1] = '\0';
    return currTime;
}

// Function to log events to file
void eventLogger(char* event) {
    FILE *fp;
    fp = fopen("events.log", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char* currTime = getTime();
    fprintf(fp, "[%s] %s\n", currTime, event);
    fclose(fp);
}

int main() {
    char event[100];
    printf("Enter event to log: ");
    fgets(event, 100, stdin);
    eventLogger(event);
    printf("Event successfully logged\n");
    return 0;
}