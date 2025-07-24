//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND 256

int main() {
    FILE *fp;
    char command[MAX_COMMAND], result[MAX_COMMAND], *split;
    double usage;
    int count = 0;

    while (1) {
        snprintf(command, MAX_COMMAND, "ps -p %d -o %%cpu | tail -1", getpid());
        fp = popen(command, "r");
        
        if (fp == NULL) {
            printf("Failed to execute command\n");
            exit(1);
        }

        fgets(result, sizeof(result), fp);
        usage = strtod(result, &split);
        printf("CPU usage: %.2f%%\n", usage);
        pclose(fp);
        sleep(1);
        count++;

        if (count > 10) {
            break;
        }
    }

    return 0;
}