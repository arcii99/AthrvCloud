//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

#define PROG_NAME "cryptic_cpuusage"
#define SAMPLE_INTERVAL 1
#define MAX_SAMPLES 1000

void signal_handler(int sig);

int main()
{
    int sample_count;
    long long int sample_time[MAX_SAMPLES];
    long long int sample_idle[MAX_SAMPLES];
    long long int sample_total[MAX_SAMPLES];
    long long int delta_time, delta_total, delta_idle, usage;
    double cpu_usage;
    char cpu_info[100];
    char cpu_type[20];
    char cpu_speed[20];
    int fd, num_cpus;

    signal(SIGINT, signal_handler);

    printf("Starting %s...\n", PROG_NAME);

    // Read CPU information from /proc/cpuinfo
    fd = open("/proc/cpuinfo", O_RDONLY);
    if (fd < 0)
    {
        printf("Error: Unable to open /proc/cpuinfo\n");
        return 1;
    }
    num_cpus = 0;
    memset(cpu_speed, 0, sizeof(cpu_speed));
    memset(cpu_type, 0, sizeof(cpu_type));
    while (read(fd, cpu_info, sizeof(cpu_info)))
    {
        if (strncmp(cpu_info, "cpu MHz", 7) == 0)
        {
            sscanf(cpu_info+10, "%s", cpu_speed);
        }
        else if (strncmp(cpu_info, "model name", 10) == 0)
        {
            sscanf(cpu_info+13, "%[^\n]", cpu_type);
            num_cpus++;
        }
    }
    close(fd);

    if (num_cpus > 1)
    {
        printf("Detected %d CPUs\n", num_cpus);
    }
    printf("CPU Type: %s\n", cpu_type);
    printf("CPU Speed: %s MHz\n", cpu_speed);

    // Begin tracking CPU usage samples
    sample_count = 0;
    while (sample_count < MAX_SAMPLES)
    {
        fd = open("/proc/stat", O_RDONLY);
        if (fd < 0)
        {
            printf("Error: Unable to open /proc/stat\n");
            return 1;
        }

        memset(cpu_info, 0, sizeof(cpu_info));
        read(fd, cpu_info, sizeof(cpu_info));
        close(fd);

        sscanf(cpu_info, "cpu %lld %lld %lld %lld", &sample_time[sample_count], &sample_idle[sample_count], &sample_time[sample_count], &sample_total[sample_count]);
        delta_time = sample_time[sample_count] - sample_time[(sample_count > 0) ? (sample_count - 1) : 0];
        delta_idle = sample_idle[sample_count] - sample_idle[(sample_count > 0) ? (sample_count - 1) : 0];
        delta_total = sample_total[sample_count] - sample_total[(sample_count > 0) ? (sample_count - 1) : 0];

        usage = 100 * (delta_total - delta_idle) / delta_total;
        cpu_usage = usage / (double)num_cpus;

        printf("CPU Usage: %.2f%%\n", cpu_usage);

        sample_count++;
        sleep(SAMPLE_INTERVAL);
    }

    printf("Exiting %s...\n", PROG_NAME);
    return 0;
}

void signal_handler(int sig)
{
    printf("\nStopping %s...\n", PROG_NAME);
    exit(0);
}