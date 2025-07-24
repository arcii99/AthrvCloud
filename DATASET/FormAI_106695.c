//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    unsigned long long memUsed;
    long pageSize = sysconf(_SC_PAGESIZE);
    char buffer[1024];
    FILE* file = fopen("/proc/self/statm", "r");
    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "%*s%llu", &memUsed);
    fclose(file);
    printf("Current RAM usage: %llu KB\n", (memUsed * pageSize)/1024);

    while(1){
        sleep(1);
        FILE* file = fopen("/proc/self/statm", "r");
        fgets(buffer, sizeof(buffer), file);
        sscanf(buffer, "%*s%llu", &memUsed);
        fclose(file);
        printf("Current RAM usage: %llu KB\n", (memUsed * pageSize)/1024);
    }
    
    return 0;
}