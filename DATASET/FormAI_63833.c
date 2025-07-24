//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

int detect_intrusion(char *log_file_path, char *suspicious_activity) {
    char buffer[MAX_FILE_SIZE];
    FILE *log_file = fopen(log_file_path, "r");

    if (log_file == NULL) {
        printf("Error: Unable to open log file: %s\n", log_file_path);
        return 0;
    }

    while (fgets(buffer, MAX_FILE_SIZE, log_file)) {
        if (strstr(buffer, suspicious_activity)) {
            printf("Warning: Suspicious activity detected: %s\n", suspicious_activity);
            return 1;
        }
    }

    printf("No suspicious activity detected in the log file: %s\n", log_file_path);
    return 0;
}

int main() {
    char log_file_path[100], suspicious_activity[50];
    int intrusion_detected;

    printf("Welcome to Intrusion Detection System!\n");
    printf("Please enter the full path of the log file to be checked: ");
    scanf("%s", log_file_path);

    printf("Please enter the suspicious activity to be checked: ");
    scanf("%s", suspicious_activity);

    intrusion_detected = detect_intrusion(log_file_path, suspicious_activity);

    if (intrusion_detected) {
        printf("Intrusion Detected!\n");
    } else {
        printf("No Intrusion Detected...\n");
    }

    return 0;
}