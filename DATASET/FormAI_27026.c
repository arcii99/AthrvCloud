//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int cpu_percentage;
    char buf[128];

    while(1) {
        FILE* file = fopen("/proc/stat", "r");
        long long int user_time1=0,nice_time1=0,sys_time1=0,idle_time1=0,iowait_time1=0,irq_time1=0,softirq_time1=0;


        if (fgets(buf, sizeof(buf), file)) {
            sscanf(buf+5, "%lld %lld %lld %lld %lld %lld %lld",
                      &user_time1, &nice_time1, &sys_time1, &idle_time1,
                      &iowait_time1, &irq_time1, &softirq_time1);
        }

        fclose(file);

        usleep(1000000); 

        file = fopen("/proc/stat", "r");
        long long int user_time2=0, nice_time2=0, sys_time2=0, idle_time2=0, iowait_time2=0, irq_time2=0, softirq_time2=0;
        
        if (fgets(buf, sizeof(buf), file)) {
            sscanf(buf+5, "%lld %lld %lld %lld %lld %lld %lld",
                      &user_time2, &nice_time2, &sys_time2, &idle_time2,
                      &iowait_time2, &irq_time2, &softirq_time2);
        }

        fclose(file);
        long long int total_time = (user_time2 + nice_time2 + sys_time2 + idle_time2 + iowait_time2 + irq_time2 + softirq_time2) - 
                                    (user_time1 + nice_time1 + sys_time1 + idle_time1 + iowait_time1 + irq_time1 + softirq_time1);

        cpu_percentage = (((total_time-(idle_time2-idle_time1))*100)/total_time);

        printf("CPU USAGE: %d%%\n", cpu_percentage);
    }
    return 0;
}