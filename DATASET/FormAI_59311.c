//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LogEntry {
    char* timestamp;
    char* sourceIP;
    char* destinationIP;
    char* message;
};

void processLogEntry(struct LogEntry entry) {
    // check for suspicious activity
    if (strstr(entry.message, "Unauthorized access attempt")) {
        printf("Potential intrusion detected from IP address %s", entry.sourceIP);
    }
    else if (strstr(entry.message, "Port scan detected")) {
        printf("Port scan detected from IP address %s", entry.sourceIP);
    }
    else if (strstr(entry.message, "Brute force attack detected")) {
        printf("Brute force attack detected from IP address %s", entry.sourceIP);
    }
    else {
        printf("No suspicious activity detected");
    }
}

int main() {
    struct LogEntry log1 = {"2022-05-11 10:22:02", "192.168.0.1", "10.0.0.2", "Unauthorized access attempt"};
    struct LogEntry log2 = {"2022-05-11 10:26:17", "192.168.0.5", "10.0.0.2", "Port scan detected"};
    struct LogEntry log3 = {"2022-05-11 10:30:41", "192.168.0.7", "10.0.0.2", "Brute force attack detected"};
    struct LogEntry log4 = {"2022-05-11 10:31:02", "192.168.0.1", "10.0.0.2", "Normal user login"};

    processLogEntry(log1);
    processLogEntry(log2);
    processLogEntry(log3);
    processLogEntry(log4);

    return 0;
}