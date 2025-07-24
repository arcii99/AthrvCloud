//FormAI DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char *event)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestamp[256];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);
    FILE *fptr;
    fptr = fopen("system_log.txt", "a");
    fprintf(fptr, "[%s] %s\n", timestamp, event);
    fclose(fptr);
}

int main()
{
    char event[256];
    printf("Enter the event to be logged: ");
    scanf("%[^\n]%*c", event);
    logEvent(event);
    printf("Event logged successfully\n");
    return 0;
}