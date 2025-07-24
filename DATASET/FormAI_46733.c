//FormAI DATASET v1.0 Category: System event logger ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void log_event(char* event_type, char* event_description){
    time_t raw_time;
    struct tm* current_time;
 
    time(&raw_time);
    current_time = localtime(&raw_time);

    printf("[%02d:%02d:%02d] Event - Type: %s Description: %s\n", current_time->tm_hour, current_time->tm_min, current_time->tm_sec, event_type, event_description);
}
 
int main(void){
    char* event_type = "error";
    char* event_description = "Could not open file abc.txt";
    log_event(event_type, event_description);

    event_type = "warning";
    event_description = "Low disk space on drive C:";
    log_event(event_type, event_description);
 
    return 0;
}