//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_IP_SIZE 16

void logEvent(char *ipAddress, char *event)
{
    FILE *file = fopen("intrusion.log", "a");

    if (file == NULL)
    {
        printf("Error: Could not open log file.");
        return;
    }

    char logLine[MAX_LOG_SIZE];
    snprintf(logLine, sizeof(logLine), "IP Address: %s - Event: %s\n", ipAddress, event);
    fputs(logLine, file);

    fclose(file);
}

int main()
{
    char ipAddress[MAX_IP_SIZE];
    char event[MAX_LOG_SIZE];

    printf("Enter IP Address: ");
    fgets(ipAddress, sizeof(ipAddress), stdin);
    ipAddress[strlen(ipAddress) - 1] = '\0';

    printf("Enter Event: ");
    fgets(event, sizeof(event), stdin);
    event[strlen(event) - 1] = '\0';

    logEvent(ipAddress, event);

    printf("Log saved successfully!");

    return 0;
}