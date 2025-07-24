//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>

int main(int argc, char *argv[]) {
    double cpu_time;
    struct tms t;
    clock_t start, end;

    start = times(&t);
    if (argc != 2) {
        printf("Usage: %s <sleep_time>\n", argv[0]);
        exit(1);
    }

    int sleep_time = atoi(argv[1]);
    printf("Running CPU usage monitor for %d seconds...\n", sleep_time);

    while (1) {
        end = times(&t);
        cpu_time = (double) (end - start) / sysconf(_SC_CLK_TCK);
        printf("CPU usage: %f %%\n", (cpu_time / sleep_time) * 100);
        sleep(1);
    }

    return 0;
}