//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Configuration */
#define MAX_LOG_MESSAGES 100
#define MAX_MESSAGE_LENGTH 200

/* Structs */
typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    int timestamp;
} LogMessage;

/* Global Variables */
LogMessage logMessages[MAX_LOG_MESSAGES];
int numMessages = 0;

/* Function Declarations */
void log_message(char* message);
void check_for_intrusion();

int main() {
    log_message("User Bob logged in at 10:00AM");
    log_message("User Bob tried to access admin-only page at 10:05AM");
    log_message("User Bob logged out at 10:10AM");
    log_message("User Alice logged in at 10:15AM");
    log_message("User Alice accessed admin-only page at 10:20AM");
    log_message("User Alice logged out at 10:25AM");
    check_for_intrusion();
    return 0;
}

void log_message(char* message) {
    if (numMessages >= MAX_LOG_MESSAGES) {
        return;
    }
    LogMessage newMessage;
    strncpy(newMessage.message, message, MAX_MESSAGE_LENGTH);
    newMessage.timestamp = time(NULL);
    logMessages[numMessages] = newMessage;
    numMessages++;
}

void check_for_intrusion() {
    int i;
    for (i = 0; i < numMessages; i++) {
        LogMessage message = logMessages[i];
        if (strstr(message.message, "accessed admin-only page") != NULL) {
            /* Intrusion detected */
            printf("Intrusion detected at %d: %s\n", message.timestamp, message.message);
        }
    }
}