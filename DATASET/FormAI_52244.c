//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_LINE_LENGTH 256
#define REFRESH_INTERVAL 2

int main() {
    struct sysinfo si;

    while (1) {
        if (sysinfo(&si) != 0) {
            printf("Error while getting system information!\n");
            exit(EXIT_FAILURE);
        }

        long long total_ram = si.totalram * si.mem_unit / (1024 * 1024);
        long long used_ram = (si.totalram - si.freeram) * si.mem_unit / (1024 * 1024);
        float used_percent = (float) used_ram / (float) total_ram * 100.0;

        char status_line[MAX_LINE_LENGTH];
        sprintf(status_line, "RAM Usage: %lld MB / %lld MB (%.2f%%)", used_ram, total_ram, used_percent);
        printf("%s\n", status_line);

        sleep(REFRESH_INTERVAL);
    }

    return 0;
}