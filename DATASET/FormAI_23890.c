//FormAI DATASET v1.0 Category: System event logger ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventName, char* eventType, char* eventMessage){
    printf("[%s][%s]: %s\n", eventType, eventName, eventMessage);
}

int main(){
    printf("*****************************************************\n");
    printf("Welcome to the Unique C System Event Logger Example\n");
    printf("*****************************************************\n");
    printf("\n");

    char eventName[20];
    char eventType[20];
    char eventMessage[50];

    printf("Please enter the event name (Max 20 characters): ");
    fgets(eventName, 20, stdin);
    printf("Please enter the event type (Max 20 characters): ");
    fgets(eventType, 20, stdin);
    printf("Please enter the event message (Max 50 characters): ");
    fgets(eventMessage, 50, stdin);

    time_t now;
    time(&now);
    printf("The event was logged on: %s", ctime(&now));

    logEvent(eventName, eventType, eventMessage);

    printf("\n");
    printf("*************************************************\n");
    printf("Event has been logged successfully! Check below: \n");
    printf("*************************************************\n");
    printf("\n");

    printf("[%s][%s]: %s\n", eventType, eventName, eventMessage);

    return 0;
}