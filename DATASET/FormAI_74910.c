//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

void print_usage(struct sysinfo* meminfo) {
    printf("Total RAM: %lu MB\n", meminfo->totalram / 1024 / 1024);
    printf("Free RAM: %lu MB\n", meminfo->freeram / 1024 / 1024);
    printf("Used RAM: %lu MB\n", (meminfo->totalram - meminfo->freeram) / 1024 / 1024);
    printf("RAM Usage Percentage: %f%%\n", 100 * (float)(meminfo->totalram - meminfo->freeram) / meminfo->totalram);
}

void check_usage() {
    struct sysinfo meminfo;
    sysinfo(&meminfo);
    print_usage(&meminfo);
}

int main(int argc, const char* argv[]) {
    while (1) {
        check_usage();
        sleep(1);
    }
    return 0;
}