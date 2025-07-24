//FormAI DATASET v1.0 Category: System event logger ; Style: random
#include<stdio.h>
#include<time.h>

//function to log the system event
void log_event(char* event_type, char* message){

    time_t now;
    time(&now);
    char* time_stamp = ctime(&now);

    printf("[LOGGED EVENT]\n");
    printf("Event Type: %s\n", event_type);
    printf("Message: %s\n", message);
    printf("Time: %s\n", time_stamp);
}

int main(){

    //sample events to log
    log_event("INFO", "System initialized successfully.");
    log_event("ERROR", "File not found.");
    log_event("WARNING", "Low disk space.");

    return 0;
}