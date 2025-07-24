//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_MSG_LEN 1024

char *check_for_intrusion(char *log_msg) {

    // Array of suspicious keywords to detect intrusion
    char *intrusion_keywords[] = {"hack", "attack", "malware", "virus", "exploit", "breach", "compromise"};

    int num_keywords = sizeof(intrusion_keywords) / sizeof(intrusion_keywords[0]);

    char *intrusion_detected = NULL;

    char *msg_copy = strdup(log_msg); // Make a copy of the log message for further processing
    char *msg_token = strtok(msg_copy, " "); // Tokenize the copy of the log message

    while (msg_token) {
        for (int i = 0; i < num_keywords; i++) {
            if (strcmp(msg_token, intrusion_keywords[i]) == 0) {
                intrusion_detected = intrusion_keywords[i];
                break;
            }
        }
        msg_token = strtok(NULL, " "); // Moving token to point to next element
    }
    free(msg_copy); // Free memory allocated to the copied string

    if (intrusion_detected != NULL) {
        return intrusion_detected;
    }
    else {
        return "Safe";
    }
}

int main() {

    // Sample log messages to test
    char *log_msg1 = "Connection attempt from unauthorized IP address";
    char *log_msg2 = "Server hacked! User credentials compromised";
    char *log_msg3 = "Malicious malware found in system";
    char *log_msg4 = "System successfully scanned by antivirus";

    char *intrusion_detected;

    // Checking for intrusion in log message 1
    intrusion_detected = check_for_intrusion(log_msg1);
    printf("%s: %s\n", log_msg1, intrusion_detected);

    // Checking for intrusion in log message 2
    intrusion_detected = check_for_intrusion(log_msg2);
    printf("%s: %s\n", log_msg2, intrusion_detected);

    // Checking for intrusion in log message 3
    intrusion_detected = check_for_intrusion(log_msg3);
    printf("%s: %s\n", log_msg3, intrusion_detected);

    // Checking for intrusion in log message 4
    intrusion_detected = check_for_intrusion(log_msg4);
    printf("%s: %s\n", log_msg4, intrusion_detected);

    return 0;
}