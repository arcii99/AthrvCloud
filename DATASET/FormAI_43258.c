//FormAI DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Oh boy! It's time to log some events!\n");

    char events[5][30] = {
        "System started up",
        "Error: Disk space running low",
        "Application error: Invalid input",
        "Login attempt from unauthorized user",
        "System shut down unexpectedly"
    };
    int eventID = 0;
    time_t current_time;
    char* timestamp;

    FILE *fp;
    fp = fopen("event_logs.txt", "w+");
    if (fp == NULL) {
        printf("I can't believe it! Failed to open the logs file!\n");
        exit(1);
    }

    printf("Good news! The logs file has been opened successfully!\n\n");

    for (int i = 0; i < 10; i++) { 
        eventID = rand() % 5;
        time(&current_time);
        timestamp = ctime(&current_time);
        fprintf(fp, "[%s] Event %d: %s\n", timestamp, (i+1), events[eventID]);
        printf("Event %d recorded: %s\n", (i+1), events[eventID]);
        printf("Timestamp: %s\n", timestamp);
        printf("-------------------------------------------\n");
        sleep(1);
    }

    printf("Wow! We just logged 10 events! Closing the logs file.\n");
    fclose(fp);
    return 0;
}