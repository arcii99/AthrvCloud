//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    FILE *fp;
    char line[256];

    while (1) {
        fp = fopen("/proc/loadavg", "r");
        if (fp == NULL) {
            printf("Error opening file\n");
            exit(1);
        }
        fgets(line, sizeof(line), fp);
        fclose(fp);

        char *p = strtok(line, " ");
        if (p != NULL) {
            printf("CPU usage: %s%%\n", p);
        }

        sleep(1);
    }

    return 0;
}