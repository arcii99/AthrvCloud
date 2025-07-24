//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_PROCESS_NAME 64

typedef struct
{
    char name[MAX_PROCESS_NAME];
    int pid;
    float usage;
} ProcessInfo;

int countProcesses()
{
    int count = 0;
    FILE *fp;
    char line[MAX_LINE];

    fp = popen("ps axo pid,args,%mem | awk '{print $1,$2,$3}'", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening pipe.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp) != NULL)
    {
        count++;
    }

    pclose(fp);
    return count - 1; // subtract 1 to exclude the header row
}

ProcessInfo *getProcesses(int *len)
{
    int count = countProcesses();
    ProcessInfo *processes = (ProcessInfo *)malloc(count * sizeof(ProcessInfo));
    FILE *fp;
    char line[MAX_LINE];
    int i = 0;

    fp = popen("ps axo pid,args,%mem | awk '{print $1,$2,$3}'", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening pipe.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp) != NULL)
    {
        if (isdigit(line[0]))
        {
            char *token = strtok(line, " ");
            processes[i].pid = atoi(token);

            token = strtok(NULL, " ");
            strncpy(processes[i].name, token, MAX_PROCESS_NAME);

            token = strtok(NULL, " ");
            processes[i].usage = atof(token);

            i++;
        }
    }

    pclose(fp);
    *len = count;
    return processes;
}

void printProcesses(ProcessInfo *processes, int len)
{
    printf("PID\tNAME\t\t\t\tUSAGE\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t%-32s\t%.1f%%\n", processes[i].pid, processes[i].name, processes[i].usage);
    }
}

int main()
{
    int len;
    ProcessInfo *processes = getProcesses(&len);
    printProcesses(processes, len);
    free(processes);
    return 0;
}