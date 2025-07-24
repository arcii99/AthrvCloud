//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: realistic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>

#define MAX_RAM 1073741824 //1 GB of RAM
#define INTERVAL 2 //time interval between each sample

int main(){
    struct sysinfo info;
    long long used_ram;

    while(1){
        if(sysinfo(&info) != 0){
            printf("Error: unable to fetch system info\n");
            exit(1);
        }

        used_ram = (long long)info.totalram - (long long)info.freeram;
        float ram_usage_percent = (float)used_ram / (float)MAX_RAM * 100.0;

        printf("RAM usage: %.2f%%\n", ram_usage_percent);

        sleep(INTERVAL);
    }

    return 0;
}