//FormAI DATASET v1.0 Category: Log analysis ; Style: statistical
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Define a structure to hold the log data
struct Log {
    char timestamp[20];
    char message[100];
    int severity;
};

// Function to parse timestamp and get date
char* get_date(char* timestamp) {
    char* date = malloc(sizeof(char) * 10);
    strncpy(date, timestamp, 10);
    date[10] = '\0';
    return date;
}

// Function to print log data
void print_logs(struct Log logs[], int log_count) {
    printf("Total log entries: %d\n\n", log_count);
    printf("%-20s %-100s %-8s\n", "Timestamp", "Message", "Severity");
    printf("------------------------------------------------------------\n");
    for(int i=0; i<log_count; i++) {
        printf("%-20s %-100s %-8d\n", logs[i].timestamp, logs[i].message, logs[i].severity);
    }
    printf("\n");
}

int main() {
    // Define example log data
    struct Log logs[] = {
        {"2021-08-23T10:54:22", "Successful login", 2},
        {"2021-08-23T11:05:43", "Database connection failed", 1},
        {"2021-08-24T13:27:18", "Invalid input", 3},
        {"2021-08-25T09:12:01", "File not found", 2},
        {"2021-08-25T13:45:23", "Critical error - system shutting down", 4},
        {"2021-08-26T14:29:33", "User not authorized", 2},
        {"2021-08-26T18:12:57", "Successful logout", 2},
        {"2021-08-27T07:01:14", "Request timed out", 2},
        {"2021-08-27T09:56:37", "Database connection established", 2},
        {"2021-08-28T16:08:45", "Password reset requested", 1},
        {"2021-08-28T17:21:59", "Password reset successful", 2},
        {"2021-08-29T12:45:33", "Server overloaded", 3},
        {"2021-08-30T08:53:11", "Received 500 new messages", 1},
        {"2021-08-30T09:40:15", "Sent 500 new messages", 2},
        {"2021-08-31T14:55:21", "User account locked", 3},
        {"2021-09-01T08:20:49", "Access denied", 2},
        {"2021-09-02T16:39:54", "Successful login", 2},
        {"2021-09-02T21:12:16", "Database query successful", 2},
        {"2021-09-03T11:48:07", "Invalid input", 3},
        {"2021-09-04T09:15:32", "File not found", 2}
    };
    int log_count = sizeof(logs)/sizeof(logs[0]); // Calculate number of log entries
    print_logs(logs, log_count); // Print all log data
    
    // Get unique dates in the log
    printf("Unique dates in the log:\n");
    printf("------------------------\n");
    char* dates[log_count];
    int date_count = 0;
    for(int i=0; i<log_count; i++) {
        char* date = get_date(logs[i].timestamp);
        int exists = 0;
        for(int j=0; j<date_count; j++) {
            if(strcmp(dates[j], date) == 0) {
                exists = 1;
            }
        }
        if(!exists) {
            dates[date_count++] = date;
            printf("%s\n", date);
        } else {
            free(date);
        }
    }
    printf("\n");
    
    // Calculate severity statistics for each date
    printf("Severity statistics for each date:\n");
    printf("----------------------------------\n");
    for(int i=0; i<date_count; i++) {
        printf("%s\n", dates[i]);
        printf("---------------\n");
        int count = 0;
        int severity_count[5] = {0}; // Array to hold count for each severity level
        for(int j=0; j<log_count; j++) {
            if(strcmp(get_date(logs[j].timestamp), dates[i]) == 0) {
                severity_count[logs[j].severity-1]++;
                count++;
            }
        }
        printf("Total log entries: %d\n", count);
        printf("Severity 1 (Low): %d (%.2f%%)\n", severity_count[0], (float)severity_count[0]/count*100);
        printf("Severity 2 (Medium): %d (%.2f%%)\n", severity_count[1], (float)severity_count[1]/count*100);
        printf("Severity 3 (High): %d (%.2f%%)\n", severity_count[2], (float)severity_count[2]/count*100);
        printf("Severity 4 (Critical): %d (%.2f%%)\n\n", severity_count[3], (float)severity_count[3]/count*100);
    }
    
    // Free dynamically allocated memory for dates array
    for(int i=0; i<date_count; i++) {
        free(dates[i]);
    }
    
    return 0;
}