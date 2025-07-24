//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    while(1) {
        struct sysinfo sys_info;
        if(sysinfo(&sys_info) != 0) {
            printf("Error fetching system information.");
            exit(1);
        }
        printf("Total RAM: %5ld MB \tFree RAM: %5ld MB\n", sys_info.totalram/1024/1024, sys_info.freeram/1024/1024);
        sleep(5); // wait 5 seconds before refreshing
    }
    return 0;
}