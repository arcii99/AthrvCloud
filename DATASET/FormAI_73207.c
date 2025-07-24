//FormAI DATASET v1.0 Category: Log analysis ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "example.log"

int main() {
    FILE *log_file = fopen(LOG_FILE, "r");
    if (!log_file) {
        fprintf(stderr, "Could not open log file\n");
        return 1;
    }
    
    size_t line_size = 1024;
    char *line = (char *) malloc(line_size * sizeof(char));
    int line_number = 1;
    
    while (getline(&line, &line_size, log_file) != -1) {
        // Check if log entry is an error
        if (strstr(line, "ERROR") != NULL) {
            printf("LOG ERROR at line %d: %s", line_number, line);
        }
        
        // Get the IP address from the log entry
        char *ip_start = strstr(line, "IP=") + 3;
        char *ip_end = strchr(ip_start, ' ');
        int ip_length = ip_end - ip_start;
        char *ip = (char *) malloc((ip_length + 1) * sizeof(char));
        strncpy(ip, ip_start, ip_length);
        ip[ip_length] = '\0';
        
        /*
         * Here you can do more analysis on the log entry
         * such as counting the number of times each IP address appears
         * or calculating the average response time for each IP address
         */
         
        free(ip);
        line_number++;
    }
    
    free(line);
    fclose(log_file);
    
    return 0;
}