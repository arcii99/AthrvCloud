//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

struct sysinfo info; // structure to hold system information

int main(){

    while(1){

        int total_mem, free_mem, used_mem, cache_mem;

        sysinfo(&info);

        total_mem = info.totalram / 1024 / 1024;   // total RAM in MB
        free_mem = info.freeram / 1024 / 1024;     // free RAM in MB
        cache_mem = info.bufferram / 1024 / 1024;  // cache RAM in MB
        used_mem = total_mem - free_mem - cache_mem; // used RAM in MB

        printf("\nTotal Memory: %d MB", total_mem);
        printf("\nUsed Memory: %d MB", used_mem);
        printf("\nFree Memory: %d MB", free_mem);
        printf("\nCached Memory: %d MB", cache_mem);

        sleep(5); // wait for 5 seconds before updating information
        system("clear"); // clear the screen before updating information
    }

    return 0;
}