//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int max_ram = 1024;
    int curr_ram = 0;
    time_t t;
    srand((unsigned) time(&t));
    while (1) {
        int rand_num = rand() % 50 + 1;
        printf("Allocating %dMB memory...\n", rand_num);
        usleep(rand_num * 1000); // simulate memory allocation delay
        curr_ram += rand_num;
        int used_percent = curr_ram * 100 / max_ram;
        printf("Current RAM usage: %d/%dMB (%d%%)\n", curr_ram, max_ram, used_percent);
        if (used_percent >= 90) {
            printf("WARNING: High memory usage detected!\n");
            // simulate releasing memory
            int rand_release = rand() % 50 + 1;
            printf("Releasing %dMB memory...\n", rand_release);
            usleep(rand_release * 1000); // simulate memory release delay
            curr_ram -= rand_release;
            printf("Current RAM usage after release: %d/%dMB (%d%%)\n", curr_ram, max_ram, curr_ram * 100 / max_ram);
        }
    }
    return 0;
}