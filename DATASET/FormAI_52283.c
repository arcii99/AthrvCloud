//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#define BUF_SIZE 256

int main() {
    struct sysinfo info;
    long total_mem, free_mem, used_mem;
    char buffer[BUF_SIZE];
    
    while(1) {
        if(sysinfo(&info) == 0) {
            total_mem = info.totalram * info.mem_unit / (1024 * 1024); // Convert to MB
            free_mem = info.freeram * info.mem_unit / (1024 * 1024); // Convert to MB
            used_mem = total_mem - free_mem;
            
            sprintf(buffer, "Total RAM: %ld MB, Used RAM: %ld MB, Free RAM: %ld MB\n", 
                    total_mem, used_mem, free_mem);
            printf("%s", buffer);
        }
        
        sleep(1);
    }
    
    return 0;
}