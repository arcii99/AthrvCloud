//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/times.h>

int main(int argc, char* argv[]) {
    // Set the time interval to 1 second
    int interval = 1;

    // Check for user-provided interval
    if(argc > 1) {
        interval = atoi(argv[1]);
    }

    while(1) {
        // Get the CPU usage info
        struct tms buf;
        clock_t start = times(&buf);
        sleep(interval);
        clock_t end = times(&buf);

        // Calculate the CPU usage percentage
        double total_time = (double)(end-start)/sysconf(_SC_CLK_TCK);
        double usage_percentage = (buf.tms_utime+buf.tms_stime)/total_time * 100.0;
        
        // Print the usage percentage
        printf("CPU Usage: %.2f%%\n", usage_percentage);
    }

    return 0;
}