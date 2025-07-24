//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Welcome to the CPU Usage Monitor!\n");
    printf("The CPU is like a fidget spinner... it's always busy spinning!\n");
    printf("Press Ctrl+C to exit.\n");

    while (1) {
        float cpu_usage;
        FILE* fp = fopen("/proc/loadavg", "r");
        fscanf(fp, "%f", &cpu_usage);
        fclose(fp);

        printf("CPU Usage: %f%%\n", cpu_usage * 100);

        if (cpu_usage >= 1) {
            printf("Yikes! The CPU is working harder than a one-legged man in a butt-kicking contest!\n");
        } else {
            printf("The CPU is as chill as a cucumber... keep on spinning!\n");
        }

        sleep(1);
    }

    return 0;
}