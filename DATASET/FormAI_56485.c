//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_ALERT_SIZE 50

typedef struct log_record {
    char source_ip[16];
    char destination_ip[16];
    char date[20];
    char time[20];
    char message[MAX_ALERT_SIZE];
} Log_Record;

int main() {
    Log_Record log_records[MAX_LOG_SIZE];
    int log_count = 0;

    FILE* log_file = fopen("intrusion.log", "r");

    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file.\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, 1024, log_file) != NULL) {
        char* source_ip = strtok(line, ",");
        char* destination_ip = strtok(NULL, ",");
        char* date = strtok(NULL, ",");
        char* time = strtok(NULL, ",");
        char* message = strtok(NULL, "\n");

        if (log_count < MAX_LOG_SIZE) {
            strncpy(log_records[log_count].source_ip, source_ip, 16);
            strncpy(log_records[log_count].destination_ip, destination_ip, 16);
            strncpy(log_records[log_count].date, date, 20);
            strncpy(log_records[log_count].time, time, 20);
            strncpy(log_records[log_count].message, message, MAX_ALERT_SIZE);
            log_count++;
        }
    }

    fclose(log_file);

    // Filter out records from the last hour
    time_t now = time(NULL);
    time_t hour_ago = now - 3600;
    int valid_log_count = 0;
    Log_Record valid_logs[MAX_LOG_SIZE];

    for (int i = 0; i < log_count; ++i) {
        char* time_str = log_records[i].time;
        struct tm* timeinfo;
        timeinfo = strptime(time_str, "%H:%M:%S", NULL);
        time_t log_time = mktime(timeinfo);

        if (log_time > hour_ago) {
            strncpy(valid_logs[valid_log_count].source_ip, log_records[i].source_ip, 16);
            strncpy(valid_logs[valid_log_count].destination_ip, log_records[i].destination_ip, 16);
            strncpy(valid_logs[valid_log_count].date, log_records[i].date, 20);
            strncpy(valid_logs[valid_log_count].time, log_records[i].time, 20);
            strncpy(valid_logs[valid_log_count].message, log_records[i].message, MAX_ALERT_SIZE);
            valid_log_count++;
        }
    }

    // Count the number of unique IP addresses in the last hour
    int unique_source_ips = 0;
    char* source_ips[valid_log_count];
    for (int i = 0; i < valid_log_count; ++i) {
        char* source_ip = valid_logs[i].source_ip;
        int found_duplicate = 0;
        for (int j = 0; j < unique_source_ips; ++j) {
            if (strcmp(source_ips[j], source_ip) == 0) {
                found_duplicate = 1;
                break;
            }
        }

        if (!found_duplicate) {
            source_ips[unique_source_ips] = source_ip;
            unique_source_ips++;
        }
    }

    // Generate alert message if necessary
    if (unique_source_ips > 10) {
        printf("INTRUSION DETECTED:\n");
        printf("Number of unique source IP addresses in the last hour: %d\n", unique_source_ips);
        printf("Logs:\n");
        for (int i = 0; i < valid_log_count; ++i) {
            printf("%s,%s,%s,%s,%s\n", valid_logs[i].source_ip, valid_logs[i].destination_ip, valid_logs[i].date, valid_logs[i].time, valid_logs[i].message);
        }
    } else {
        printf("No intrusion detected.\n");
    }

    return 0;
}