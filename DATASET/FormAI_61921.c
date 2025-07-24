//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

#define MB (1024 * 1024)

void printHeader() {
    printf("%8s %8s %8s\n", "PID", "RAM", "TIME");
    printf("--------------------------------\n");
}

int main() {
    printHeader();

    pid_t pid = getpid();

    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    while (1) {
        char filename[30];
        sprintf(filename, "/proc/%d/status", pid);

        FILE* status_file = fopen(filename, "r");

        if (status_file == NULL) {
            fprintf(stderr, "Error: Could not open file %s\n", filename);
            exit(EXIT_FAILURE);
        }

        char line[256];
        int ram_kb = 0;

        while (fgets(line, sizeof(line), status_file)) {
            if (strncmp(line, "VmRSS:", 6) == 0) {
                sscanf(line, "%*s %d", &ram_kb);
                break;
            }
        }

        fclose(status_file);

        int ram_mb = ram_kb / 1024;

        struct timeval current_time;
        gettimeofday(&current_time, NULL);

        long time_difference = ((current_time.tv_sec - start_time.tv_sec) * 1000) +
                ((current_time.tv_usec - start_time.tv_usec) / 1000);
        int hours = time_difference / (60 * 60 * 1000);
        int minutes = (time_difference % (60 * 60 * 1000)) / (60 * 1000);
        int seconds = ((time_difference % (60 * 60 * 1000)) % (60 * 1000)) / 1000;

        printf("%8d %8dMB %02d:%02d:%02d\n", pid, ram_mb, hours, minutes, seconds);

        sleep(1);
    }

    return 0;
}