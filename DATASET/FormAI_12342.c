//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
    #include <sys/sysinfo.h>
#elif _WIN32
    #include <windows.h>
#endif

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void print_usage(int kilobytes) {
    int megabytes = kilobytes / 1024;
    printf("\nCurrent RAM usage: %dKB (%dMB)\n", kilobytes, megabytes);
}

int get_ram_usage() {
    #ifdef __linux__
        struct sysinfo mem_info;
        sysinfo(&mem_info);
        return mem_info.totalram - mem_info.freeram;
    #elif _WIN32
        MEMORYSTATUSEX mem_info;
        mem_info.dwLength = sizeof(mem_info);
        GlobalMemoryStatusEx(&mem_info);
        return mem_info.ullTotalPhys - mem_info.ullAvailPhys;
    #else
        return 0;
    #endif
}

int main() {
    printf("Welcome to the RAM usage monitor!\n");

    while (1) {
        int usage = get_ram_usage();
        print_usage(usage);
        clear_screen();
        sleep(2);
    }

    return 0;
}