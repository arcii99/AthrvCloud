//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>

// Function to print CPU usage in percentage
void print_cpu_usage(int previous_idle_time, int previous_total_time)
{
    FILE* fp = fopen("/proc/stat", "r");
    int idle_time, total_time;
    fscanf(fp, "cpu %d %*d %*d %d", &idle_time, &total_time);
    fclose(fp);

    int diff_idle = idle_time - previous_idle_time;
    int diff_total = total_time - previous_total_time;

    double usage_percentage = 100.0 * (1.0 - ((double)diff_idle / (double)diff_total));

    printf("CPU Usage: %.2f%%\n", usage_percentage);
}

// Signal handler for SIGALRM
void handle_signal(int signal)
{
    print_cpu_usage(0, 0);
    alarm(1);
}

int main()
{
    signal(SIGALRM, handle_signal);

    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while(1){
        sleep(1);
    }
    return 0;
}