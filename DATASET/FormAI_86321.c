//FormAI DATASET v1.0 Category: Log analysis ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This program analyses the log file and extracts important information */
int main() {

    FILE *fp;
    fp = fopen("server.log", "r"); // Opening the log file in read mode

    if (fp == NULL) { // If file fails to open
        printf("Could not open file");
        return 0;
    }

    char line[100];
    int count_total_logs = 0;
    int count_errors = 0;
    int count_warnings = 0;
    int count_info = 0;
    char error_messages[10][100]; // Storage array for error messages

    while (fgets(line, sizeof(line), fp)) { // Loop through each line in the log file

        count_total_logs++;

        if (strstr(line, "ERROR") != NULL) { // If the line contains the word "ERROR"
            count_errors++;
            char error_message[100];
            strcpy(error_message, line);
            strcat(error_messages[count_errors-1], error_message); // Store error message in the array
        }
        else if (strstr(line, "WARNING") != NULL) { // If the line contains the word "WARNING"
            count_warnings++;
        }
        else if (strstr(line, "INFO") != NULL) { // If the line contains the word "INFO"
            count_info++;
        }

    }

    printf("Total logs: %d\n", count_total_logs);
    printf("Errors: %d\n", count_errors);
    printf("Warnings: %d\n", count_warnings);
    printf("Info: %d\n", count_info);

    if (count_errors > 0) { // If there are error messages
        printf("Error messages:\n");
        for (int i=0; i<count_errors; i++) {
            printf("%s", error_messages[i]); // Print each error message
        }
    }

    fclose(fp); // Close the log file

    return 0;

}