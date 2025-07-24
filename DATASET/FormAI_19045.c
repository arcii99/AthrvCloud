//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG 1000 // Maximum number of log entries to be stored
#define MAX_IP 20 // Maximum length of an IP address string
#define MAX_MSG 100 // Maximum length of a log message

typedef struct { // Structure to hold each log entry
    char timestamp[25];
    char ip[MAX_IP];
    char message[MAX_MSG];
} LogEntry;

LogEntry log[MAX_LOG]; // Global log array
int num_entries = 0; // Number of log entries currently stored

int is_intrusion(char* ip) { // Function to check if an IP address is an intruder
    int count = 0;

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(log[i].ip, ip) == 0) { // If the IP address matches a log entry
            count++;

            if (count >= 5) { // If there are more than 5 log entries from this IP address
                return 1; // Return true, indicating an intrusion
            }
        }
    }

    return 0; // Return false, indicating no intrusion
}

void log_entry(char* timestamp, char* ip, char* message) { // Function to add a log entry to the global log array
    LogEntry entry;

    strcpy(entry.timestamp, timestamp);
    strcpy(entry.ip, ip);
    strcpy(entry.message, message);

    log[num_entries] = entry;

    num_entries++;

    if (num_entries == MAX_LOG) { // If the log array is full, shift all entries left by 1
        for (int i = 1; i < MAX_LOG; i++) {
            log[i - 1] = log[i];
        }

        num_entries--;
    }
}

int main() {
    char timestamp[25];
    char ip[MAX_IP];
    char message[MAX_MSG];

    while (1) { // Infinite loop to simulate logging activity
        printf("Enter timestamp (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", timestamp);

        printf("Enter IP address: ");
        scanf("%s", ip);

        printf("Enter log message: ");
        getchar(); // Consume newline character from previous scanf
        fgets(message, MAX_MSG, stdin);

        log_entry(timestamp, ip, message);

        if (is_intrusion(ip)) { // If the IP address is an intruder
            printf("Intrusion detected from IP address %s!\n", ip);

            // Optional code to take action against the intruder (e.g. ban IP address, alert authorities)
        }
    }

    return 0;
}