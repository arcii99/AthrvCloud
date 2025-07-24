//FormAI DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event_type, char* event_description){
    time_t current_time;
    struct tm* time_info;
    char time_string[9];
    char date_string[11];
    
    time(&current_time);
    time_info = localtime(&current_time);
    
    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
    strftime(date_string, sizeof(date_string), "%Y-%m-%d", time_info);
    
    printf("[%s %s] %s: %s\n", date_string, time_string, event_type, event_description);
}

int main(){
    log_event("INFO", "Application started");
    log_event("WARNING", "Low disk space warning");
    log_event("ERROR", "File not found");
    log_event("INFO", "Application stopped");
    
    return 0;
}