//FormAI DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct logs {
    int hour;
    int minute;
    int second;
    char message[100];
} Log;

void print_logs(Log *log_arr, int size) {
    printf("\n--------------------\n");
    for (int i = 0; i < size; i++) {
        printf("[%02d:%02d:%02d] %s\n", log_arr[i].hour, log_arr[i].minute, log_arr[i].second, log_arr[i].message);
    }
    printf("--------------------\n");
}

int main() {
    int n = 10; //number of logs
    Log logs[n];

    //populate logs with sample data
    strcpy(logs[0].message, "Connection established");
    logs[0].hour = 10;
    logs[0].minute = 30;
    logs[0].second = 45;

    //...populate logs[n-1] with sample data...

    //print all logs
    print_logs(logs, n);

    //find logs with keyword "error"
    printf("\nFinding logs with keyword 'error'\n");
    for (int i = 0; i < n; i++) {
        if (strstr(logs[i].message, "error") != NULL) {
            printf("[%02d:%02d:%02d] %s\n", logs[i].hour, logs[i].minute, logs[i].second, logs[i].message);
        }
    }

    //delete logs with timestamp before 12:00:00
    printf("\nDeleting logs with timestamp before 12:00:00\n");
    int j = 0;
    while (j < n) {
        if (logs[j].hour < 12) {
            for (int k = j; k < n-1; k++) {
                logs[k] = logs[k+1];
            }
            n--;
        } else {
            j++;
        }
    }

    //print remaining logs
    print_logs(logs, n);

    return 0;
}