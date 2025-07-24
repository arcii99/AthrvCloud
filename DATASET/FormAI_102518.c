//FormAI DATASET v1.0 Category: System event logger ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* event) {
    FILE *fp;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char timeStr[20];
    sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d", 
        tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
        tm.tm_hour, tm.tm_min, tm.tm_sec);
    fp = fopen("event_log.txt", "a");
    if (fp == NULL) {
        printf("Error opening log file!\n");
        return;
    }
    fprintf(fp, "%s - %s\n", timeStr, event);
    fclose(fp);
}

int main() {
    printf("Welcome to the C System Event Logger!\n");
    printf("Please enter the event you want to log:");
    char event[100];
    scanf("%[^\n]", event);
    logEvent(event);
    printf("Event logged successfully!\n");
    return 0;
}