//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#define refresh_rate 5 // Refresh rate in seconds

struct sysinfo mem_info; // Global variable for memory information

void printHeader() {
    printf("%10s %10s %10s %10s\n", "Total", "Used", "Free", "Usage");
    printf("---------------------------------------\n");
}

float getRamUsage() {
    float used_memory = mem_info.totalram - mem_info.freeram;
    return (used_memory / mem_info.totalram) * 100;
}

void printUsage() {
    sysinfo(&mem_info);
    float ram_usage = getRamUsage();
    printf("%10ld %10ld %10ld %10.2f %%\n", 
        mem_info.totalram / 1024 / 1024, 
        (mem_info.totalram - mem_info.freeram) / 1024 / 1024, 
        mem_info.freeram / 1024 / 1024, 
        ram_usage);
}

int main() {
    printHeader();

    while(1) {
        printUsage();
        sleep(refresh_rate);
    }

    return 0;
}