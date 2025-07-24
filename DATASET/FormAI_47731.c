//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define INTERVAL 1  // time interval between each monitor update in seconds

// function to convert bytes to megabytes
double bytes_to_mb(unsigned long long bytes){
    return (bytes / 1024.0) / 1024.0;
}

// function to get the current RAM usage in megabytes
double get_ram_usage(){
    struct sysinfo info;
    sysinfo(&info);
    return bytes_to_mb(info.totalram - info.freeram);
}

int main(){
    printf("Starting RAM usage monitor...\n");
    printf("Press Ctrl + C to exit.\n\n");
    printf("------------------------------------\n");
    printf("| Time    | RAM Usage (MB) |\n");
    printf("------------------------------------\n");

    while(1){
        double ram_usage = get_ram_usage();
        time_t current_time = time(NULL);
        struct tm *time_info = localtime(&current_time);
        char time_str[9];
        strftime(time_str, sizeof(time_str), "%H:%M:%S", time_info);
        printf("| %s | %10.2f   |\n", time_str, ram_usage);
        fflush(stdout);
        sleep(INTERVAL);
    }

    return 0;
}