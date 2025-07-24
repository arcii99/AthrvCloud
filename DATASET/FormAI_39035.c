//FormAI DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char logText[] = "I saw her unexpectedly at the server room.\n"
                      "My heart skipped a beat as I checked her id.\n"
                      "She asked me what I was doing there, and I stumbled over my words.\n"
                      "But she smiled, and that was enough to make my day.\n"
                      "I wrote this code to analyze the logs, hoping to see her name again.\n";

    char searchName[] = "her";

    int count = 0;
    char *ptr = strstr(logText, searchName);
    while(ptr != NULL)
    {
        count++;
        ptr = strstr(ptr + 1, searchName);
    }

    printf("Analysis Report\n");
    printf("----------------\n");
    printf("Total number of times %s appears in the log: %d\n", searchName, count);

    return 0;
}