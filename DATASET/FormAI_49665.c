//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

volatile int flag = 0;

void handler(int signum) {
    flag = 1;
}

int main() {
    struct sigaction sa;
    sa.sa_handler = &handler;
    sigfillset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);

    struct itimerval it;
    it.it_value.tv_sec = 0;
    it.it_value.tv_usec = 500000; // timer interval set to 500 ms
    it.it_interval.tv_sec = 0;
    it.it_interval.tv_usec = 500000;
    setitimer(ITIMER_REAL, &it, NULL);

    float cpu_usage = 0;
    long prev_total = 0, prev_idle = 0;
    FILE* fp = fopen("/proc/stat", "r");

    if (fp == NULL) {
        printf("Unable to open file!");
        return 1;
    }

    while (1) {
        if (flag) {
            long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
            long total = 0;

            fseek(fp, 0, SEEK_SET);
            fscanf(fp, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
            total = user + nice + system + idle + iowait + irq + softirq + steal;
            if (prev_total != 0) {
                float diff_idle = idle - prev_idle;
                float diff_total = total - prev_total;
                float diff_usage = (1000 * (diff_total - diff_idle) / diff_total + 5) / 10;
                cpu_usage = (cpu_usage + diff_usage) / 2;
            }
            prev_idle = idle;
            prev_total = total;
            flag = 0;
        }
        printf("CPU usage: %3.2f%%\r", cpu_usage);
        fflush(stdout);
        usleep(1000);
    }

    fclose(fp);
    return 0;
}