//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main()
{
    char command[MAX_SIZE];
    char usage[MAX_SIZE];
    while (1)
    {
        sprintf(command, "ps -eo pmem | awk '{$1=\"\";print}' | sort -nr | head -1");
        FILE *p = popen(command, "r");
        fgets(usage, MAX_SIZE, p);
        float ram_usage = atof(usage);
        pclose(p);
        printf("Current RAM usage: %.2f%%\n", ram_usage);
        if (ram_usage > 80.0)
        {
            printf("Oh my God! RAM usage is above 80%%. Please kill some processes!!\n");
        }
        sleep(5);
    }
    return 0;
}