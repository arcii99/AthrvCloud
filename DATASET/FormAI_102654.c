//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <unistd.h>

int main() {

    long long int total_mem, free_mem;
    char buffer[1024];

    FILE* meminfo_file = fopen("/proc/meminfo", "r");

    // Reading total memory
    fgets(buffer, sizeof(buffer), meminfo_file);
    sscanf(buffer, "MemTotal: %lld", &total_mem);

    // Reading free memory
    fgets(buffer, sizeof(buffer), meminfo_file);
    sscanf(buffer, "MemFree: %lld", &free_mem);

    // Calculating used memory
    long long int used_mem = total_mem - free_mem;

    printf("Total Memory: %lld KB\n", total_mem);
    printf("Free Memory: %lld KB\n", free_mem);
    printf("Used Memory: %lld KB\n", used_mem);

    fclose(meminfo_file);

    return 0;

}