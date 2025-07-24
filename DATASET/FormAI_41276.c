//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: brave
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MB (1024*1024)

int main() {
    struct sysinfo si;
    int interval = 1; // Check memory usage every second
    long prev_used_mem = 0;
    long curr_used_mem;

    while (1) {
        sysinfo(&si);
        curr_used_mem = (si.totalram - si.freeram) / MB;
        printf("RAM usage: %ld MB\n", curr_used_mem);

        if (prev_used_mem != 0) { // Compare with previous memory usage
            long diff_mem = curr_used_mem - prev_used_mem;
            if (diff_mem > 100) { // If usage increased by more than 100 MB
                printf("RAM usage increased by %ld MB!\n", diff_mem);
            }
        }
        prev_used_mem = curr_used_mem; // Update previous memory usage

        sleep(interval);
    }

    return 0;
}