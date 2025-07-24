//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main(){
    struct sysinfo info;
    while(1){
        if(sysinfo(&info)==-1){
            printf("Error: Could not fetch system information.\n");
            exit(1);
        }
        printf("RAM Usage: %lu KB\n", (info.totalram - info.freeram) / 1024);
        usleep(500000);
    }
    return 0;
}