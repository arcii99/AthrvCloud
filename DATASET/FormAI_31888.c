//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

#define INTERVAL 1 // Interval for updating CPU usage (in seconds)

long double get_cpu_usage(){
    FILE* fp;
    char buffer[1024];
    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    unsigned long long total_time, total_idle_time;
    long double cpu_usage;

    fp = fopen("/proc/stat", "r");
    if(!fp){
        printf("Error opening /proc/stat file\n");
        exit(1);
    }

    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    total_time = user + nice + system + idle + iowait + irq + softirq + steal;
    total_idle_time = idle + iowait;
    cpu_usage = (total_time - total_idle_time)*100.0/total_time;

    fclose(fp);

    return cpu_usage;
}

int main(){
    long double usage = 0.0;
    time_t now;

    printf("\nCPU Usage Monitor:\n\n");

    while(1){
        usage = get_cpu_usage();
        now = time(NULL);
        printf("Usage: %.2Lf%%\t\tTime: %s\n", usage, ctime(&now));
        sleep(INTERVAL);
    }

    return 0;
}