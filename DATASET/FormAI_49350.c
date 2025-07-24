//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main()
{
    FILE* fp;
    char path[MAX_SIZE];
    char line[MAX_SIZE];
    int ram_usage;

    while (1) {
        fp = fopen("/proc/self/status", "r");
        if (fp == NULL) {
            printf("Failed to open status file\n");
            exit(EXIT_FAILURE);
        }

        while (fgets(line, MAX_SIZE, fp) != NULL) {
            if (strncmp(line, "VmRSS:", 6) == 0) {
                ram_usage = atoi(line + 7);
                printf("Current RAM usage: %d KB\n", ram_usage);
                break;
            }
        }

        fclose(fp);
        sleep(1);
    }

    return 0;
}