//FormAI DATASET v1.0 Category: System event logger ; Style: futuristic
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define MAX_EVENTS 100

struct systemEvent {
    char eventType[50];
    char affectedModule[50];
    char eventDetails[500];
    time_t eventTime;
};

struct systemEvent eventLog[MAX_EVENTS];
int eventCount = 0;

void logEvent(char eventType[50], char affectedModule[50], char eventDetails[500]) {
    if (eventCount == MAX_EVENTS) {
        printf("Event log has reached maximum capacity. Unable to log event.\n");
        return;
    }
    struct systemEvent event;
    strcpy(event.eventType, eventType);
    strcpy(event.affectedModule, affectedModule);
    strcpy(event.eventDetails, eventDetails);
    event.eventTime = time(NULL);
    eventLog[eventCount++] = event;
}

void displayEventsByType(char eventType[50]) {
    int eventCounter = 1;
    bool eventsFound = false;
    printf("\nEvents with type '%s':\n", eventType);
    for (int i = 0; i < eventCount; i++) {
        if (strcmp(eventType, eventLog[i].eventType) == 0) {
            printf("\nEvent %d:\nType: %s\nAffected Module: %s\nEvent Details: %s\nEvent Time: %s\n", eventCounter++, 
                                                                                                    eventLog[i].eventType, 
                                                                                                    eventLog[i].affectedModule, 
                                                                                                    eventLog[i].eventDetails, 
                                                                                                    ctime(&(eventLog[i].eventTime)));
            eventsFound = true;
        }
    }
    if (!eventsFound) {
        printf("No events with type '%s' were found.\n", eventType);
    }
}

void displayAllEvents() {
    int eventCounter = 1;
    printf("\nAll system events:\n");
    for (int i = 0; i < eventCount; i++) {
        printf("\nEvent %d:\nType: %s\nAffected Module: %s\nEvent Details: %s\nEvent Time: %s\n", eventCounter++, 
                                                                                                eventLog[i].eventType, 
                                                                                                eventLog[i].affectedModule, 
                                                                                                eventLog[i].eventDetails, 
                                                                                                ctime(&(eventLog[i].eventTime)));
    }
}

int main() {
    logEvent("ERROR", "DATABASE", "Unable to establish database connection.");
    logEvent("ERROR", "SERVER", "Server crashed due to high CPU usage.");
    logEvent("WARNING", "CLIENT", "Client requested an invalid resource.");
    logEvent("INFO", "BACKUP", "Backup successful.");
    logEvent("INFO", "UPDATES", "New firmware updates available.");

    displayAllEvents();
    displayEventsByType("ERROR");
    displayEventsByType("WARNING");
    displayEventsByType("INFO");
    
    return 0;
}