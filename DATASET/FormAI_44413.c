//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int time_interval = 1; // in seconds
    if (argc > 1) {
        time_interval = atoi(argv[1]);
    }
    while (1) {
        FILE *fp;
        char buffer[1024];
        double idle_time, total_time;
        fp = fopen("/proc/stat", "r");
        fgets(buffer, sizeof(buffer), fp);
        fclose(fp);
        char *tok = strtok(buffer, " ");
        // parsing the idle and total CPU time
        for (int i = 0; i < 5; i++) {
            tok = strtok(NULL, " ");
        }
        idle_time = atof(tok);
        for (int i = 0; i < 3; i++) {
            tok = strtok(NULL, " ");
            total_time += atof(tok);
        }
        double cpu_usage = 100.0 - ((idle_time * 100.0) / total_time);
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        sleep(time_interval);
    }
    return 0;
}