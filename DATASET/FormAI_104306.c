//FormAI DATASET v1.0 Category: System event logger ; Style: retro
#include <stdio.h>
#include <time.h>

void logEvent(char* event);

int main(){
    printf("Welcome to the Retro Event Logger!\n");
    printf("Please type in the event you would like to log:\n");
    char event[50];
    fgets(event, sizeof(event), stdin);
    logEvent(event);
    return 0;
}

void logEvent(char* event){
    // Get current time
    time_t t = time(NULL);
    struct tm currentTime = *localtime(&t);

    FILE* logFile;
    logFile = fopen("event_log.txt", "a"); // Open file in append mode

    if(logFile == NULL){
        printf("Error opening file!\n");
        return;
    }

    fprintf(logFile, "[%d/%d/%d %d:%d:%d] ", currentTime.tm_mon + 1, currentTime.tm_mday, currentTime.tm_year + 1900, currentTime.tm_hour, currentTime.tm_min, currentTime.tm_sec);
    fprintf(logFile, "%s\n", event);

    fclose(logFile);
    printf("Event logged successfully!\n");
}