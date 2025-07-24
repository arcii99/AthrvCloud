//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MB (1024 * 1024)

/*
* A simple and unique program to monitor C RAM usage in real-time.
* Program uses a single-threaded approach to monitor RAM usage.
*/

void print_info() {
    printf("--------------------------\n");
    printf("RAM USAGE MONITOR\n");
    printf("--------------------------\n");
    printf("RAM Total\tRAM Used\tRAM Free\n");
}

int main() {
    print_info();
    int interval = 1; //interval in seconds
    struct sysinfo mem_info;
    while(1) {
        if(sysinfo(&mem_info) != 0) {
            printf("Error while fetching memory info\n");
            exit(1);
        }
        long long total_ram = mem_info.totalram / MB;
        long long used_ram = (mem_info.totalram - mem_info.freeram) / MB;
        long long free_ram = mem_info.freeram / MB;

        printf("%lld MB\t\t%lld MB\t\t%lld MB\n", total_ram, used_ram, free_ram);

        usleep(interval * 1000000); //Sleep for interval seconds
    }
    return 0;
}