//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    long double idle, cpu_time_prev = 0, cpu_time_all_prev = 0;
    FILE *fp;
    char buf[128];
    time_t start, end;
    double cpu_usage;
    time(&start);

    while(1) {
        fp = fopen("/proc/stat", "r");
        fgets(buf, sizeof(buf), fp);
        fclose(fp);

        sscanf(buf, "cpu  %Lf %*Lf %*Lf %*Lf %*Lf %*Lf %*Lf", &idle);

        fp = fopen("/proc/uptime", "r");
        fgets(buf, sizeof(buf), fp);
        fclose(fp);

        double now = atof(buf);
        
        if(cpu_time_prev != 0 && cpu_time_all_prev != 0) {
            cpu_usage = 100 - (idle - cpu_time_prev) / (now - cpu_time_all_prev) * 100;
            printf("CPU Usage: %f%%\n", cpu_usage);
        }

        cpu_time_prev = idle;
        cpu_time_all_prev = now;

        usleep(500000);
        time(&end);

        if(difftime(end, start) >= 120) {
            printf("Program has run for 2 minutes. CPU Monitor quitting.\n");
            break;
        }
    }

    return 0;
}