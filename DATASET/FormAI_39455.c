//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: authentic
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <string.h>

#define SEC_TO_USEC 1000000

int main(int argc, const char** argv) {
    int pid;
    struct rusage info;
    struct timeval tv;
    double cpu_usage;
    
    if (argc < 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    pid = atoi(argv[1]);

    while(1) {
        if (getrusage(pid, &info) != 0) {
            fprintf(stderr, "Failed to get resource usage information: %s\n", strerror(errno));
        } else {
            tv = info.ru_utime;
            cpu_usage = ((double)tv.tv_sec + (double)tv.tv_usec / SEC_TO_USEC);
            printf("CPU usage of process %d: %.2f seconds.\n", pid, cpu_usage);
        }

        sleep(1);
    }

    return 0;
}