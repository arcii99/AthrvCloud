//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 100
#define MAX_LOG_ENTRIES 100

// Represents a log entry
typedef struct log_entry {
    char log_str[MAX_STR_LEN];
} log_entry;

// Represents a log file
typedef struct log_file {
    char log_filename[MAX_STR_LEN];
    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries;
} log_file;

// Function to check if a log file has any suspicious activity
int is_suspect(log_file *lfile) {
    int i;

    // Look for suspicious keywords in the log file
    char keywords[5][MAX_STR_LEN] = {"hack", "intrusion", "malicious", "attack", "unauthorized"};
    for(i=0;i<lfile->num_entries;i++) {
        int j;
        for(j=0;j<5;j++) {
            if(strstr(lfile->log_entries[i].log_str, keywords[j]) != NULL) {
                return 1;
            }
        }
    }

    // If we reach here, it means no suspicious activity was found
    return 0;
}

int main() {
    // Create a sample log file with some log entries
    log_file lfile;
    strcpy(lfile.log_filename, "system_logs.txt");
    lfile.num_entries = 3;
    strcpy(lfile.log_entries[0].log_str, "User login successful");
    strcpy(lfile.log_entries[1].log_str, "Hack attempt detected");
    strcpy(lfile.log_entries[2].log_str, "System shut down due to unauthorized access");

    // Check if the log file has any suspicious activity
    if(is_suspect(&lfile)) {
        printf("WARNING: Intrusion detected in log file %s.\n", lfile.log_filename);
    } else {
        printf("No intrusion detected in log file %s.\n", lfile.log_filename);
    }

    return 0;
}