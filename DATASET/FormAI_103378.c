//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main(void) {
    struct sysinfo sys_info;

    while(1) {
        // Clear terminal
        printf("\033[2J\033[H");
        printf("=== Welcome to the C RAM Usage Monitor Program! ===\n\n");

        if(sysinfo(&sys_info) != 0) {
            printf("Error getting system information.\n");
            exit(EXIT_FAILURE);
        }

        printf("Total RAM: %ldMB\n", (sys_info.totalram / 1024) / 1024);
        printf("Free RAM: %ldMB\n", (sys_info.freeram / 1024) / 1024);
        printf("Money to buy more RAM: $%ld\n", (sys_info.totalram - sys_info.freeram) / 1000000 * 10);

        sleep(1);
    }

    return 0;
}