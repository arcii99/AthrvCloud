//FormAI DATASET v1.0 Category: System event logger ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* event, char* severity) {
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    FILE* fp;
    fp = fopen("systemlog.txt", "a");
    fprintf(fp, "[ %s | %s ] - %s\n", c_time_string, severity, event);
    fclose(fp);
}

int main() {
    char* event = "System started successfully.";
    char* severity = "INFO";
    logEvent(event, severity);

    // some code that calls various system functions

    event = "System crashed due to memory overflow.";
    severity = "ERROR";
    logEvent(event, severity);
    return 0;
}