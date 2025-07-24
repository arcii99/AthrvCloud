//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    int delay = 3; // update interval in seconds
    printf("Welcome to the CPU Usage Monitor!\n");
    printf("This program will display the CPU usage every %d seconds\n", delay);
    printf("Press Ctrl+C to exit.\n\n");

    while(1) {
        struct sysinfo info;
        if(sysinfo(&info) != 0) {
            printf("Error: Unable to fetch system information\n");
            exit(1);
        }

        double total = info.totalram / 1024;
        double used = (info.totalram - info.freeram) / 1024;
        double usage = used / total * 100;

        printf("\rCPU Usage: %.2f%%\t\t", usage);
        fflush(stdout);
        sleep(delay);
    }

    return 0;
}