//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MB 1024 * 1024

int main() {
    const int UPDATE_INTERVAL = 1;  // update interval in seconds
    int count = 0;
    struct sysinfo info;
    
    printf("Starting C RAM Usage Monitor...\n");
    
    while (1) {
        sleep(UPDATE_INTERVAL);
        
        if (sysinfo(&info) != 0) {
            printf("Error: sysinfo failed.\n");
            exit(1);
        }
        
        double total = (double)info.totalram * info.mem_unit / MB;
        double free = (double)info.freeram * info.mem_unit / MB;
        double used = total - free;
        double percent_used = used / total * 100;
        
        printf("RAM Usage: %.2lf MB / %.2lf MB (%.2lf%%)\n", used, total, percent_used);
        
        // exit after 10 updates
        count++;
        if (count == 10) {
            printf("Exiting...\n");
            exit(0);
        }
    }
    
    return 0;
}