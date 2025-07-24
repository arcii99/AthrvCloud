//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 512

int main()
{
    char buffer[BUFFER_SIZE];
    FILE* fp;
    char* command = "/usr/bin/top -b -n 2 | grep 'Cpu(s)' | tail -n 1 | awk '{print $2 + $4}'";
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {}
    pclose(fp);
    double cpu_usage = atof(buffer);
    printf("Current CPU Usage is: %.2f %%\n", cpu_usage);
    return 0;
}