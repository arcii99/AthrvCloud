//FormAI DATASET v1.0 Category: System event logger ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void logEvent(char* eventType, char* eventDescription);

int main() {
    char* event1 = "Login";
    char* event2 = "Logout";
    char* event3 = "File Upload";
    char* event4 = "File Download";
    char* event5 = "Payment";
    
    logEvent(event1, "User1 has logged in.");
    logEvent(event3, "User2 has uploaded a file.");
    logEvent(event5, "User3 has made a payment of $50.");
    logEvent(event2, "User1 has logged out.");
    logEvent(event4, "User2 has downloaded a file.");
    
    return 0;
}

void logEvent(char* eventType, char* eventDescription) {
    FILE *fptr;
    time_t currentTime;
    
    fptr = fopen("event_log.txt", "a");
    
    if(fptr == NULL) {
        printf("Error! Could not open file.");
        exit(1);
    }
    
    //get current time
    time(&currentTime);
    
    //append to file
    fprintf(fptr, "[%s] (%s): %s\n", asctime(localtime(&currentTime)), eventType, eventDescription);
    
    fclose(fptr);
}