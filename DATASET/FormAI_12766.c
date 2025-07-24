//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    double total_time = 0;
    double user_time = 0;
    double system_time = 0;
    double idle_time = 0;

    clock_t start_time = clock();
    clock_t prev_total_time = start_time;
    clock_t prev_idle_time = start_time;

    while(1) {
        FILE* proc_stat = fopen("/proc/stat", "r");
        if (proc_stat == NULL) {
            printf("Error: cannot open /proc/stat\n");
            exit(1);
        }

        char line[256];
        fgets(line, sizeof(line), proc_stat);
        fclose(proc_stat);

        if (line[0] != 'c') { // look for cpu line
            continue;
        }
        
        sscanf(line, "cpu %lf %lf %lf %lf", &user_time, &system_time, &idle_time, &total_time);
        double delta_total_time = total_time - prev_total_time;
        double delta_idle_time = idle_time - prev_idle_time;
        double usage = (delta_total_time - delta_idle_time) / delta_total_time * 100.0;

        printf("CPU Usage: %.2f%%\n", usage);

        prev_total_time = total_time;
        prev_idle_time = idle_time;

        sleep(1);
    }
    return 0;
}