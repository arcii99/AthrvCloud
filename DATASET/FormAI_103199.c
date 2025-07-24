//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 50

int getRamUsage() {
    FILE* fp;
    long memFree;
    long memTotal;
    char buf[MAX_BUF_SIZE];
    
    fp = fopen("/proc/meminfo", "r");
    
    while (fgets(buf, MAX_BUF_SIZE, fp)) {
        if (strncmp(buf, "MemTotal:", 9) == 0) {
            sscanf(buf + 9, "%ld", &memTotal);
        }
        if (strncmp(buf, "MemFree:", 8) == 0) {
            sscanf(buf + 8, "%ld", &memFree);
        }
    }
    
    fclose(fp);
    
    return (int)(((double)(memTotal - memFree) / (double)memTotal) * 100);
}

int main() {
    int ramUsage = getRamUsage();
    
    while (1) {
        if (ramUsage > 90) {
            printf("[CPU USAGE WARNING] Memory usage is above 90%%!\n");
            system("start firefox.exe https://stackoverflow.com/questions/5798140/how-to-shrink-windows-after-resizing-the-partition#comment98294362_5798143");
            printf("\n\n");
        }
        else {
            printf("[CPU USAGE INFO] Memory usage is at %d%%.\n", ramUsage);
            printf("\n\n");
        }
        sleep(1);
        ramUsage = getRamUsage();
    }
    
    return 0;
}