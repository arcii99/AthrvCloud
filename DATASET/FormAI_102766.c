//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: intelligent
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    printf("Starting CPU usage monitor...\n\n");
    printf("Current PID: %d\n", getpid());
    printf("Current process priority: %d\n", getpriority(PRIO_PROCESS, 0));
    
    long double prev_idle_time = 0, prev_total_time = 0;
    while(1) {
        FILE* statFile = fopen("/proc/stat", "r");
        if(statFile == NULL) {
            printf("Error opening /proc/stat file.\n");
            continue;
        }
        
        char buf[1024];
        fgets(buf, sizeof(buf), statFile);
        fclose(statFile);
        
        unsigned long long user_time, nice_time, sys_time, idle_time, io_wait_time, irq_time, soft_irq_time, steal_time;
        sscanf(buf, "cpu %llu %llu %llu %llu %llu %llu %llu %llu", &user_time, &nice_time, &sys_time, &idle_time, &io_wait_time, &irq_time, &soft_irq_time, &steal_time);
        
        long double total_time = user_time + nice_time + sys_time + idle_time + io_wait_time + irq_time + soft_irq_time + steal_time;
        long double diff_idle_time = idle_time - prev_idle_time;
        long double diff_total_time = total_time - prev_total_time;
        long double usage = (1000.0 * (diff_total_time - diff_idle_time) / diff_total_time + 5) / 10;
        
        printf("CPU Usage: %Lf %%\n", usage);
        
        prev_idle_time = idle_time;
        prev_total_time = total_time;
        
        sleep(1);
    }
    
    return 0;
}