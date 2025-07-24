//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    while (1) {
        char cmd[50];
        sprintf(cmd, "ps -eo pmem | awk '{sum+=$1} END {print sum}'");
        FILE* output = popen(cmd, "r");
        if (output == NULL) {
            printf("Error: Failed to execute command.\n");
            exit(1);
        }

        char buffer[512];
        fgets(buffer, 512, output);
        float ramUsage = strtod(buffer, NULL);
        printf("Current RAM usage: %.2f%%\n", ramUsage);

        pclose(output);
        sleep(5);
    }
    return 0;
}