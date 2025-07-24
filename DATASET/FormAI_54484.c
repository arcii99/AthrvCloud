//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

int main() {
    int interval = 1;
    int num_samples = 10;
    double total_cpu_usage = 0;
    int count = 0;
    struct timeval start, end;    

    while(count < num_samples) {
        gettimeofday(&start, NULL);

        char* cmd = "ps -A -o %cpu | awk '{s+=$1} END {print s}'";
        FILE* fp = popen(cmd, "r");

        char result[10];
        fread(result, 1, 10, fp);
        double cpu_usage = atof(result);

        pclose(fp);

        total_cpu_usage += cpu_usage;
        count++;

        gettimeofday(&end, NULL);
        double elapsed_time = (end.tv_sec - start.tv_sec) + 
            (end.tv_usec - start.tv_usec) * 1e-6;
        sleep(interval - elapsed_time);
    }

    double avg_cpu_usage = total_cpu_usage / num_samples;
    printf("Average CPU Usage: %f\n", avg_cpu_usage);

    return 0;
}