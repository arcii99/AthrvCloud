//FormAI DATASET v1.0 Category: System administration ; Style: statistical
/* This program performs statistical analysis on system logs */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000000      // Maximum number of lines in the log file
#define MAX_LINE_LEN 1000      // Maximum length of a log line
#define MAX_HOSTS 1000         // Maximum number of unique hosts in the log file

// Struct to store information about a log line
typedef struct LogLine {
    char host[100];
    char date[50];
    char time[50];
    char method[50];
    char endpoint[200];
    int response_code;
    int bytes_sent;
} LogLine;

// Struct to store information about a unique host
typedef struct HostInfo {
    char host[100];
    int num_requests;
    int num_errors;
    int total_bytes_sent;
} HostInfo;

// Array to store log lines
LogLine log_lines[MAX_LINES];

// Array to store unique hosts
HostInfo hosts[MAX_HOSTS];

// Number of log lines read
int num_lines = 0;

// Number of unique hosts found
int num_hosts = 0;

// Function to parse a log line and store the information in a LogLine object
void parse_log_line(char* line, LogLine* log_line) {
    sscanf(line, "%s %s %s %s %s %d %d",
           log_line->host,
           log_line->date,
           log_line->time,
           log_line->method,
           log_line->endpoint,
           &log_line->response_code,
           &log_line->bytes_sent);
}

// Function to update information about a unique host
void update_host_info(char* host, int response_code, int bytes_sent) {
    int i;
    for (i = 0; i < num_hosts; i++) {
        if (strcmp(hosts[i].host, host) == 0) {
            hosts[i].num_requests++;
            hosts[i].total_bytes_sent += bytes_sent;
            if (response_code >= 400 && response_code < 500) {
                hosts[i].num_errors++;
            }
            return;
        }
    }

    // If the host is not found, add it to the list of unique hosts
    HostInfo new_host;
    strcpy(new_host.host, host);
    new_host.num_requests = 1;
    new_host.total_bytes_sent = bytes_sent;
    new_host.num_errors = (response_code >= 400 && response_code < 500) ? 1 : 0;
    hosts[num_hosts++] = new_host;
}

// Function to print the top 10 hosts with the most requests
void print_top_hosts() {
    int i, j;

    // Sort the hosts array in descending order by number of requests
    for (i = 0; i < num_hosts; i++) {
        for (j = i + 1; j < num_hosts; j++) {
            if (hosts[j].num_requests > hosts[i].num_requests) {
                HostInfo temp = hosts[i];
                hosts[i] = hosts[j];
                hosts[j] = temp;
            }
        }
    }

    printf("----- Top 10 Hosts -----\n");
    for (i = 0; i < 10 && i < num_hosts; i++) {
        printf("%d) %s - %d requests\n", i+1, hosts[i].host, hosts[i].num_requests);
    }
}

// Function to print the percentage of requests that resulted in errors
void print_error_rate() {
    int i, total_requests = 0, total_errors = 0;
    for (i = 0; i < num_hosts; i++) {
        total_requests += hosts[i].num_requests;
        total_errors += hosts[i].num_errors;
    }
    double error_rate = (double)total_errors / (double)total_requests * 100.0;
    printf("----- Error Rate -----\n%f%% of requests resulted in errors\n", error_rate);
}

// Function to print the total number of bytes sent
void print_total_bytes_sent() {
    int i, total_bytes_sent = 0;
    for (i = 0; i < num_hosts; i++) {
        total_bytes_sent += hosts[i].total_bytes_sent;
    }
    printf("----- Total Bytes Sent -----\n%d bytes were sent in total\n", total_bytes_sent);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    char* log_file_path = argv[1];
    FILE* log_file = fopen(log_file_path, "r");

    if (log_file == NULL) {
        printf("Error: could not open log file\n");
        exit(2);
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, log_file) != NULL) {
        parse_log_line(line, &log_lines[num_lines]);
        update_host_info(log_lines[num_lines].host,
                         log_lines[num_lines].response_code,
                         log_lines[num_lines].bytes_sent);
        num_lines++;
    }

    print_top_hosts();
    print_error_rate();
    print_total_bytes_sent();

    return 0;
}