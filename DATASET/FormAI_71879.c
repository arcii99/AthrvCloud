//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

#define GB (1024 * 1024 * 1024)

long long get_ram_usage()
{
    struct sysinfo info;
    if (sysinfo(&info) == -1) {
        printf("Error getting system information\n");
        exit(EXIT_FAILURE);
    }
    long long used_memory = info.totalram - info.freeram;
    return used_memory / GB;
}

int main()
{
    time_t current_time;
    char* time_string;

    while (1) {
        long long ram_usage = get_ram_usage();
        time(&current_time);
        time_string = ctime(&current_time);
        time_string[strlen(time_string) - 1] = '\0';
        printf("%s - RAM usage: %lld GB\n", time_string, ram_usage);
        sleep(60);
    }

    return 0;
}