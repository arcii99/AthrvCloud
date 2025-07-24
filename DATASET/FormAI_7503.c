//FormAI DATASET v1.0 Category: System event logger ; Style: Sherlock Holmes
#include<stdio.h>
#include<time.h>
#include<string.h>

void logSystemEvent(char* event);

int main() {

    // Initialize the logger
    printf("Initializing the System Logger...\n");
    printf("----------------------------------\n");
    printf("The game is afoot!\n");

    // Generate a random event to log
    char events[5][50] = {
        "The printer has run out of paper!\n",
        "A new user has been created.\n",
        "A program has terminated abnormally.\n",
        "The server is now offline.\n",
        "A hacker has been locked out of the system!\n"
    };

    // Log the events
    for(int i=0; i<5; i++) {
        logSystemEvent(events[i]);
    }

    // Done logging
    printf("All events have been logged.\n");
    printf("Elementary, my dear Watson.\n");

    return 0;
}

void logSystemEvent(char* event) {
    FILE *fp;
    fp = fopen ("system.log","a");
    if(fp!=NULL) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        char timestamp[50];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &tm);
        fprintf(fp, "%s: %s", timestamp, event);
        fclose(fp);
        printf("Event logged: %s", event);
    } else {
        printf("Error: Unable to log event!");
    }
}