//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define REFRESH_RATE 5    // how often to refresh the display (seconds)

int main(int argc, char *argv[]) {
    while (1) {
        // get the RAM usage
        FILE *file = fopen("/proc/meminfo", "r");
        long mem_total, mem_free, mem_used;
        fscanf(file, "MemTotal: %ld kB\nMemFree: %ld kB\n", &mem_total, &mem_free);
        fclose(file);
        mem_used = mem_total - mem_free;

        // calculate the percentage used
        float percentage_used = ((float) mem_used / mem_total) * 100;

        // display the information
        printf("\033[2J\033[1;1H");    // clear the screen
        printf("RAM:\n");
        printf("    Total:       %10ld kB\n", mem_total);
        printf("    Used:        %10ld kB\n", mem_used);
        printf("    Free:        %10ld kB\n", mem_free);
        printf("    Percentage:  %10.2f%%\n", percentage_used);

        // wait and repeat
        sleep(REFRESH_RATE);
    }
    return 0;
}