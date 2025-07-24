//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define GB (1024 * 1024 * 1024)
#define MB (1024 * 1024)

int main() {
    struct sysinfo system_info;
    sysinfo(&system_info);

    long total_ram = system_info.totalram / MB;
    long free_ram = system_info.freeram / MB;
    long used_ram = total_ram - free_ram;

    printf("Total RAM: %ld MB\n", total_ram);
    printf("Used RAM: %ld MB\n", used_ram);
    printf("Free RAM: %ld MB\n", free_ram);
    
    // calculate the percentage of RAM usage
    float usage_percentage = ((float)used_ram / total_ram) * 100;
    printf("RAM Usage: %.2f%%\n", usage_percentage);

    // check if usage percentage exceeds a certain threshold
    float threshold_percentage = 80.0;
    if (usage_percentage >= threshold_percentage) {
        printf("Warning! High RAM usage.\n");
        // do something here, like freeing up memory
    }

    return 0;
}