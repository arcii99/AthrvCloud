//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int load = -1; // initialize with an invalid value
    while (1) {
        FILE *fp = fopen("/proc/loadavg", "r");
        if (fp == NULL) {
            fprintf(stderr, "Cannot open /proc/loadavg\n");
            return 1;
        }

        // read the first value of the file, which is the CPU load
        if (fscanf(fp, "%d", &load) != 1) {
            fprintf(stderr, "Cannot read CPU load from /proc/loadavg\n");
            fclose(fp);
            return 1;
        }

        fclose(fp);

        printf("CPU usage: %d%%\n", (int)((double)load * 100 / 4));

        // wait for 1 second before checking again
        sleep(1);
    }

    return 0;
}