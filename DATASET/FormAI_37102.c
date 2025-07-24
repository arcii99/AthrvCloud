//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: high level of detail
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    int prev_cpu_time = 0;
    int curr_cpu_time = 0;

    while(1) {
        int pid = getpid(); // get process id
        int total_cpu_time = 0;
        getrusage(RUSAGE_SELF, &usage);
        total_cpu_time = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
        // calculate total CPU time used in seconds
        curr_cpu_time = total_cpu_time - prev_cpu_time;
        prev_cpu_time = total_cpu_time; // save current value for next iteration
        
        printf("Process ID: %d | CPU Usage: %d seconds\n", pid, curr_cpu_time);
        sleep(1); // wait for 1 second
    }
    return 0;
}