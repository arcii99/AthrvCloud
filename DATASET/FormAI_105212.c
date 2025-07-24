//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cpu_usage_monitor() {
    float cpu_usage = 0;
    FILE *fp;
    char buffer[8192];
    size_t bytes_read;
    char *search_string = "cpu ";
    char *line;
    long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    long prev_idle = 0, prev_total = 0;

    while (1) {
        fp = fopen("/proc/stat", "r");
        if (!fp) {
            perror("Could not open stat");
        }
        bytes_read = fread(buffer, 1, sizeof(buffer), fp);
        fclose(fp);
        if (bytes_read == 0 || bytes_read == sizeof(buffer)) {
            perror("Error reading stat");
        }
        buffer[bytes_read] = '\0';
        line = strstr(buffer, search_string);
        sscanf(line, "%*s %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
               &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
        long total = user + nice + system + idle + iowait + irq + softirq + steal;
        if (prev_idle != 0 && prev_total != 0) {
            long diff_idle = idle - prev_idle;
            long diff_total = total - prev_total;
            cpu_usage = (float)(100 * (diff_total - diff_idle)) / diff_total;
            printf("CPU usage: %0.2f%%\n", cpu_usage);
        }
        prev_idle = idle;
        prev_total = total;
        sleep(1);
    }
}

int main() {
    cpu_usage_monitor();
    return 0;
}