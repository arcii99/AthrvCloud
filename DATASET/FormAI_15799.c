//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: enthusiastic
#include<stdio.h>
#include<string.h>

// function prototypes
void logEvent(char* event);
void detectIntrusion(char* event);

char eventLogs[1000][50]; // array to hold event logs
int currentLogIndex = 0; // index to indicate the current event log position

int main() {
    printf("Welcome to the Intrusion Detection System!\n\n");
    printf("Please enter any events or actions: ");
    while(1) { // continuously prompt the user for events/actions
        char event[50]; // create a buffer for input
        fgets(event, 50, stdin);
        event[strcspn(event, "\n")] = '\0'; // remove the \n character added by fgets
        logEvent(event);
        detectIntrusion(event); // check if the newly added event is an intrusion
    }
    return 0;
}

void logEvent(char* event) {
    strcpy(eventLogs[currentLogIndex], event); // copy the event into the logs array
    currentLogIndex++; // move the current index to the next position
}

void detectIntrusion(char* event) {
    int count = 0; // variable to count the number of times a particular event occurs in the logs
    // loop through all previous logs and count the number of times the new event has occurred
    for(int i = 0; i < currentLogIndex - 1; i++) { 
        if(strcmp(eventLogs[i], event) == 0)
            count++;
    }
    if(count >= 3) { // if the count is 3 or more, it may indicate an intrusion
        printf("***ALERT!!!*** Possible intrusion detected!\n\n");
        // code to send alert notifications to system administrators or security personnel
    }
}