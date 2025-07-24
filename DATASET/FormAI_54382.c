//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MB (1024*1024)

int main() {
    struct sysinfo info;

    while (1) {
        if(sysinfo(&info) != 0) {
            printf("Error: Unable to get system information.\n");
            exit(EXIT_FAILURE);
        }

        float total_mem = info.totalram / MB;
        float free_mem = info.freeram / MB;
        float used_mem = total_mem - free_mem;
        float usage_perc = used_mem / total_mem * 100;

        printf("Total Memory: %.2fMB\n", total_mem);
        printf("Free Memory: %.2fMB\n", free_mem);
        printf("Used Memory: %.2fMB\n", used_mem);
        printf("Memory Usage: %.2f%%\n", usage_perc);

        sleep(1);
        system("clear"); //clear the screen to update the output
    }

    return 0;
}