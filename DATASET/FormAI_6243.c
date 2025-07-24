//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MB 1024*1024

// function to get the current RAM usage in MB
double getRAMUsageMB() {
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return (double)(pages * page_size) / MB;
}

int main() {
    printf("Starting RAM usage monitoring...\n\n");

    double initialRAMUsage = getRAMUsageMB();

    while (1) {
        // sleep for 1 second
        sleep(1);

        double currRAMUsage = getRAMUsageMB();
        
        // check if RAM usage has changed and print the change
        if (currRAMUsage != initialRAMUsage) {
            double ramUsageChange = currRAMUsage - initialRAMUsage;
            printf("RAM usage has changed by %.2lfMB\n", ramUsageChange);
        }
    }
    
    return 0;
}