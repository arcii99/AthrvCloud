//FormAI DATASET v1.0 Category: Log analysis ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000 // Maximum number of lines in the log file
#define MAX_STR_LEN 500 // Maximum character length of each log line
#define MAX_IPS 50 // Maximum number of unique IP addresses to track

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }
    char *log_file_name = argv[1];
    FILE *log_file = fopen(log_file_name, "r");
    if(log_file == NULL) {
        printf("Unable to open log file: %s\n", log_file_name);
        return 1;
    }
    char ip_addresses[MAX_IPS][16]; // Array to store unique IP addresses
    int ip_count[MAX_IPS] = {0}; // Array to store count of requests made by each IP address
    int count = 0; // Total number of requests in the log file
    char line[MAX_STR_LEN]; // Buffer to store each log line
    while(fgets(line, MAX_STR_LEN, log_file)) { // Read each line from the log file
        char ip[16]; // Buffer to store IP address
        sscanf(line, "%*s %*s %*s %*s %*s %*s %*s %*s [%*[^]]] \"%*s %s", ip); // Extract IP address from log line
        int unique = 1; // Flag to check if IP address is already in the list
        for(int i = 0; i < MAX_IPS; i++) { // Check if IP address is already in the list
            if(ip_count[i] == 0) { // If there are no IP addresses in the list, break out of the loop
                break;
            }
            if(strcmp(ip_addresses[i], ip) == 0) { // If IP address is already in the list, increment count and set flag to 0
                ip_count[i]++;
                unique = 0;
                break;
            }
        }
        if(unique) { // If IP address is not in the list, add it to the list and set count to 1
            strcpy(ip_addresses[count], ip);
            ip_count[count] = 1;
            count++;
        }
    }
    fclose(log_file);
    printf("Total requests: %d\n", count);
    printf("IP Address\t\tRequests\n");
    for(int i = 0; i < count; i++) { // Print out list of IP addresses and count of requests made by each IP address
        printf("%s\t\t%d\n", ip_addresses[i], ip_count[i]);
    }
    return 0;
}