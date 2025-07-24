//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CPU_STAT_PATH "/proc/stat"
#define CPU_INFO_PATH "/proc/cpuinfo"

typedef struct {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
} cpu_usage_t;

int read_cpu_info(char *vendor_id, char *model_name)
{
    int fd, len;
    char buffer[1024] = {0}, *p;
    fd = open(CPU_INFO_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open /proc/cpuinfo");
        return -1;
    }
    len = read(fd, buffer, sizeof(buffer));
    if (len <= 0) {
        perror("Failed to read /proc/cpuinfo");
        close(fd);
        return -1;
    }
    close(fd);
    p = strstr(buffer, "vendor_id");
    if (p != NULL) {
        sscanf(p, "%*s%*s%s", vendor_id);
    }
    p = strstr(buffer, "model name");
    if (p != NULL) {
        sscanf(p, "%*s%*s%*s%*s%*s%*[ ]%[^\n]", model_name);
    }
    return 0;
}

int read_cpu_usage(cpu_usage_t *cpu_usage)
{
    int fd, len;
    char buffer[1024] = {0};
    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    fd = open(CPU_STAT_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open /proc/stat");
        return -1;
    }
    len = read(fd, buffer, sizeof(buffer));
    if (len <= 0) {
        perror("Failed to read /proc/stat");
        close(fd);
        return -1;
    }
    close(fd);
    sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    cpu_usage->user = user;
    cpu_usage->nice = nice;
    cpu_usage->system = system;
    cpu_usage->idle = idle;
    return 0;
}

void print_cpu_usage(cpu_usage_t *prev_cpu_usage, cpu_usage_t *curr_cpu_usage)
{
    unsigned long long prev_total, curr_total, prev_idle, curr_idle;
    double cpu_usage;
    prev_total = prev_cpu_usage->user + prev_cpu_usage->nice + prev_cpu_usage->system + prev_cpu_usage->idle;
    curr_total = curr_cpu_usage->user + curr_cpu_usage->nice + curr_cpu_usage->system + curr_cpu_usage->idle;
    prev_idle = prev_cpu_usage->idle;
    curr_idle = curr_cpu_usage->idle;
    cpu_usage = (double)(curr_total - prev_total - (curr_idle - prev_idle)) * 100.0 / (double)(curr_total - prev_total);
    printf("CPU Usage: %.2lf%%\n", cpu_usage);
}

int main()
{
    char vendor_id[256] = {0}, model_name[256] = {0};
    cpu_usage_t prev_cpu_usage, curr_cpu_usage;
    memset(&prev_cpu_usage, 0, sizeof(prev_cpu_usage));
    memset(&curr_cpu_usage, 0, sizeof(curr_cpu_usage));
    read_cpu_info(vendor_id, model_name);
    printf("CPU Vendor: %s\n", vendor_id);
    printf("CPU Model: %s\n", model_name);
    while (1) {
        read_cpu_usage(&curr_cpu_usage);
        print_cpu_usage(&prev_cpu_usage, &curr_cpu_usage);
        prev_cpu_usage = curr_cpu_usage;
        sleep(1);
    }
    return 0;
}