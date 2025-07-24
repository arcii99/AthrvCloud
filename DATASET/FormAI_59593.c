//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Starting RAM usage monitor...\n");

    while (1) {
        FILE* fp;
        char path[100];
        char buffer[64];
        float usage;

        // read total memory and free memory
        fp = popen("cat /proc/meminfo | grep MemTotal | awk '{print $2}'", "r");
        fgets(buffer, sizeof(buffer), fp);
        int total_mem = atoi(buffer);
        pclose(fp);

        fp = popen("cat /proc/meminfo | grep MemFree | awk '{print $2}'", "r");
        fgets(buffer, sizeof(buffer), fp);
        int free_mem = atoi(buffer);
        pclose(fp);

        // calculate used memory
        int used_mem = total_mem - free_mem;

        // calculate usage percentage
        usage = (float)used_mem / total_mem * 100.0;

        // print usage percentage
        printf("Current RAM usage: %.2f%\n", usage);

        // wait for 5 seconds before checking again
        sleep(5);
    }

    return 0;
}