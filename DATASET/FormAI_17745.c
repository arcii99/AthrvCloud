//FormAI DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *fp;
    char message[100];
    time_t current_time;
    struct tm * time_info;
    char time_str[30];

    fp = fopen("system_log.txt", "a");

    if (fp == NULL) {
        printf("Error in opening the file.\n");
        exit(1);
    }

    printf("Enter the message to log: ");
    fgets(message, 100, stdin);

    // Get current time
    time(&current_time);
    time_info = localtime(&current_time);

    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);

    fprintf(fp, "[%s] %s\n", time_str, message);

    fclose(fp);

    printf("Message logged successfully.\n");

    return 0;
}