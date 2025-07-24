//FormAI DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
This is a unique C System Event Logger program that logs all system-related events in a specific file.

The program logs the following events:
1. System boot-up
2. User login/logout
3. Process start/end
4. File creation/deletion

*/

const char* FILE_NAME = "system_log.txt"; // Name of the log file

void log_event(const char* event_desc){
    FILE* fp = fopen(FILE_NAME, "a"); //Opening the file for writing the event
    if(fp == NULL){
        printf("Failed to open file for writing! [%s]\n", FILE_NAME);
        return;
    }

    char timestamp[30];
    time_t now = time(NULL); 
    strftime(timestamp, 30, "%Y-%m-%d %H:%M:%S", localtime(&now)); // Time stamp of the event

    fprintf(fp, "[%s] %s\n", timestamp, event_desc); // Logging the event with timestamp
    fclose(fp); // Closing the file
}

int main(){
    // Test the logger function with some sample events
    log_event("System booted up!");
    log_event("User John Doe logged in!");
    log_event("Process 12345 started.");
    log_event("File abc.txt deleted.");
    log_event("User Jane Smith logged out!");

    return 0;
}