//FormAI DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char buffer[1024], log_line[1024], timestamp[20], message[1000];
    int line_count = 0, error_count = 0;

    fp = fopen("server.log", "r");
    if (fp == NULL) {
        perror("Error opening file.");
        exit(1);
    }

    printf("Analyzing server logs...\n");

    while(fgets(buffer, 1024, fp)) {
        line_count++;
        sscanf(buffer, "[%[^]]] %[^\n]", timestamp, message);
        if (strstr(message, "ERROR") != NULL) {
            error_count++;
            strcpy(log_line, buffer);
            printf("Error found on Line %d.\n", line_count);
            printf("Timestamp: %s\n", timestamp);
            printf("Log Line: %s", log_line);
        }
    }

    printf("Log analysis complete.\n%d lines scanned.\n%d errors found.\n", line_count, error_count);

    fclose(fp);
    return 0;
}