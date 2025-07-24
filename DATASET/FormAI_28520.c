//FormAI DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_IP_LENGTH 16
#define MAX_DATE_LENGTH 26

// Log entry structure
typedef struct {
    char ip[MAX_IP_LENGTH];
    char date[MAX_DATE_LENGTH];
    int response_code;
    char request_method[10];
    char resource[MAX_LINE_LENGTH];
} LogEntry;

// Function to parse a line of log entry and populate the LogEntry structure
void parse_log_entry(char *line, LogEntry *log_entry) {
    char *token;
    int i = 0;
    
    // Tokenize the line based on space
    token = strtok(line, " ");
    while (token != NULL) {
        switch (i) {
            case 0:
                strcpy(log_entry->ip, token);
                break;
            case 3:
                strncpy(log_entry->date, &token[1], strlen(token) - 1);
                break;
            case 5:
                log_entry->response_code = atoi(token);
                break;
            case 6:
                strcpy(log_entry->request_method, token);
                break;
            case 7:
                strcpy(log_entry->resource, token);
                break;
            default:
                break;
        }
        token = strtok(NULL, " ");
        i++;
    }
}

int main() {
    FILE *log_file;
    LogEntry log_entry;
    char line[MAX_LINE_LENGTH];
    int total_requests = 0, successful_requests = 0, client_error_requests = 0, server_error_requests = 0;
    int resource_requests[10] = {0};
    
    // Open the log file
    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error opening log file!\n");
        exit(EXIT_FAILURE);
    }
    
    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        // Parse the log entry
        parse_log_entry(line, &log_entry);
        
        // Record the request
        total_requests++;
        if (log_entry.response_code >= 200 && log_entry.response_code < 300) {
            successful_requests++;
            if (strstr(log_entry.resource, ".html") != NULL) {
                resource_requests[0]++;
            } else if (strstr(log_entry.resource, ".css") != NULL) {
                resource_requests[1]++;
            } else if (strstr(log_entry.resource, ".js") != NULL) {
                resource_requests[2]++;
            } else if (strstr(log_entry.resource, ".jpg") != NULL || strstr(log_entry.resource, ".jpeg") != NULL) {
                resource_requests[3]++;
            } else if (strstr(log_entry.resource, ".png") != NULL) {
                resource_requests[4]++;
            } else {
                resource_requests[5]++;
            }
        } else if (log_entry.response_code >= 400 && log_entry.response_code < 500) {
            client_error_requests++;
        } else if (log_entry.response_code >= 500) {
            server_error_requests++;
        }
    }
    
    // Close the log file
    fclose(log_file);
    
    // Print the analysis report
    printf("Total Requests: %d\n", total_requests);
    printf("Successful Requests: %d\n", successful_requests);
    printf("Client Error Requests: %d\n", client_error_requests);
    printf("Server Error Requests: %d\n", server_error_requests);
    printf("Resource Requests:\n");
    printf("\tHTML: %d\n", resource_requests[0]);
    printf("\tCSS: %d\n", resource_requests[1]);
    printf("\tJavaScript: %d\n", resource_requests[2]);
    printf("\tJPEG Images: %d\n", resource_requests[3]);
    printf("\tPNG Images: %d\n", resource_requests[4]);
    printf("\tOther: %d\n", resource_requests[5]);
    
    return 0;
}