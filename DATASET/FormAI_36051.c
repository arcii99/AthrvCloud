//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main() 
{
    struct sysinfo info;
    if(sysinfo(&info) != 0) 
    {
        printf("Error getting system info\n");
        exit(1);
    }
    long long total = info.totalram;
    total *= info.mem_unit;
    long long free = info.freeram;
    free *= info.mem_unit;
    long long used = total - free;

    printf("Total RAM: %lld MB\n", total / 1024 / 1024);
    printf("Used RAM: %lld MB\n", used / 1024 / 1024);
    printf("Free RAM: %lld MB\n", free / 1024 / 1024);

    return 0;
}