//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: optimized
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    double lastTime, lastCPU, currTime, currCPU, CPU, totalTime = 0;
    
    getrusage(RUSAGE_SELF, &usage);
    lastTime = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000.0;
    lastCPU = usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000.0;
    
    printf("Monitor started.\n");
    
    for (int i = 0; i < 10; i++) {
        usleep(100000); // sleep for 100 ms
        getrusage(RUSAGE_SELF, &usage);
        currTime = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000.0;
        currCPU = usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000.0;
        CPU = (currCPU - lastCPU) / (currTime - lastTime) * 100;
        lastTime = currTime;
        lastCPU = currCPU;
        totalTime += currTime - lastTime;
        printf("CPU Usage: %.2f%%\n", CPU);
    }
    
    printf("Monitor stopped.\n");
    printf("Total time elapsed: %.2f seconds.\n", totalTime);
    
    return 0;
}