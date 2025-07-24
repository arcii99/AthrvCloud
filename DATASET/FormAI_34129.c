//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main() {
    char command[MAX_SIZE];
    char ram_usage[MAX_SIZE];
    int usage;

    while (1) {
        strcpy(command, "ps aux | awk '{sum=sum+$4}; END{print sum}'");
        FILE *fp = popen(command, "r");
        fgets(ram_usage, MAX_SIZE, fp);
        usage = atoi(ram_usage);

        printf("Current RAM usage: %d%%\n", usage);

        if (usage >= 80) {
            printf("RAM usage is high! Initiating measures...\n");
            // perform actions to reduce RAM usage
        }

        pclose(fp);
        sleep(5);
    }

    return 0;
}