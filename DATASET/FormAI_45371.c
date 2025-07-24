//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: high level of detail
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    while(1) {
        if(sysinfo(&info)) {
            exit(EXIT_FAILURE);
        }
        printf("Total RAM: %ld kB\n", info.totalram/1024);
        printf("Free RAM: %ld kB\n", info.freeram/1024);
        printf("Used RAM: %ld kB\n", (info.totalram-info.freeram)/1024);
        printf("----------------------\n");
        sleep(1); //wait 1 second before updating values
    }
    return 0;
}