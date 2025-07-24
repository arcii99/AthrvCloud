//FormAI DATASET v1.0 Category: System event logger ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *logFile;
    logFile = fopen("system_events.log", "a");

    char eventMsg[100];

    srand(time(NULL));

    int eventType = rand() % 3;

    if (eventType == 0)
    {
        sprintf(eventMsg, "A critical error has occurred.");
    }
    else if (eventType == 1)
    {
        sprintf(eventMsg, "A warning has been issued.");
    }
    else
    {
        sprintf(eventMsg, "An information message has been logged.");
    }

    fprintf(logFile, "%s\n", eventMsg);

    printf("Alas, a system event has transpired!\n");
    printf("%s\n", eventMsg);

    fclose(logFile);

    return 0;
}