//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int cpu_total, cpu_user, cpu_nice, cpu_sys, cpu_idle, cpu_iowait, cpu_irq, cpu_softirq;
    int cpu_total_old, cpu_user_old, cpu_nice_old, cpu_sys_old, cpu_idle_old, cpu_iowait_old, cpu_irq_old, cpu_softirq_old;
    float cpu_usage;
    FILE *fp;
 
    while(1) {
        fp = fopen("/proc/stat", "r");   // open the stat file
        fscanf(fp, "cpu %d %d %d %d %d %d %d %d", &cpu_user, &cpu_nice, &cpu_sys, &cpu_idle, &cpu_iowait, &cpu_irq, &cpu_softirq, &cpu_total);
        fclose(fp);   // close the file
 
        cpu_total_old = cpu_user_old + cpu_nice_old + cpu_sys_old + cpu_idle_old + cpu_iowait_old + cpu_irq_old + cpu_softirq_old;
        cpu_user_old = cpu_user;
        cpu_nice_old = cpu_nice;
        cpu_sys_old = cpu_sys;
        cpu_idle_old = cpu_idle;
        cpu_iowait_old = cpu_iowait;
        cpu_irq_old = cpu_irq;
        cpu_softirq_old = cpu_softirq;
        cpu_total = cpu_user + cpu_nice + cpu_sys + cpu_idle + cpu_iowait + cpu_irq + cpu_softirq;
        int cpu_usage = (cpu_total - cpu_total_old - cpu_idle + cpu_idle_old) / (cpu_total - cpu_total_old) * 100;
 
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        sleep(1);   // sleep for 1 second
    }
 
    return 0;
}