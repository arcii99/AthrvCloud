//FormAI DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Define our log types
#define ERROR 0
#define WARNING 1
#define INFO 2
#define DEBUG 3

// Define function to parse log type based on the first letter of the log message
int parse_log_type(char* message) {
    char first_letter = message[0];
    switch (first_letter) {
        case 'E':
            return ERROR;
        case 'W':
            return WARNING;
        case 'I':
            return INFO;
        case 'D':
            return DEBUG;
        default:
            return -1;
    }
}

int main() {
    // Define some sample logs
    char log_1[] = "E: ERROR: Invalid command received from client";
    char log_2[] = "W: WARNING: Server disconnected unexpectedly";
    char log_3[] = "I: INFO: Database connection established";
    char log_4[] = "D: DEBUG: Executing query: SELECT * FROM users";

    // Define an array to hold our log messages
    char logs[4][100];
    strcpy(logs[0], log_1);
    strcpy(logs[1], log_2);
    strcpy(logs[2], log_3);
    strcpy(logs[3], log_4);

    // Print out all of our logs, parsing the log type and printing in a cyberpunk style
    printf(">>>>> BEGIN LOG ANALYSIS <<<<<\n");
    for (int i = 0; i < 4; i++) {
        char* current_log = logs[i];
        int log_type = parse_log_type(current_log);
        printf("---------------------------------------------\n");
        switch (log_type) {
            case ERROR:
                printf("ERROR! SYSTEM BREACH DETECTED! %s!\n", current_log);
                break;
            case WARNING:
                printf("WARNING! INCOMING THREAT DETECTED! %s!\n", current_log);
                break;
            case INFO:
                printf("INFORMATION RECEIVED! %s!\n", current_log);
                break;
            case DEBUG:
                printf("DEBUG MODE INITIATED! %s\n", current_log);
                break;
            default:
                printf("UNKNOWN LOG MESSAGE RECEIVED. IGNORING...\n");
        }
    }
    printf("---------------------------------------------\n");
    printf(">>>>> END LOG ANALYSIS <<<<<\n");
}