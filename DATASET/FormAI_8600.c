//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000 // Maximum number of log entries
#define MAX_LOG_LINE_LENGTH 200 // Maximum length of each log entry
#define MAX_IP_LENGTH 16 // Maximum length of each IP address

// Struct to hold a single log entry
typedef struct {
    char ip[MAX_IP_LENGTH];
    char message[MAX_LOG_LINE_LENGTH];
} log_entry;

// Struct to hold all the log entries
typedef struct {
    log_entry entries[MAX_LOG_ENTRIES];
    int num_entries;
} log_file;

// Function to check if an IP address is in the blacklist
int is_blacklisted(char* ip) {
    // In a real system, this function would check against a database or other source
    // For this example, we just hard-code some IPs as blacklisted
    if (strcmp(ip, "192.168.0.1") == 0 ||
        strcmp(ip, "10.0.0.2") == 0 ||
        strcmp(ip, "172.16.0.3") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    log_file log;
    log.num_entries = 0;

    // Simulate incoming log data (10 legitimate entries followed by 3 blacklisted entries)
    strcpy(log.entries[0].ip, "192.168.1.1");
    strcpy(log.entries[0].message, "User login successful");
    strcpy(log.entries[1].ip, "192.168.1.1");
    strcpy(log.entries[1].message, "User data retrieve successful");
    strcpy(log.entries[2].ip, "192.168.1.1");
    strcpy(log.entries[2].message, "User logout successful");
    strcpy(log.entries[3].ip, "192.168.1.2");
    strcpy(log.entries[3].message, "User login successful");
    strcpy(log.entries[4].ip, "192.168.1.2");
    strcpy(log.entries[4].message, "User data retrieve successful");
    strcpy(log.entries[5].ip, "192.168.1.2");
    strcpy(log.entries[5].message, "User logout successful");
    strcpy(log.entries[6].ip, "192.168.1.3");
    strcpy(log.entries[6].message, "User login successful");
    strcpy(log.entries[7].ip, "192.168.1.3");
    strcpy(log.entries[7].message, "User data retrieve successful");
    strcpy(log.entries[8].ip, "192.168.1.3");
    strcpy(log.entries[8].message, "User logout successful");
    strcpy(log.entries[9].ip, "192.168.1.4");
    strcpy(log.entries[9].message, "User login successful");
    
    strcpy(log.entries[10].ip, "192.168.0.1");
    strcpy(log.entries[10].message, "Intrusion attempt detected");
    strcpy(log.entries[11].ip, "10.0.0.2");
    strcpy(log.entries[11].message, "Intrusion attempt detected");
    strcpy(log.entries[12].ip, "172.16.0.3");
    strcpy(log.entries[12].message, "Intrusion attempt detected");
    log.num_entries = 13;

    // Check each entry for potential intrusion
    for (int i = 0; i < log.num_entries; i++) {
        if (is_blacklisted(log.entries[i].ip)) {
            printf("Intrusion detected: %s\n", log.entries[i].message);
            // Handle intrusion (e.g. send alert to security team)
        } else {
            printf("%s\n", log.entries[i].message);
        }
    }

    return 0;
}