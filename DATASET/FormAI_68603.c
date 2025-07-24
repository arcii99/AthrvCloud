//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: surprised
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("Oh my god! I can't believe I'm a CPU usage monitor!\n");
    printf("This is so exciting, I can't wait to get started!\n\n");

    while(1) {
        int cpu_usage = rand() % 100; // Generate a random CPU usage (0-99)
        printf("CPU usage: %d%%\n", cpu_usage);
        sleep(1); // Wait for a second before checking again
    }

    return 0;
}