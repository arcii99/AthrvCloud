//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: scalable
#include <stdio.h>
#include <sys/times.h>
#include <unistd.h>

int main() {
    int cpuTickRate = sysconf(_SC_CLK_TCK); // get the CPU tick rate
    struct tms t1, t2;
    clock_t c1, c2;
    int cpuUsage;
    
    c1 = times(&t1); // get the start time
    sleep(2); // wait for a while
    c2 = times(&t2); // get the end time
    
    // calculate the CPU usage
    cpuUsage = (int)((t2.tms_utime+t2.tms_stime-t1.tms_utime-t1.tms_stime) * 100 / (double)(c2-c1));
    
    printf("CPU usage: %d%%\n", cpuUsage);
    
    return 0;
}