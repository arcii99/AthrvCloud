//FormAI DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[50], c;
    int total_logs = 0, warning_logs = 0, error_logs = 0;
    printf("Enter the name of the log file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening the file. Please try again later.");
        exit(0);
    }
    while ((c = fgetc(fp)) != EOF) {
        if (c == 'L') {
            total_logs++;
            c = fgetc(fp);
            if (c == 'W')
                warning_logs++;
            else if (c == 'E')
                error_logs++;
        }
    }
    printf("Total Logs: %d\n", total_logs);
    printf("Warning Logs: %d\n", warning_logs);
    printf("Error Logs: %d\n", error_logs);
    fclose(fp);
    return 0;
}