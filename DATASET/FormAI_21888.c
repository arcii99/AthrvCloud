//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESS_NAME_LENGTH 200
#define MAX_PROCESSES 100

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    float cpuUsage;
} Process;

int main(int argc, char *argv[]) {
    Process processes[MAX_PROCESSES];
    char *command = "ps -eo pid,%cpu,comm --sort=-%cpu";
    char line[200], name[200];

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    int i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (i == 0 || i > MAX_PROCESSES) { // Ignore first line and if we have too many processes
            i++;
            continue;
        }
        sscanf(line, "%*d %f %s", &processes[i-1].cpuUsage, name);
        strncpy(processes[i-1].name, name, MAX_PROCESS_NAME_LENGTH - 1);

        i++;
    }
    pclose(fp);

    printf("CPU usage:\n");
    for (int i = 0; i < MAX_PROCESSES && processes[i].cpuUsage > 0; i++) {
        printf("%s: %.2f%%\n", processes[i].name, processes[i].cpuUsage);
    }

    return 0;
}