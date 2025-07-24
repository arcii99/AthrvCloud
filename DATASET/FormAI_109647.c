//FormAI DATASET v1.0 Category: System event logger ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event);

int main()
{
    char event[100];
    printf("Enter the event message: ");
    fgets(event, 100, stdin);
    log_event(event);
    return 0;
}

void log_event(char* event)
{
    time_t current_time = time(NULL);
    struct tm* tm = localtime(&current_time);
    char filename[20];
    sprintf(filename, "%d-%02d-%02d.log", tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday);
    FILE* fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: Unable to open file.");
        exit(1);
    }
    fprintf(fp, "%d:%02d:%02d\t%s\n", tm->tm_hour, tm->tm_min, tm->tm_sec, event);
    fclose(fp);
}