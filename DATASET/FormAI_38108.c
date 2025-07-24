//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    const int INTERVAL_IN_SECONDS = 1;
    const int BUFFER_SIZE = 512;
    char buffer[BUFFER_SIZE];
    int loadavg;
    FILE* file;

    while (1) {
        file = fopen("/proc/loadavg", "r");
        if (file == NULL) {
            printf("Unable to open /proc/loadavg");
            return -1;
        }

        fgets(buffer, BUFFER_SIZE, file);
        fclose(file);

        // Parse the CPU load from the output of /proc/loadavg
        sscanf(buffer, "%d", &loadavg);

        // Output the current CPU load
        printf("CPU Usage: %d%%\n", loadavg);

        // Wait for some time before checking the CPU load again
        sleep(INTERVAL_IN_SECONDS);
    }

    return 0;
}