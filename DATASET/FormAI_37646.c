//FormAI DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <time.h>

void logEvent(char* eventType, char* eventMessage);

int main(){
    // Example usage of logEvent function
    logEvent("ERROR", "Could not connect to database");
    logEvent("INFO", "User logged in successfully");
    logEvent("WARNING", "Disk space is running low");
    return 0;
}

void logEvent(char* eventType, char* eventMessage){
    FILE *fp;
    time_t now;
    struct tm *current_time;
    char timestamp[26];

    // Get current time and format as string
    time(&now);
    current_time = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", current_time);

    // Open log file for appending
    fp = fopen("event.log", "a");

    // Write event to log file with timestamp
    fprintf(fp, "[%s] [%s] %s\n", eventType, timestamp, eventMessage);

    // Close log file
    fclose(fp);
}