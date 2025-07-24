//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <string.h>

int main()
{
    struct sysinfo info;
    char buffer[1024];
    
    while (1) {
        sysinfo(&info);
        sprintf(buffer, "Total memory: %ld, Free memory: %ld\n", 
            info.totalram, info.freeram);
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    return 0;
}