//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define ERROR -1
#define SUCCESS 0
#define MAX_BUF_SIZE 512

int main() {
    char buf[MAX_BUF_SIZE];
    struct sysinfo si;
    
    while(1) {
        if (sysinfo(&si) == ERROR) {
            printf("Error: sysinfo\n");
            return ERROR;
        }
        
        long long total_ram = si.totalram * si.mem_unit;
        long long free_ram = si.freeram * si.mem_unit;
        long long used_ram = total_ram - free_ram;
        float used_percent = (float) used_ram / (float) total_ram * 100;
        
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "RAM USAGE MONITOR: %.2f%% used (%lld MB)\n", used_percent, used_ram / (1024 * 1024));
        printf("%s", buf);
        
        sleep(1);
    }
    
    return SUCCESS;
}