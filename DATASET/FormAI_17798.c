//FormAI DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(const char* source, const char* message)
{
    time_t current_time = time(NULL);
    char time_string[25];
    strftime(time_string, 25, "%Y-%m-%d %H:%M:%S", localtime(&current_time));
    FILE* fp = fopen("event_log.txt", "a");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open event log file\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "[%s] [%s]: %s\n", time_string, source, message);
    fclose(fp);
}

int main()
{
    printf("=========================\n");
    printf("== C System Event Logger ==\n");
    printf("=========================\n\n");
    char source[50];
    char message[1024];
    printf("Enter the source of the event (e.g. application, system): ");
    scanf("%s", source);
    printf("Enter the message of the event: ");
    scanf(" %[^\n]s", message);
    log_event(source, message);
    printf("\nEvent logged successfully!\n");
    return 0;
}