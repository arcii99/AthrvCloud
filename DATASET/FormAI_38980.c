//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define INTERVAL 1 // Time interval for checking memory usage (in seconds)

void printHeader() {
    printf("%-10s%-10s\n", "PID", "Memory Usage");
}

void printUsage(int pid, long usage) {
    printf("%-10d%-10ld\n", pid, usage);
}

int main() {
    char input[10];
    printf("Enter PID (Enter 0 to exit): ");
    fgets(input, 10, stdin);
    int pid = atoi(input);
    if (pid == 0) {
        return 0;
    }
    
    // Set memory limit to max value
    struct rlimit limit;
    limit.rlim_cur = RLIM_INFINITY;
    limit.rlim_max = RLIM_INFINITY;
    if (setrlimit(RLIMIT_DATA, &limit) != 0) {
        perror("Error setting memory limit");
        return 1;
    }
    
    printHeader();
    while (1) {
        char cmd[100];
        sprintf(cmd, "grep VmRSS /proc/%d/status | awk '{print $2}'", pid);
        FILE* fp = popen(cmd, "r");
        if (fp == NULL) {
            perror("Error getting memory usage");
            return 1;
        }
        char output[100];
        fgets(output, 100, fp);
        long usage = atol(output);
        printUsage(pid, usage);
        pclose(fp);
        sleep(INTERVAL);
    }
    
    return 0;
}