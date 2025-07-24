//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define CPU_INFO_FILE "/proc/stat"

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];

    // initialize variables
    long prev_idle, prev_total;
    long idle, total;
    int cpu_usage;

    // read the initial idle and total CPU usage
    fp = fopen(CPU_INFO_FILE, "r");
    fgets(line, MAX_LINE_LENGTH, fp);
    sscanf(line, "cpu %ld %ld %ld %ld %ld %ld %ld", &prev_idle, &prev_idle, &prev_idle, &prev_idle, &prev_idle, &prev_total, &prev_idle);

    // loop infinitely to monitor CPU usage
    while (1) {
        // wait for 1 second
        sleep(1);

        // read the latest idle and total CPU usage
        rewind(fp);
        fgets(line, MAX_LINE_LENGTH, fp);
        sscanf(line, "cpu %ld %ld %ld %ld %ld %ld %ld", &idle, &idle, &idle, &idle, &idle, &total, &idle);

        // calculate the CPU usage percentage
        cpu_usage = (int)(100 * (1.0 - ((double)(total - prev_total) / (double)(idle - prev_idle))));

        // print the CPU usage percentage
        printf("CPU Usage: %d%%\n", cpu_usage);

        // update the previous idle and total CPU usage
        prev_idle = idle;
        prev_total = total;
    }

    return 0;
}