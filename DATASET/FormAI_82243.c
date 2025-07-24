//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    float max_cpu_usage = 100.0;
    int update_time = 1;

    printf("CPU Usage Monitor\n");
    while(1){
        FILE* fp;
        char buff[1024];
        float cpu_usage;

        fp = fopen("/proc/stat", "r");
        fgets(buff, sizeof(buff), fp);
        fclose(fp);
        
        int user, nice, system, idle, iowait, irq, softirq, steal;
        sscanf(buff, "cpu  %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
        
        sleep(update_time);
        fp = fopen("/proc/stat", "r");
        fgets(buff, sizeof(buff), fp);
        fclose(fp);

        int user1, nice1, system1, idle1, iowait1, irq1, softirq1, steal1;
        sscanf(buff, "cpu  %d %d %d %d %d %d %d %d", &user1, &nice1, &system1, &idle1, &iowait1, &irq1, &softirq1, &steal1);

        int totald = user1 + nice1 + system1 + idle1 + iowait1 + irq1 + softirq1 + steal1 - (user + nice + system + idle + iowait + irq + softirq + steal);
        int idled = idle1 - idle;

        cpu_usage = 100.0 * (1 - (float)idled / (float)totald);

        if(cpu_usage > max_cpu_usage){
            printf("CPU usage exceeded maximum limit of %f%%. CPU usage at %f%%\n", max_cpu_usage, cpu_usage);
            exit(0);
        }

        printf("CPU usage: %f%%\n", cpu_usage);
    }
    return 0;
}