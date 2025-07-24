//FormAI DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

void log_event(char* event){
    // Log the event to system log
    openlog("MyApp", LOG_PID|LOG_CONS, LOG_USER);
    syslog(LOG_INFO,"%s", event);
    closelog(); 
}

int main(){
    
    // Welcome message
    printf("Welcome to MyEventLogger program!\n");

    // Ask user for input
    printf("Enter an event to log:\n");
    char event[100];
    fgets(event, 100, stdin);

    // Log the event
    log_event(event);

    // Confirmation message
    printf("Event logged successfully.\n");

    return 0;
}