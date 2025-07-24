//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LOG_CHARS 200

void checkLogs(const char* logs[], int numLogs)
{
    int i,j;
    char* keywords[] = {"hack", "intrusion", "compromise", "breach"};

    for(i=0; i<numLogs; i++)
    {
        for(j=0; j<4; j++)
        {
            if(strstr(logs[i], keywords[j]) != NULL)
            {
                printf("ALERT! Suspicious activity detected in log entry %d:\n%s\n", i+1, logs[i]);
                break;
            }
        }
    }
}

int main()
{
    char logs[MAX_LOG_ENTRIES][MAX_LOG_CHARS];
    int numLogs = 0;
    char input[MAX_LOG_CHARS];
    int i = 0;

    printf("Enter security logs. Press Ctrl+D to stop.\n");

    while(fgets(input, MAX_LOG_CHARS, stdin) != NULL && numLogs < MAX_LOG_ENTRIES)
    {
        strcpy(logs[numLogs], input);
        numLogs++;
    }

    printf("\nAnalyzing %d security logs...\n\n", numLogs);

    checkLogs((const char**)logs, numLogs);

    return 0;
}