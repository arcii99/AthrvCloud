//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int cpu_usage = 0;
    while (1) {
        system("clear"); // clear console screen
        printf("CPU Usage: %d%%\n", cpu_usage);
        cpu_usage = rand() % 101; // generate random percentage value between 0-100
        sleep(1); // wait for 1 second
    }
    return 0;
}