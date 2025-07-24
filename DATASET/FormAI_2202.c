//FormAI DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the log messages and file name
#define MAX_LOG_LEN 1000
#define FILE_NAME "example.log"

// Function to count the number of occurrences of a substring in a string
int count_occurrences(char *str, char *substr) {
    int count = 0;
    char *ptr = str;
    while ((ptr = strstr(ptr, substr)) != NULL) {
        count++;
        ptr += strlen(substr);
    }
    return count;
}

int main() {
    char log_message[MAX_LOG_LEN];
    char *log_file_name = FILE_NAME;
    FILE *log_file = fopen(log_file_name, "r");
    if (log_file == NULL) {
        printf("Error: Failed to open log file '%s'.\n", log_file_name);
        return 1;
    }

    printf("Log Analysis Report\n");
    printf("--------------------\n");

    // Count the number of log messages with "ERROR" in them
    int num_error_msgs = 0;
    while (fgets(log_message, MAX_LOG_LEN, log_file) != NULL) {
        if (strstr(log_message, "ERROR") != NULL) {
            num_error_msgs++;
        }
    }
    printf("Total number of error messages: %d\n", num_error_msgs);

    // Count the number of log messages with "WARNING" in them
    int num_warning_msgs = 0;
    rewind(log_file);
    while (fgets(log_message, MAX_LOG_LEN, log_file) != NULL) {
        if (strstr(log_message, "WARNING") != NULL) {
            num_warning_msgs++;
        }
    }
    printf("Total number of warning messages: %d\n", num_warning_msgs);

    // Count the number of log messages with a specific error code
    char error_code[5];
    printf("Enter an error code to search for (e.g. 404): ");
    scanf("%s", error_code);
    int num_specific_error_msgs = 0;
    rewind(log_file);
    while (fgets(log_message, MAX_LOG_LEN, log_file) != NULL) {
        if (strstr(log_message, error_code) != NULL) {
            num_specific_error_msgs++;
        }
    }
    printf("Total number of messages with error code '%s': %d\n", error_code, num_specific_error_msgs);

    // Count the number of occurrences of a specific IP address in the log file
    char ip_address[16];
    printf("Enter an IP address to search for (e.g. 192.168.0.1): ");
    scanf("%s", ip_address);
    int num_ip_address_occurrences = 0;
    rewind(log_file);
    while (fgets(log_message, MAX_LOG_LEN, log_file) != NULL) {
        if (strstr(log_message, ip_address) != NULL) {
            num_ip_address_occurrences += count_occurrences(log_message, ip_address);
        }
    }
    printf("Total number of occurrences of IP address '%s': %d\n", ip_address, num_ip_address_occurrences);

    // Close the log file
    fclose(log_file);
    return 0;
}