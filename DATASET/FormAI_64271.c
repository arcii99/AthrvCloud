//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo si;
    int error = sysinfo(&si);
    if(error != 0) {
        printf("Error: Could not retrieve system information.\n");
        return 1;
    }
    long long total_mem = si.totalram / (1024 * 1024);
    long long free_mem = si.freeram / (1024 * 1024);
    long long used_mem = total_mem - free_mem;

    printf("Total memory: %lld MB\n", total_mem);
    printf("Free memory: %lld MB\n", free_mem);
    printf("Used memory: %lld MB\n", used_mem);

    return 0;
}