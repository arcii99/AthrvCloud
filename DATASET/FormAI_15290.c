//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define CHUNK_SIZE 1024
#define DEFAULT_UPDATE_INTERVAL_SECS 5

// Calculate C RAM usage based on /proc/meminfo
long calc_c_ram_usage() {
    long c_ram = 0;
    char* line = malloc(CHUNK_SIZE);
    FILE* meminfo = fopen("/proc/meminfo", "r");
    if (meminfo != NULL) {
        while (fgets(line, CHUNK_SIZE, meminfo)) {
            if (strstr(line, "Committed_AS:") != NULL) {
                c_ram = strtol(line + strlen("Committed_AS:"), NULL, 10);
                break;
            }
        }
        fclose(meminfo);
    }
    free(line);
    return c_ram;
}

int main(int argc, char** argv) {
    int update_interval_secs = DEFAULT_UPDATE_INTERVAL_SECS;
    if (argc == 2) {
        update_interval_secs = atoi(argv[1]);
    }

    pid_t child_pid = fork();
    if (child_pid == 0) { // Child process
        while (1) {
            printf("C RAM usage: %ld kB\n", calc_c_ram_usage());
            sleep(update_interval_secs);
        }
    } else { // Parent process
        printf("C RAM usage monitor started (update interval: %d secs)\n", update_interval_secs);
        wait(NULL); // Wait for child process to exit
    }

    return 0;
}