//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {

    struct sysinfo sys_info;
    unsigned long long totalramuse, bufferramuse, freeramuse;
    double ramusage;   

    while(1) {
        if(sysinfo(&sys_info) != 0) {
            printf("Error getting system info.\n");
            exit(EXIT_FAILURE);
        }

        totalramuse = sys_info.totalram / 1024;
        bufferramuse = sys_info.bufferram / 1024;
        freeramuse = sys_info.freeram / 1024;
        ramusage = ((double)(totalramuse - bufferramuse - freeramuse) / totalramuse) * 100;

        printf("RAM Total Usage: %llu KB\n", totalramuse);
        printf("RAM Buffer Usage: %llu KB\n", bufferramuse);
        printf("RAM Free Usage: %llu KB\n", freeramuse);
        printf("RAM Usage: %.2f %%\n\n", ramusage);

        sleep(5); // update every 5 seconds
    }

    return 0;
}